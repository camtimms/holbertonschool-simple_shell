#include "main.h"

/**
 * main - Simple Shell
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
	int i = 0;
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

		/* Removed newline char from line */
		if (line[num_char - 1] == '\n')
			line[num_char - 1] = '\0';
		
		/* Convert line to array */
		arr_arg = line_to_arr(line);
		if (arr_arg == NULL)
			continue;

		/* Check if user entered empty command */
		if (arr_arg[0] == NULL)
		{
			free_arr(arr_arg);
			continue;
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
			continue;
		}
