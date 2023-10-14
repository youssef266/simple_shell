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
lenth1 = _strlen(process);
lenth2 = _strlen(command);
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
lenth1 = _strlen(process);
lenth2 = _strlen(command);
write(STDERR_FILENO, process, lenth1);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "2", 1);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, command, lenth2);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "can't open\n", 12);
}
