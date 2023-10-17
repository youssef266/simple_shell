#include "shell.h"
/**
 * exit_builtin - Implement the exit built-in command.
 * @tok: to take the status of exit
 * @argv: the argument given value
 */
void exit_builtin(char **argv, char **tok)
{
int exit_stat = 0;
if (tok[1] == NULL)
exit(0);
if (_isdigit(tok[1]) == 0)
{
illegal(argv[0], tok[0], tok[1]);
exit(2);
}
exit_stat = _atoi(tok[1]);
if (exit_stat < 0)
{
illegal(argv[0], tok[0], tok[1]);
exit(2);
}
exit(exit_stat);
}
