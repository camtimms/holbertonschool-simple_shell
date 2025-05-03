#include "main.h"

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
