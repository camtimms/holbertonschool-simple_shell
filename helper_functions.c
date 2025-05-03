#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * free_arr - Frees an array created by line_to_arr
 *
 * @arr: Array to free
 *
 * Description: Frees a array of pointers
 *
 * Return: void
 */

void free_arr(char **arr)
{
	int i;

	if (arr == NULL)
		return;

	for (i = 0; arr[i] != NULL; i++)
		free(arr[i]);
	free(arr);
}

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
	int i = 0, j = 0;
	int arr_size = 2;
	int new_size;
	char *token;
	char *line_dup;
	char **arr = malloc(arr_size * sizeof(char *));
	char **new_arr;

	if (arr == NULL)
	{
		perror("line_to_arr: malloc failed");
		return (NULL);
	}

	line_dup = strdup(line);
	if (line_dup == NULL)
	{
		perror("line_to_arr: line_dup failed");
		return (NULL);
	}

	token = strtok(line_dup, " ");

	while (token != NULL)
	{
		if (i >= arr_size - 1)
		{
			new_size = arr_size * 2;
			new_arr = malloc(new_size * sizeof(char *));
			if (new_arr == NULL)
			{
				perror("line_to_arr: malloc failed");
				for (j = 0; j < i; j++)
					free(arr[j]);
				free(arr);
				free(line_dup);
				return (NULL);
			}
			memcpy(new_arr, arr, arr_size * sizeof(char *));
			free(arr);
			arr = new_arr;
			arr_size = new_size;
		}

		arr[i] = strdup(token);
		if (arr[i] == NULL)
		{
			perror("line_to_arr: strdup failed");
			for (j = 0; j < i; j++)
				free(arr[j]);
			free(arr);
			free(line_dup);
			return (NULL);
		}

		token = strtok(NULL, " ");
		i++;
	}

	free(line_dup);
	arr[i] = NULL;
	return (arr);
}

/**
 * _getenv - gets the environment variable
 *
 * @name: Name of environment variable
 *
 * Description: Passed through env until it reaches the matching variable
 *
 * Return: value of the variable
 */
char *_getenv(char *name)
{
	int i = 0;
	int name_len;

	if (name == NULL)
		return (NULL);

	name_len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, name_len) == 0)
			return (environ[i] + name_len + 1);
		i++;
	}

	return (NULL);
}

/**
* get_path - finds path from environment
*
* @command: input command
*
* Description: Tokenises the path from the env, then checks the command input
* against the paths using stat.
*
* Return: command path or NULL(fail)
*/
char *get_path(char *command)
{
	char *path, *path_dup, *path_token, *path_full;
	char *cmd_dup;
	size_t buff_size;

	/* Check for NULL input */
	if (command == NULL || command[0] == '\0')
		return (NULL);

	/* Check for slashes in command */
	if (strchr(command, '/') != NULL)
	{
		/* Check if command exists and is executable */
		if (access(command, X_OK) == 0)
		{
			cmd_dup = strdup(command);
			return (cmd_dup);
		}
		return (NULL);
	}

	/* Get path string from env */
	path = _getenv("PATH");
	if (path == NULL || *path == '\0')
		return (NULL);
	path_dup = strdup(path);
	if (path_dup == NULL)
		return (NULL);

	path_token = strtok(path_dup, ":");

	while (path_token != NULL)
	{
		/* Allocate space for the full file path */
		/* E.g: dir + / + command + \0 */
		buff_size = strlen(path_token) + 1 + strlen(command) + 1;
		path_full = malloc(buff_size);
		if (path_full == NULL)
		{
			free(path_dup);
			return (NULL);
		}
		/* Iniitalize string and form full path */
		path_full[0] = '\0';
		strcat(path_full, path_token);
		strcat(path_full, "/");
		strcat(path_full, command);

		/* Check if file exists */
		if (access(path_full, X_OK) == 0)
		{
			free(path_dup);
			return (path_full);
		}

		/* Move to next path */
		free(path_full);
		path_token = strtok(NULL, ":");

	}

	free(path_dup);
	return (NULL);
}
