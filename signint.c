#include "shell.h"

/**
 * signint: handle ctrl+c
 * Return: nothing
*/

void signint(void)
{
write(STDIN_FILENO, "\n($)", 5);
}