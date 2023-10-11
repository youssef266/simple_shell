#include "shell.h"

/**
 * _strlen - return the length of string
 * @s: the string
 * Return: the length of the string
*/

int _strlen(char *s)
{
	int str;

	for (str = 0; *s != '\0'; s++)
		str++;
	return (str);
}
