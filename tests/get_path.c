#include "main.h"
#include <string.h>
#include <sys/stat.h>
/**
 *
 *
 *
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
			printf("path found(command): %s\n", command);
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
		printf("path token:%s\n", path_token);
		
		path_dup = strdup(path_token);
		path_search = strcat(path_dup, "/");
		path_search = strcat(path_search, command);

		printf("path search:%s\n", path_search);

		if (stat(path_search, &st) == 0)
		{
			printf("path found: %s\n", path_search);
			return(path_search);
		}
		path_token = strtok(NULL, ":");
	}
	perror("path not found - end of get_path.c");
	return (NULL);/*need to change to no path found*/
}


/*
path(strtok) = /user/bin/\0/bin/\0blah blah
command = ls

path_ptr[0] = /user/bin/
path_ptr[1] = /bin/

path_search (strcat) path_ptr[0] strcat(ls) => /user/bin/ls
*/
