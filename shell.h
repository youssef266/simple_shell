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
#include <signal.h>

int interactive(char **argv, char **env);
int non_interactive(int argc, char**);
int _strtok(char **tok, char *line, char *delim);
void signint(int sig);
size_t _strlen(char *s);
void handling_error(char *process, char *command);
int _putchar(char c);
#endif
