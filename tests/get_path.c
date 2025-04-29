#include "main.h"
/**
 *
 *
 *
 */
char *get_path(voidmoom,)
{
	char *path;
	char *path_token;

	path = strdup(getenv("PATH"));
	if (path == NULL)
	{
		return(NULL);
	}

	path_token = strtok(path, ":");
	while (path_token != NULL)
	{
		path_token = strtok(NULL, ":")
	}
	return (path_token);
}

int stat(
