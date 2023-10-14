#include "shell.h"

/**
 * signint: handle ctrl+c
 * Return: nothing
*/

void signint(int sig)
{
    (void) sig;
write(STDIN_FILENO, "\n($)", 5);
}
