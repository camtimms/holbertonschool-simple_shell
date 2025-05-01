#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * line_to_arr - Converts a string/line to an array
 *
 * @line: String/line to tokenise
 *
 * Description: Tokenises each word in a string and sets them to positions in
 * an array
 *
 * Return: Array or failure (NULL)
 */

char **line_to_arr(char *line)
{
	int i = 0, j;
	int arr_size = 2; 
	char *token;
	char **arr = malloc(arr_size * sizeof(char *));
	char **temp;

	if (arr == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}

	token = strtok(line, " ");
	
	while (token != NULL)
	{
		if (i >= arr_size - 1)
		{
			arr_size *= 2;
			temp = realloc(arr, arr_size * sizeof(char *));
			if (temp == NULL)
			{
				perror("realloc failed");
				free(arr);
				return (NULL);
			}
			arr = temp;
		}

		arr[i] = strdup(token);
		if (arr[i] == NULL)
		{
			perror("strdup failed");
			for (j = 0; j < i; j++)
				free(arr[j]);
			free(arr);
			return (NULL);
		}

		token = strtok(NULL, " ");
		i++;
	}

	arr[i] = NULL;
	return (arr);
}

/**
 * free_arr - Frees an array created by line_to_arr
 *
 * Return: void
 */

void free_arr(char **argv)
{
	int i;

	if (argv == NULL)
		return;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}

/**
* get_path - finds path from environment
*
* @command: input command
*
* Description: tokenises the path from the env, 
* then checks the command input against the paths using stat
*
* Return: command path or NULL(fail)
*/
char *get_path(char *command)
{
	char *path;
	char *path_token;
	char *path_dup;
	char *path_search;
	struct stat st;

	if(command[0] == '/')
	{
		if (stat(command, &st) == 0)
		{
			return(command);
		}
	}

	path = strdup(getenv("PATH"));
	if (path == NULL)
	{
		perror("no path input");
		return(NULL);
	}

	path_token = strtok(path, ":");

	while (path_token != NULL)
	{
		path_dup = strdup(path_token);
		path_search = strcat(path_dup, "/");
		path_search = strcat(path_search, command);

		if (stat(path_search, &st) == 0)
		{
			return(path_search);
		}
		path_token = strtok(NULL, ":");
	}

	free(path_dup);
	perror("path not found");
	return (NULL);
}
