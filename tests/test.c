#include <stdio.h>
#include "main.h"
int main(void)
{
    char str1[] = "    bin/ls -la";
    char str2[] = "hello world";
    char str3[] = "     lots of spaces before";
    char str4[] = "nospaces";
    char str5[] = "";  /* Empty string */
    char str6[] = "       "; /* Only spaces */
    printf("Before: '%s'\n", str1);
    remove_space(str1);
    printf("After : '%s'\n\n", str1);
    printf("Before: '%s'\n", str2);
    remove_space(str2);
    printf("After : '%s'\n\n", str2);
    printf("Before: '%s'\n", str3);
    remove_space(str3);
    printf("After : '%s'\n\n", str3);
    printf("Before: '%s'\n", str4);
    remove_space(str4);
    printf("After : '%s'\n\n", str4);
    printf("Before: '%s'\n", str5);
    remove_space(str5);
    printf("After : '%s'\n\n", str5);
    printf("Before: '%s'\n", str6);
    remove_space(str6);
    printf("After : '%s'\n\n", str6);
    return 0;
}
