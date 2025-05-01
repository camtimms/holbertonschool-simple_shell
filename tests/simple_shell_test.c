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
			break;
		
		/* removed newline from line */
		if (line[num_char - 1] == '\n')
			line[num_char - 1] = '\0';
		
		/* convert line to array */
		argv = line_to_arr(line);
		printf("address of line: %p\n", line);
		free(line);
		if (argv == NULL)
		{
			free(argv);
			continue;
		}
		
		/* get file path for the command */
		command_path = get_path(argv[0]);
		printf("after command path: %s\n", command_path);
		if (command_path == NULL)
		{
			free_arr(argv);
			free(command_path);
			printf("command path == NULL\n");
			continue;
		}
		
		/* fork process */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork failed");
			free(command_path);
			printf("fork failed\n");
			return (-1);
		}
		if (child_pid == 0)
		{
			printf("forking here\n");
			if (execve(command_path, argv, NULL) == -1)
			{
				perror("execve failed");
				return(-1);
			}
			printf("this should not run");
		}
		else
		{
			printf("waiting for child &status\n");
			wait(&status);	
			printf("after child &status\n");
			free(command_path);
			free(argv);
			printf("after everything freeed\n");
		}
	}

	return (0);
}
