#include "shell.h"
/**
 * interactive: handle interactie mode
 * @argc: argument counter
 * @argv: argument vector
 * @environmental variable
 * Return: 0 on success
*/

int interactive(char **argv, char **env)
{
char *command, *tok[10];
size_t line_len = 0;
int n_read = 1, status, exit_stat;
pid_t child;
while (1)
{
if (isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO,"($) ", 4);
n_read = getline(&command, &line_len, stdin);
if (n_read == -1)
{
if(isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO, "\n", 1);
if (command != NULL)
free(command);
exit(0);
}
}
_strtok(tok, command, "\n");
child = fork();
if (child == -1)
{
if (command != NULL)
free(command);
exit(15);
}
if (child == 0)
{
execve(tok[0], tok, env);
exit(25);
}
else
{
wait(&status);
exit_stat = WEXITSTATUS(status);
kill(child, SIGKILL);
}
}

