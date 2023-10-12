#include "shell.h"

/**
 * handle_error - a generic function for handling errors
 * @process: Name of the process where the error occurred.
 * @command: Command or file name associated with the error.
 * @error_type: Description of the error (e.g., "fork" or "execve").
 *
 * This function will print an error message with process, command, and error_type,
 * allowing more flexibility in error handling.
 */
void handle_error(char *process, char *command, char *error_type)
{
    size_t len_process = _strlen(process);
    size_t len_command = _strlen(command);
    size_t len_error_type = _strlen(error_type);

    write(STDERR_FILENO, process, len_process);
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, "1", 1);
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, command, len_command);
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, error_type, len_error_type);
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, "not found\n", 11);
}
