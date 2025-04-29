#include "main.h"

/**
 * main - Super Simple Shell
 *
 * Description: Super Simple Shell that can run commands with their full path,
 * without any argument.
 *
 * Return: Success (0) or Failure (-1)
 */

int main (void)
{
	char *line =  NULL;
	size_t len = 0;
	int num_char = 0;
	pid_t child_pid;
	int status;
	char *argv[2];

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		num_char = getline(&line, &len, stdin);
		if (num_char == -1)
			break;

		if (line[num_char - 1] == '\n')
			line[num_char - 1] = '\0';

		line = remove_space(line);
		if (line == NULL || line[0] == '\0')
			continue;

		argv[0] = line;
		argv[1] = NULL;

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork failed");
			free(line);
			return (-1); 
		}
		if (child_pid == 0)
		{
			if (execve(line, argv, NULL) == -1)
			{
				perror("execve failed");
				return (-1);
			}
		}
		else
			wait(&status);
	}
	
	free (line);
	return (0);
}
