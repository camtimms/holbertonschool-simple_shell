#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * split_string - Breaks the input into tokens
 *
 * Return: Array of tokens
 */

char **split_string (char *line)
{
	char *token;
	static char *args[64];
	int arg_num = 0;


	token = strtok(line, " ");
	
	while (token != NULL)
	{
		args[arg_num] = token;
		token = strtok(NULL, " ");
		arg_num++;
	}
	args[arg_num] = NULL;

	return (args);
}
