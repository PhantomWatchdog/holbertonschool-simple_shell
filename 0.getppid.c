#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t parent_pid; /* Declaration variable for to get the PID */

    parent_pid = getppid(); /* Obtaining the PID of the parent process grace the function getppid */
    printf("Parent PID: %u\n", parent_pid); /* Display the PID of the parent process*/

    return 0; /* To say that the function return the correct value */
}

