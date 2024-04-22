#include <stdio.h>
#include <stdlib.h>

/**
 * main - Print all the arguments without ac use.
 * @ac: Argument count.
 * @av: Argument values.
 * Return: 0
 */

int main(int ac, char **av)
{
	int count = 0; /* Declaration of the variable count */
                    /* for traverse arguments */

	while (av[count] != NULL) /* As long as the current element */
                                /* of av is not NULL */
	{
		printf("%s ", av[count]); /* Display the current argument */
		count++; /* Incrementation of count for to move to the next arguement */
	}
	printf("\n"); /* All arguments have been displayed, print a newline character */
	return (0); /* Return 0 if the program is success */
}

