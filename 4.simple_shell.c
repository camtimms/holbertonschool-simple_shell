#include "main.h"

/**
 * main - Super Simple Shell
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

		num_char = getline(&line, &len, stdin);
		if (num_char == -1)
			break;

		if (line[num_char - 1] == '\n')
			line[num_char - 1] = '\0';

		argv = line_to_arr(line);
		if (argv == NULL)
		{
			free_arr(argv);
			continue;
		}

		command_path = get_path(argv[0]);
		if (command_path == NULL)
		{
			free_arr(argv);
			free(line);
			continue;
		}
		
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork failed");
			free(line);
			return (-1);
		}
		if (child_pid == 0)
		{
			if (execve(command_path, argv, NULL) == -1)
			{
				perror("execve failed");
				return (EXIT_FAILURE);
			}
			free_arr(argv);
		}
		else
		{
			wait(&status);
			free_arr(argv);
		}
	}

	free(line);
	return (0);
}
