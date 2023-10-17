#include "shell.h"
/**
 * _isspace - function that handle the spaces
 *
 * @c: var for type int
 * Return: space
*/
int _isspace(int c)
{
return (c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r');
}
