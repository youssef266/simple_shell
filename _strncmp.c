#include "shell.h"


/**
 * _strncmp - function that compares two strings.
 * @s1: the first string
 * @s2: the second string
 * @n: number of characters to compare
 * Return: 0 if equal 1 if not
*/
int _strncmp(char *s1, char *s2, int n)
{
int i;
i = 0;
while (i < n)
{
if (*(s1 + i) == *(s2 + i))
{}
else
return (1);
i++;
}
return (0);
}
