#include "shell.h"
/**
 * exit_builtin - Implement the exit built-in command.
 *
 * Return: 0 (indicating successful execution)
 */
int exit_builtin(void)
{
    char message[] = "Exiting the shell.\n";
    write(STDOUT_FILENO, message, sizeof(message) - 1);
    exit(0);
}
