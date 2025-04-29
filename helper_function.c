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
	int start = 0;
	int end = 0;
	int i = 0;

	if (line == NULL)
		return (NULL);

	/* Find first non-whitespace character */
	while (line[start] == ' ')
		start++;

	/* Find last non-whitespace character */
	end = start;
	while (line[end] != '\0')
		end++;
	end--;

	while (end > start && line[end] == ' ')
		end--;

	/* Shift charaters to the start of line */
	while (start <= end)
	{
		line[i] = line[start];
		i++;
		start++;
	}

	line[i] = '\0';

	return (line);
}
