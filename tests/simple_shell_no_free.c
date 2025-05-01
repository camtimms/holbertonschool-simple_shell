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
		if (argv == NULL)
		{
			continue;
		}
		
		/* get file path for the command */
		command_path = get_path(argv[0]);
		if (command_path == NULL)
		{
			continue;
		}
		
		/* fork process */
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork failed");
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

	}

	return (0);
}
