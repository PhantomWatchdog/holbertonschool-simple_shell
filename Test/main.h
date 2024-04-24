#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>


void prompt(void);
int execute_cmd(char *usr_input);
char *_getinput(void);

void shell_exit(char **args);
int check_for_builtin(char **args);
#endif
