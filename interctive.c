#include "shell.h"

/**
 * interactive: handle interactie mode
 * @argc: argument counter
 * @argv: argument vector
 * @environmental variable
 * Return: 0 on success
*/
int interactive(char **argv, char **env, list_t *head_path)
{
    char *command = NULL, *tok[10], *tok_by_word[10];
    size_t line_len = 0;
    ssize_t n_read = 1;
    int status, exit_stat = 0, exist = 0;
    pid_t child;
    list_t *temp;
    struct stat stats;

while (1)
{
if (isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO,"($) ", 4);
signal(SIGINT, signint);
n_read = getline(&command, &line_len, stdin);
if (n_read == -1)
{
if(isatty(STDIN_FILENO) != 0)
write(STDOUT_FILENO, "\n", 1);
if (command != NULL)
{
free(command);
free_list(head_path);
}
exit(exit_stat);
}
command = handle_spaces(command);
_strtok(tok, command, "\n");
if (tok[0] == NULL)
continue;
_strtok(tok_by_word, tok[0], " ");
 if (_strcmp(tok_by_word[0], "exit") == 0) {           
exit_builtin(argv, tok_by_word);
free(command);
free_list(head_path);
}
if (_strcmp(tok_by_word[0], "env") == 0) {
list_environment_variables();
continue;
}
exist = 0;
if (stat(tok_by_word[0], &stats) != 0)
{
exist = -1;
temp = head_path;
while (temp != NULL)
{
exist = check_for_path(&tok_by_word[0], temp->var);
if (exist == 1)
break;
temp = temp->next;
}
}
if (exist == -1)
continue;
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
execve(tok_by_word[0], tok_by_word, env);
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
