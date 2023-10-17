#include "shell.h"


/**
 * list_environment_variables - a function that list the env
*/
void list_environment_variables(void)
{
int i = 0;
size_t len;

while (environ[i] != NULL)
{
	len = _strlen(environ[i]);
	write(STDOUT_FILENO, environ[i], len);
	write(STDOUT_FILENO, "\n", 1);
	i++;
}
}
