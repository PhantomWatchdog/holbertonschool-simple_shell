#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int ac, char **argv);
char **strtok_custom(char *str, const char *delim);
void execshell(char **argv);
#endif
