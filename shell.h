#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <string.h>

int interactive(int argc, char **argv, char **env);
int non_interactive(int argc, char**);
int _strtok(char **tok, char *line, char *delim);

#endif
