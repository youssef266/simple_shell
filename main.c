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
signal(SIGINT, signint);
if (argc == 1)
interactive(argv, env);
return (0);
}