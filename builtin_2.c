#include "shell.h"

/**
 * shell_help - displays help information for built-in commands
 */

void shell_help(void)
{
	puts("\nShell Version 1.0.0\n\n");
	puts("Usage: ./hsh\n\n");
	puts("Shell built-in commands:\n\n");
	puts("help\t\tDisplay this help information\n\n");
	puts("cd [dir]\tChange the current working directory\n\n");
	puts("env\t\tDisplay the environment variables\n\n");
	puts("setenv\t\tSet an environment variable\n\n");
	puts("unsetenv\tUnset an environment variable\n\n");
	puts("exit\t\tExit the shell\n\n");
}

/**
 * shell_setenv - Set the value of an environment variable
 * @args: Arguments (name and value of the environment variable)
 *
 * Return: Nothing
 */

int shell_setenv(char **args)
{
	char *name, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		perror("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	name = args[1];
	value = args[2];

	if (setenv(name, value, 1) != 0)
	{
		perror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * shell_unsetenv - Unset an environment variable
 * @args: Arguments (name of the environment variable)
 *
 * Return: Nothing
 */

int shell_unsetenv(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		perror("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		perror("unsetenv");
	}
	return (0);
}
