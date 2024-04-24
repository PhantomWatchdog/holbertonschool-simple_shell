#include "main.h"

/**
 * prompt - Display prompt.
 * Return: void.
*/

void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
