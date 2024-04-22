#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

/*macros*/
#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define PROMPT "SuperShell$ "
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

/* prompt_parse_exe.c */
void prompt(void);
char **tokenize(char *str, const char *delim);
char **tokenize_input(char *input);
int execute(char **args);

/* get.c */
char *get_input(void);
void *get_line(void);
char *_getenv(const char *name);
char *get_path(void);
char *find_in_path(char *command);

/* builtin_1.c */
int check_for_builtin(char **args);
void shell_cd(char **args);
int shell_clear(char **args);
int shell_env(void);
void shell_exit(char **args);

/* builtin_2.c */
void shell_help(void);
int shell_setenv(char **args);
int shell_unsetenv(char **args);

/* signal_handler.c */
void handle_sigint(int sig);
void handle_sigquit(int sig);
void handle_sigstp(int sig);

/* free.c */
void free_error(char **argv, char *arg);
void free_tokens(char **ptr);
void free_path(void);
void free_last_input(void);

#endif
