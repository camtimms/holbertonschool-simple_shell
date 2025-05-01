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
	char *line_dup;
	char **arr = malloc(arr_size * sizeof(char *));
	char **temp;

	if (arr == NULL)
	{
		perror("malloc failed");
		return (NULL);
	}

	line_dup = strdup(line);
	if (line_dup == NULL)
	{
		perror("line_dup failed");
		return (NULL);
	}
	
	token = strtok(line_dup, " ");
	
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

	free(line_dup);
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
 * free_str - Frees duplicate strings
 *
 * @str: String to free
 *
 * Return: void
 */

void free_str(char *str, ...)
{
	va_list args;
	char *current;

	va_start(args, str);
	current = str;

	while (current != NULL)
	{
		free(current);
		current = va_arg(args, char *);
	}

	va_end(args);
}

extern char **environ;

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
			return(environ[i] + name_len + 1);
		i++;
	}

	return(NULL);
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
	char *path, *path_dup, *path_token, *path_full;
	char *cmd_dup;
	size_t buff_size;

	/* Check for NULL input */
	if (command == NULL || command[0] == '\0')
		return (NULL);

	/* Check for slashes in command */
	if(strchr(command, '/') != NULL)
	{
		/* Check if command exists and is executable */
		if (access(command, X_OK) == 0)
		{
			cmd_dup = strdup(command);
			if (cmd_dup == NULL)
				perror("get_path: cmd_dup failed");
			return(cmd_dup);
		}
		perror("get_path: invalid path");
		return (NULL);
	}

	/* Get path string from env */
	path = _getenv("PATH");
	if (path == NULL || *path == '\0')
		return (NULL);
	path_dup = strdup(path);
	if (path_dup == NULL)
	{
		perror("get_path: path_dup failed");
		return (NULL);
	}

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
	perror("path not found");
	return (NULL);
}
