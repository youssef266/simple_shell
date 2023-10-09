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
char *token;
int len = 1, i = 1;
token = strtok(line, delim);
tok[0] = token;
while (token != NULL)
{
token = strtok(NULL, delim);
tok[i] = token;
i++, len++;
}
return (len);
}

