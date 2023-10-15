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
/**
 * struct list: linked list for envriomental variables
 * @var: the environmental variable
 * @len: the length of the environmental variable
 * @next: pointer to next node
*/
typedef struct list
{
char *var;
int len;
struct list *next;
}list_t;
int interactive(char **argv, char **env, list_t *head_path);
int non_interactive(int argc, char**);
int _strtok(char **tok, char *line, char *delim);
void signint(int sig);
size_t _strlen_sizet(char *s);
void handle_error(char *process, char *command, char *error_type);
int _putchar(char c);
void notfound(char *process, char *command);
void cannot_open(char *process, char *command);
int exit_builtin(void);
int _strcmp(char *s1, char *s2);
void list_environment_variables(void);
int _isspace(int c);
char *handle_spaces(char *str);
void list_environment_variables();
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
int _strlen(char *s);
void free_list(list_t *head);
list_t *env_linked_path(char **env);
char *getpath(char **env);
int check_for_path(char **command, char *path);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);

#endif
