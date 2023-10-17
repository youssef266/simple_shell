#include "shell.h"
/**
 * _isdigit - indicate if string is digit or not
 * @s: string to check
 * Return: 1 if s is digit and 0 otherwise
 */
int _isdigit(char *s)
{
int i;
if (s == NULL)
return (0);
for (i = 0; s[i] != '\0'; i++)
if (s[i] < '0' || s[i] > '9')
return (0);
return (1);
}
