#include "shell.h"

/**
 * _atoi - convert a string to an integer
 * @s: string
 * Return: integer in string
 */

int _atoi(char *s)
{
int start = 0, len, i = 0, neg = 0, temp = 0, j = 0, k = 0;
int sign = 1, ten = 1, num_of_digits = 0;
int l = 0, no_digit = 1, to_int = 0;
unsigned int num = 0;
len = _strlen (s);
for (j = 0; j <= len; j++)
{
if (s[j] >= '0' && s[j] <= '9')
{
start = j;
no_digit = 0;
break;
}}
if (no_digit == 1)
return (0);
while (i < start)
{
if (s[i] == '-')
neg++;
i++;
}
if (neg % 2 != 0)
sign = -1;
temp = start;
while ((s[temp] >= '0' && s[temp] <= '9') && s[temp] != '\0')
{
num_of_digits++;
temp++;
}
for (l = 1; l < num_of_digits; l++)
ten *= 10;
for (k = 0; k < num_of_digits; k++)
{
to_int = s[start] - '0';
num += to_int *ten;
ten /= 10;
start++;
}
return (num *sign);
}
