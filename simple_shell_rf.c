#include "main.h"

int custom_command(char **arr_arg, int exit_status, char *line)
{
	int i = 0;
	int skip = 1;

	/* Check if user entered empty command */
	if (arr_arg[0] == NULL)
	{
		free_arr(arr_arg);
		skip = 1;
	}

	/* Check for exit command */
	if (strcmp(arr_arg[0], "exit") == 0)
	{
		free_arr(arr_arg);
		free(line);
		exit(exit_status);
	}

	/* Check for env command */
	if (strcmp(arr_arg[0], "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
		
		free_arr(arr_arg);
		skip = 1;
	}

	return (skip);
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
	char *line =  NULL;
	size_t len = 0;
	int num_char = 0;
	pid_t child_pid;
	int status;
	char **arr_arg = NULL;
	char *command_path;
	int line_count = 0;
	int exit_status = 0;
	int skip = 0;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		/* Pull line from stdin */
		num_char = getline(&line, &len, stdin);
		if (num_char == -1)
			break;

		line_count++;
		skip = 0;

		/* Removed newline char from line */
		if (line[num_char - 1] == '\n')
			line[num_char - 1] = '\0';

		/* Convert line to array */
		arr_arg = line_to_arr(line);
		if (arr_arg == NULL)
			continue;

		/*Check for custom command */
		skip = custom_command(arr_arg, exit_status, line);
		if (skip == 1)
			continue;

		/* Get file path for the command */
		command_path = get_path(arr_arg[0]);
		if (command_path == NULL)
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
				argv[0], line_count, arr_arg[0]);
			exit_status = 127;
			free_arr(arr_arg);
			continue;
		}

		/* Fork process */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork failed");
			free(command_path);
			free_arr(arr_arg);
			return (-1);
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
			wait(&status);
			if (WIFEXITED(status))
				exit_status = WEXITSTATUS(status);
		}

		/* Free memory for next command */
		free(command_path);
		free_arr(arr_arg);
	}

	free(line);
	return (exit_status);
}
