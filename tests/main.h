#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

char *remove_space(char *);
char *remove_traling_spaces(char *);
char **line_to_arr(char *);
void free_arr(char **);

#endif
