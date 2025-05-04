#include "main.h"

/**
 * custom_command - Handles the built in commands for the shell
 *
 * @arr_arg: Array of arguments from stdin
 * @exit_status: Pointer to the exit_status variable
 *
 * Description: Handles the checks for the built in commands like exit and env
 *
 * Return: 1 to skip execution, 0 no custom command, -1 exits the shell
 */

int custom_command(char **arr_arg, int *exit_status)
{
	int i = 0;

	/* Check if user entered empty command */
	if (arr_arg[0] == NULL)
		return (1);

	/* Check for exit command */
	if (strcmp(arr_arg[0], "exit") == 0)
	{
		*exit_status = 0;
		return (-1);
	}

	/* Check for env command */
	if (strcmp(arr_arg[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
		*exit_status = 0;
		return (1);
	}

	return (0);
}

/**
 * execute_command - Handles the command execution with fork + execve
 *
 * @arr_arg: Array of arguments from stdin
 * @command_path: Path to the command
 * @exit_status Pointer to the exit_status variable
 *
 * Description: Executes the command given by command path in a child process
 *
 * Return: void
 */

void execute_command(char **arr_arg, char *command_path, int *exit_status)
{
	pid_t child_pid;
	int child_status;

	/* Fork process */
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failed");
		free(command_path);
		free_arr(arr_arg);
		exit(-1);
	}
	if (child_pid == 0)
	{
		if (execve(command_path, arr_arg, NULL) == -1)
		{
			perror("execve failed");
			_exit(1);
		}
	}
	else
	{
		wait(&child_status);
		if (WIFEXITED(child_status))
			*exit_status = WEXITSTATUS(child_status);
	}
}

/**
 * main - Simple Shell
 *
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Description: Super Simple Shell that can run commands with their full path,
 * without any argument.
 *
 * Return: Success (0) or Failure (-1)
 */

int main(int argc, char **argv)
{
	char *line =  NULL, *command_path;
	char **arr_arg = NULL;
	int num_char = 0, line_count = 1, exit_status = 0;
	size_t len = 0;
	int cmd_status;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		/* Pull line from stdin */
		num_char = getline(&line, &len, stdin);
		if (num_char == -1)
			break;

		/* Removed newline char from line */
		if (line[num_char - 1] == '\n')
			line[num_char - 1] = '\0';

		/* Convert line to array */
		arr_arg = line_to_arr(line);
		if (arr_arg == NULL)
		{
			line_count++;
			continue;
		}

		/*Check for custom command */
		cmd_status = custom_command(arr_arg, &exit_status);
		if (cmd_status == -1)
		{
			free_arr(arr_arg);
			break;
		}
		if (cmd_status == 1)
		{
			free_arr(arr_arg);
			line_count++;
			continue;
		}

		/* Get file path for the command */
		command_path = get_path(arr_arg[0]);
		if (command_path == NULL)
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
				argv[0], line_count, arr_arg[0]);
			exit_status = 127;
			free_arr(arr_arg);
			line_count++;
			continue;
		}

		/* Fork process */
		execute_command(arr_arg, command_path, &exit_status);

		/* Free memory for next command */
		free(command_path);
		free_arr(arr_arg);
		line_count++;
	}

	free(line);
	return (exit_status);
}
