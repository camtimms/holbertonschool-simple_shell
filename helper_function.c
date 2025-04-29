#include "main.h"
/**
 *
 *
 */
char *remove_space(char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;

	if(line == NULL)
		return(NULL);

	while (line[i] == ' ')
		i = i + 1;
/*     bin/ls    -la  */
	while (line[i] != '\0')
	{
		line[j] = line[i];
		i = i + 1;
		j = j + 1;
	}

	return(line);
}


