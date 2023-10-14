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
char *command = NULL, *tok[10];
size_t line_len = 0;
ssize_t n_read = 1;
int status, exit_stat = 0;
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
exit(exit_stat);
}
_strtok(tok, command, "\n");
if (tok[0] == NULL)
continue;
 if (_strcmp(tok[0], "exit") == 0) {
            exit_stat = exit_builtin();
            continue;
        }
        if (strcmp(tok[0], "env") == 0) {
            list_environment_variables();
            continue;
        }
child = fork();
if (child == -1)
{
if (command != NULL)
free(command);
notfound(argv[0], tok[0]);
exit(15);
}
if (child == 0)
{
execve(tok[0], tok, env);
notfound(argv[0], tok[0]);
exit(25);
}
else
{
wait(&status);
exit_stat = WEXITSTATUS(status);
kill(child, SIGKILL);
}
}

}

