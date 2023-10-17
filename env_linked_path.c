#include "shell.h"

/**
 * env_linked_path - create a linked list of path to handle the path
 * ex (ls instead of /bin/ls)
 * @env: environmental variables
 * Return: pointer to the linked list contain the path
*/

list_t *env_linked_path(char **env)
{
char *path, *tok[20], *delim = ":";
int j = 0;
list_t *head = NULL;
path = getpath(env);
if (path == NULL)
return (NULL);
_strtok(tok, path, delim);
while (tok[j] != NULL)
{
add_node(&head, tok[j]);
j++;
}
return (head);
}
