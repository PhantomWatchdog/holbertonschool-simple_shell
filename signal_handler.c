#include "shell.h"

/**
 * handle_sigint - Signal handler for SIGINT (Ctrl+C)
 * @sig: Signal number
 *
 * Return: Nothing
 */

void handle_sigint(int sig)
{
	(void) sig;
	putchar('\n');
	prompt();
}

/**
 * handle_sigquit - Signal handler for SIGQUIT (Ctrl+\)
 * @sig: Signal number
 *
 * Return: Nothing
 */

void handle_sigquit(int sig)
{
	(void) sig;
	perror("Quit (core dumped)\n");
	exit(EXIT_SUCCESS);
}

/**
 * handle_sigstp - Signal handler for SIGTSTP (Ctrl+Z)
 * @sig: Signal number
 *
 * Return: Nothing
 */

void handle_sigstp(int sig)
{
	(void) sig;
	puts("\n");
	prompt();
}
