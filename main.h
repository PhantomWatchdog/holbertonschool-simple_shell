#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

void read_command(char *buffer, ssize_t *read_result);
void execute_command(char *buffer);


#endif

