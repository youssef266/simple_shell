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
list_t *head_path = NULL;
head_path = env_linked_path(env);
if (argc == 1)
interactive(argv, env, head_path);
return (0);
}
