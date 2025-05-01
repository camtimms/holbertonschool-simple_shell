#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


int main(void)
{
    char *str1 = strdup("Memory");
    char *str2 = strdup("Management");
    char *str3 = strdup("Test");

    if (!str1 || !str2 || !str3)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Allocated strings:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);

    free_str(str1, str2, str3, NULL);

    printf("Strings freed successfully.\n");

    return 0;
}

