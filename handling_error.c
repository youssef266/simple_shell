#include "shell.h"
/**
  * handling_error - a function that handling the error
  * @process: Name of the process is made.
  * @exit_status: Exit status the is been developed.
  * @command: Command or file name associated with the error.
  *
  * Return: voide.
  */
void handling_error(char *process, int exit_status, char *command)
{
	size_t lenth1, lenth2, lenth3, lenth4;
	char status = exit_status + '0';
	char *error_message = "command not found\n", *open_message = "Can't open ";

	lenth1 = (size_t)_strlen(process);
	lenth2 = (size_t)_strlen(command);
	if (exit_status == 1)
	{
		lenth3 = (size_t)_strlen(error_message);
		write(STDERR_FILENO, process, lenth1);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, &status, 1);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, command, lenth2);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, error_message, lenth3);
	}
	if (exit_status == 0)
	{
		lenth4 = (size_t)_strlen(open_message);
		write(STDERR_FILENO, process, lenth1);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, &status, 1);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, open_message, lenth4);
		write(STDERR_FILENO, command, lenth2);
		write(STDERR_FILENO, "\n", 1);
	}
}
