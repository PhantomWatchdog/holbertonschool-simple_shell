 #include "shell.h"

/**
 * check_for_builtin - checks if the command is a builtin
 * @args: the arguments array
 *
 * Return: 1 if command is a builtin, 0 otherwise
 */

int check_for_builtin(char **args)
{
	if (!args[0])
		return (0);
	if (!strcmp(args[0], "exit"))
		shell_exit(args);
	else if (!strcmp(args[0], "env"))
		shell_env();
	else if (!strcmp(args[0], "setenv"))
		shell_setenv(args);
	else if (!strcmp(args[0], "unsetenv"))
		shell_unsetenv(args);
	else if (!strcmp(args[0], "help"))
		shell_help();
	else if (!strcmp(args[0], "cd"))
		shell_cd(args);
	else if (!strcmp(args[0], "clear"))
		shell_clear(args);
	else
		return (0);

	return (1);
}

/**
 * shell_cd - changes the current working directory of the shell
 * @args: array of arguments
 */

void shell_cd(char **args)
{
	char *dir = args[1];
	int ret;

	/* If no argument is provided, change to HOME directory */
	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			_puts("cd: No HOME directory found\n");
			return;
		}
	}

	ret = chdir(dir);
	if (ret == -1)
	{
		perror("cd");
	}
}

/**
 * shell_clear - clears the terminal screen.
 * @args: an array of arguments
 *
 * Return: 1 to continue executing,
 *         or 0 to exit.
*/

int shell_clear(char **args)
{
	(void)args; /* avoid "unsued parameter" warning */
	_puts("\033[2J\033[H");
	return (1);
}

/**
 * shell_env - Prints all the environment variables.
 *
 * Return: void.
 */

int shell_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		putchar('\n');
	}

	return (0);
}

/**
 * shell_exit - Exit the shell.
 * @args: Arguments.
 *
 * Return: Nothing.
 */

void shell_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
	}
	free_tokens(args);
	free_last_input();
	exit(status);
}
