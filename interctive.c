#include "shell.h"
/**
 * interactive: handle interactie mode
 * @argc: argument counter
 * @argv: argument vector
 * @environmental variable
 * Return: 0 on success
*/

int interactive(int argc, char **argv, char **env)
{
char *command, *tok[10];
size_t line_len = 0;
int n_read = 1;
(void) argc;
write(STDOUT_FILENO,"($) ", 4);
n_read = getline(&command, &line_len, stdin);
while (n_read)
{
_strtok(tok, command, "\n");
}
}
