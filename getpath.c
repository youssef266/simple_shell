#include "shell.h"

/**
 * getpath - a function that returns the path from
 * the environmental variable
 * @env: the environmental variable
 * Return: null
*/
char *getpath(char **env)
{
char *tmp, *returned;
int i = 0;
while (env[i] != NULL)
{
if (strncmp(env[i], "PATH", 4) == 0)
{
tmp = env[i];
strtok(tmp, "=");
(returned = strtok(NULL, ""));
return (returned);
}
i++;
}
return (NULL);
}
