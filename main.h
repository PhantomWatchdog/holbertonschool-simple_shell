#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

/*flag*/
#define length 64

void prompt(void);
int execute_cmd(char *usr_input);
char *_getinput(void);

#endif
