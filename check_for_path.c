#include "shell.h"
/**
 * check_for_path - sseaerch for a file in path
 * command: the name of the file for example (ls)
 * path: the ath i looked for
 * return: 1 if success 0 if not
*/

int check_for_path(char **command, char *path)
{
char *fullname =NULL;
if (path[0] == '\0')
return (0);
fullname = _strdup(path);
fullname = _strcat(fullname, "/");
fullname = _strcat(fullname, *command);
if (access(fullname, F_OK) == 0)
{
*command = _strdup(fullname);
return (1);
}
return (0); 
}
