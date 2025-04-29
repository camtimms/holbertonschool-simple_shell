#include "main.h"

/**
 * main - Entry point to test line_to_arr function
 *
 * Return: 0 on success, 1 on failure
 */
int main(void)
{
    char input[] = "This version handles any number of words safely";
    char **words = line_to_arr(input);
    int i = 0;

    if (words == NULL)
    {
        fprintf(stderr, "Tokenization failed\n");
        return (1);
    }

    for (i = 0; words[i] != NULL; i++)
    {
        printf("Word[%d]: %s\n", i, words[i]);
    }

    free(words);

    return (0);
}

