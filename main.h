#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

char *remove_space(char *);
char *remove_traling_spaces(char *);
char **line_to_arr(char *);
char *get_path(char *);

#endif
