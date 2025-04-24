#include <stdio.h>
#include <string.h>

char **split_string(char *line);

int main(void) 
{
    char input[] = "hello there general kenobi";
    char **words = split_string(input);

    for (int i = 0; words[i] != NULL; i++) 
    {
        printf("Word[%d]: %s\n", i, words[i]);
    }

    return (0);
}

