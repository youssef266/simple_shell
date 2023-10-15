#include "shell.h"
/**
 * _strtok: parse string to sequence of tokens
 * tok: pointer to array of strings
 * line: the command
 * delim: the delimiter
 * Return: number of tokens
*/

int _strtok(char **tok, char *line, char *delim)
{
char *tmp, *str;
int i = 0;
for (str = line; ; str = NULL)
{
tmp = strtok(str, delim);
tok[i] = tmp;
if (tmp == NULL)
break;
i++;
}
return (i);
}

