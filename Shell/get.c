#include "shell.h"

/**
 * _getenv - Get the value of an environment variable
 * @name: Name of the environment variable
 *
 * Return: Value of the environment variable, or NULL if it doesn't exist
 */

char *_getenv(const char *name)
{
	char **env;
	size_t name_len = strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}

	return (NULL);
}

static char *last_input;

/**
 * get_input - Read the line of input from user.
 *
 * Return: Pointer to a buffer conatining the user's input.
*/

char *get_input(void)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t nread;

	do {
		/* print shell prompt */
		prompt();

		/* get a line of input from user */
		nread = getline(&input, &input_size, stdin);

		/* check for EOF or error */
		if (nread == -1)
		{
			free(input);
			puts("\n");
			return (NULL);
		}

		/* remove trailing newline character */
		input[nread - 1] = '\0';

	} while (input[0] == '\0' || isspace(input[0]));

	/* update last_input to point to the new input */
	last_input = input;
	return (input);
}

/**
 * get_path - Returns the value of the PATH enviroment variable.
 *
 * Return: Pointer to the value of $PATH.
 */

char *get_path(void)
{
	return (_getenv("PATH"));
}

/**
 * get_line - Read input from the standard input.
 *
 * Return: The string enter by the user.
*/

void *get_line(void)
{
	static char buffer[BUFFER_SIZE];
	static int buf_pos, buf_size;
	char *input_str = NULL;
	char current_char;
	int input_len = 0;

	while (1)
	{
		if (buf_pos >= buf_size)
		{
			buf_size = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			buf_pos = 0;
			if (buf_size == 0)
				return (input_str);
			else if (buf_size < 0)
			{
				perror("read");
				return (NULL);
			}
		}

		current_char = buffer[buf_pos];

		buf_pos++;

		if (current_char == '\n')
		{
			input_str = realloc(input_str, input_len + 1);
			input_str[input_len] = '\0';
			return (input_str);
		}
		else
		{
			input_str = realloc(input_str, input_len + 1);
			input_str[input_len] = current_char;
			input_len++;
		}
	}
}

/**
 * find_in_path - Looks for a command in each directory specified in the PATH
 *                environment variable
 * @command: pointer to `command` string to look for.
 *
 * Return: pointer to string containing the full path (success) if it is found,
 *         or NULL if it is not found (failure).
*/

char *find_in_path(char *command)
{
	struct stat st;
	int stat_ret, i;
	char buf[PATH_MAX_LENGTH], *path, *ret, **dir;

	path = get_path();
	if (!path)
		return (NULL);
	dir = tokenize(path, PATH_SEPARATOR);
	if (!dir)
		return (NULL);
	for (i = 0; dir[i]; i++)
	{
		memset(buf, 0, PATH_MAX_LENGTH);
		strcpy(buf, dir[i]);
		strcat(buf, "/");
		strcat(buf, command);
		stat_ret = stat(buf, &st);
		if (stat_ret == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			free_tokens(dir);
			ret = malloc(sizeof(char) * (strlen(buf) + 1));
			if (!ret)
				return (NULL);
			strcpy(ret, buf);
			return (ret);
		}
	}
	if (stat_ret == -1)
		free_tokens(dir);
	return (NULL);
}
