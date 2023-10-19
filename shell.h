#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
void fun(char **argv);
char *loc_search(char *command);
char **_tokenization(char *str, char delimiter, int length);
void ptr_free(char **argv, int h);

#endif /* SHELL_H */
