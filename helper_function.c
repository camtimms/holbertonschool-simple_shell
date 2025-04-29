#include "main.h"

/**
 * remove_space - Removes leading white spaces
 *
 * @line: The string/line you want to remove whitespaces from
 *
 * Descriptions: Uses an array and two indices to reassign characters to the
 * start of a line.
 *
 * Return: String or NULL
 */
char *remove_space(char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;

	if (line == NULL)
		return (NULL);

	while (line[i] == ' ')
		i = i + 1;

	while (line[i] != '\0')
	{
		line[j] = line[i];
		i = i + 1;
		j = j + 1;
	}

	line[j] = '\0';

	return (line);
}


