#include "shell.h"

/**
 * non_interactive: handle non interactie mode
 * @argc: argument counter
 * @argv: argument vector
 * @environmental variable
 * Return: 0 on success
*/
int non_interactive(int argc, char **argv, char **env, list_t *head_path)
{
    char *command = NULL, *tok[10], *tok_by_word[10], *temp_2;
    int status, exit_stat = 0, exist = 0, i = 0;
    pid_t child;
    list_t *temp;
    struct stat stats;
    (void) argc;
command = argv[1];
for (i = 2; i < argc; i++)
{
temp_2 = strdup(command);
command = strdup(_strcat(temp_2, " "));
temp_2 = strdup(command);
command = strdup(_strcat(temp_2, argv[i]));
}
_strtok(tok, command, "\n");
if (tok[0] == NULL)
exit(35);
_strtok(tok_by_word, tok[0], " ");
 if (_strcmp(tok_by_word[0], "exit") == 0) {           
exit_builtin(argv, tok_by_word);
}
if (_strcmp(tok_by_word[0], "env") == 0) {
list_environment_variables();
exit(exit_stat);
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
exit(-1);
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
return(1);
}

