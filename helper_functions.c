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
	int i = 0;
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

		arr[i] = token;
		token = strtok(NULL, " ");
		i++;
	}

	arr[i] = NULL;
	return (arr);
}

/**
* get_path - finds path from environment
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
	char *path_search;
	struct stat st; /*empty struct*/
	char *path_dup;

	if(command[0] == '/')
	{
		/*failing path*/
		if (stat(command, &st) == 0)
		{
			/*printf("path found(command): %s\n", command);*/
			return(command);
		}
	}

	path = strdup(getenv("PATH"));
	if (path == NULL)
	{
		perror("no path input");
		return(NULL);/*no path found*/
	}

	path_token = strtok(path, ":");

	while (path_token != NULL)
	{
		/*printf("path token:%s\n", path_token);*/
		
		path_dup = strdup(path_token);
		path_search = strcat(path_dup, "/");
		path_search = strcat(path_search, command);

		/*printf("path search:%s\n", path_search);*/

		if (stat(path_search, &st) == 0)
		{
			/*printf("path found: %s\n", path_search);*/
			return(path_search);
		}
		path_token = strtok(NULL, ":");
	}
	perror("path not found - end of get_path.c");
	return (NULL);/*need to change to no path found*/
}
