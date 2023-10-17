#include "shell.h"
/**
 * *handle_spaces - a function that handle the space
 * @str: string
 * Return: string
*/
char *handle_spaces(char *str)
{
	char *end;

	while (_isspace(*str))
	{
		str++;
	}
	if (*str == '\0')
	{
		return (str);
	}
	end = str + _strlen(str) - 1;
	while (end > str && _isspace(*end))
	{
		end--;
	}
	*(end + 1) = '\0';
	return (str);
}
