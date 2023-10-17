#include "shell.h"
/**
  * notfound - a function that handling the not found error
  * @process: Name of the process is made.
  * @command: Command or file name associated with the error.
  *
  * Return: voide.
  */
void notfound(char *process, char *command)
{
size_t lenth1, lenth2;
lenth1 = _strlen_sizet(process);
lenth2 = _strlen_sizet(command);
write(STDERR_FILENO, process, lenth1);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "1", 1);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, command, lenth2);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "not found\n", 11);
}

/**
  * cannot_open - a function that handling the can not open error
  * @process: Name of the process is made.
  * @command: Command or file name associated with the error.
  *
  * Return: voide.
  */
void cannot_open(char *process, char *command)
{
size_t lenth1, lenth2;
lenth1 = _strlen_sizet(process);
lenth2 = _strlen_sizet(command);
write(STDERR_FILENO, process, lenth1);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "2", 1);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, command, lenth2);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "can't open\n", 12);
}
/**
 * illegal - function that handle the exit
 *
 * @process: pointer to type char
 * @command: the command used
 * @num: number
 *
*/
void illegal(char *process, char *command, char *num)
{
size_t lenth1, lenth2, length3;
lenth1 = _strlen_sizet(process);
lenth2 = _strlen_sizet(command);
length3 = _strlen(num);
write(STDERR_FILENO, process, lenth1);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "2", 1);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, command, lenth2);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "Illegal number", 15);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, num, length3);
write(STDERR_FILENO, "\n", 2);
}
