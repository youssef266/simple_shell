#include "shell.h"

/**
 * signint -  handle ctrl+d
 * @sig: var type int
 * Return: nothing
*/

void signint(int sig)
{
	(void) sig;
write(STDIN_FILENO, "\n($)", 5);
}
