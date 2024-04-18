#include <stdio.h>
#include <unistd.h>

/**
 * main - Print the PID and PPID.
 * Return: Always 0.
 */

int main(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("Enfant %u\n", my_pid);
	my_pid = getppid();
	printf("Parent %u\n", my_pid);
	return (0);
}
