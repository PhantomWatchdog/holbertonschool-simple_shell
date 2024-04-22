#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * read_command - Read a command from standard input.
 * @buffer: Buffer to store the input command.
 * @read_result: Pointer to store the result of the read operation.
 */
void read_command(char *buffer, ssize_t *read_result);

/**
 * execute_command - Execute a command.
 * @buffer: Buffer containing the command to execute.
 */
void execute_command(char *buffer);

/**
 * main - Entry point of the simple shell program.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of pointers to the arguments passed to the program.
 * Return: Always returns EXIT_SUCCESS (0) upon successful completion.
 */
int main(int argc, char **argv)
{
	char buffer[BUFFER_SIZE];
	ssize_t read_result;
	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}
		read_command(buffer, &read_result);

		if (read_result == 0)
		{
			if (isatty(STDIN_FILENO))
			{
				printf("\n");
			}
			break;
		}
		execute_command(buffer);
	}
	return (EXIT_SUCCESS);
}

/**
 * read_command - Read a command from standard input.
 * @buffer: Buffer to store the input command.
 * @read_result: Pointer to store the result of the read operation.
 */
void read_command(char *buffer, ssize_t *read_result)
{
	size_t length;

	*read_result = read(STDIN_FILENO, buffer, BUFFER_SIZE);
	if (*read_result < 0)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}

	length = (size_t)(*read_result);

	if (buffer[length - 1] == '\n')
	{
		buffer[length - 1] = '\0';
	}
}

/**
 * execute_command - Execute a command.
 * @buffer: Buffer containing the command to execute.
 */
void execute_command(char *buffer)
{
	char *args[2];
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		args[0] = buffer;
		args[1] = NULL;
		execve(args[0], args, NULL);
		perror("./hsh");
		_exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}





