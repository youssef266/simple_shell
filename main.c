#include "shell.h"
/**
 * main: main function to compile the code
 * @argc: argument counter
 * @argv: argument vector
 * @environmental variable
 * Return: 0 on success
*/
int main(int argc, char **argv, char **env)
{
if (argc == 1)
interactive(argc, argv, env);
return (0);
}