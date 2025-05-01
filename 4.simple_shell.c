#include "main.h"

/**
 * main - Simple Shell
 *
 * Description: Super Simple Shell that can run commands with their full path,
 * without any argument.
 *
 * Return: Success (0) or Failure (-1)
 */

int main(void)
{
	char *line =  NULL;
	size_t len = 0;
	int num_char = 0;
	pid_t child_pid;
	int status;
	char **argv = NULL;
	char *command_path;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		
		/* Pull line from stdin */
		line = NULL;
		num_char = getline(&line, &len, stdin);
		if (num_char == -1)
		{
			free(line);
			break;
		}

		/* Removed newline char from line */
		if (line[num_char - 1] == '\n')
			line[num_char - 1] = '\0';
		
		/* Convert line to array */
		argv = line_to_arr(line);
		free(line);
		if (argv == NULL)
		{
			free_arr(argv);
			free(line);
			continue;
		}
		
		/* Get file path for the command */
		command_path = get_path(argv[0]);
		if (command_path == NULL)
		{
			free_arr(argv);
			free(command_path);
			continue;
		}
		
		/* Fork process */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork failed");
			free(command_path);
			free_arr(argv);
			return (-1);
		}
		if (child_pid == 0)
		{
			if (execve(command_path, argv, NULL) == -1)
			{
				perror("execve failed");
				return(-1);
			}
		}
		else
			wait(&status);
		
		/* Free memory for next command */
		free(command_path);
		free_arr(argv);
	}

	return (0);
}
