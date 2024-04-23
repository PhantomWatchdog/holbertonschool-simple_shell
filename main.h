#ifndef MAIN_H
#define MAIN_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

void prompt(void);
char *_getline(void);
int process(char **token, char **av, int path);
char **_strtok(char *line);
int main(int ac, char **av);

#endif
