#include "shell.h"

/**
 * shell_help - displays help information for built-in commands
 */
void shell_help(void)
{
        _puts("\nShell Version 1.0.0\n\n");
        _puts("Usage: ./hsh\n\n");
        _puts("Shell built-in commands:\n\n");
        _puts("help\t\tDisplay this help information\n\n");
        _puts("cd [dir]\tChange the current working directory\n\n");
        _puts("env\t\tDisplay the environment variables\n\n");
        _puts("setenv\t\tSet an environment variable\n\n");
        _puts("unsetenv\tUnset an environment variable\n\n");
        _puts("exit\t\tExit the shell\n\n");
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
                _puterror("Usage: setenv VARIABLE VALUE\n");
                return (-1);
        }

        name = args[1];
        value = args[2];

        if (setenv(name, value, 1) != 0)
        {
                _puterror("setenv");
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
                _puterror("Usage: unsetenv VARIABLE\n");
                return (-1);
        }

        name = args[1];

        if (unsetenv(name) != 0)
        {
                _puterror("unsetenv");
        }
        return (0);
}
