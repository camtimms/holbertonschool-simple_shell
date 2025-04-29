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
	int i = 0;
	char *token = malloc(64);

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		num_char = getline(&line, &len, stdin);
		if (num_char == -1)
			break;

		if (line[num_char - 1] == '\n')
			line[num_char - 1] = '\0';
		
		token = strtok(line, " ");
		i = 0;
		while (token != NULL)
		{
			argv[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		free(token);

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork failed");
			free(line);
			return (-1); 
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
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
