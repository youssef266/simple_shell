#include "shell.h"
#include <stdlib.h>

int interactive(char **argv, char **env, list_t *head_path);

/**
 * interactive - handle interactive mode
 * @argv: argument vector
 * @env: environmental variables
 * @head_path: var for the head path
 * Return: 0 on success
 */
int interactive(char **argv, char **env, list_t *head_path)
{
    char *command = NULL;
    size_t line_len = 0;
    ssize_t n_read = 1;
    int status, exit_stat = 0, exist = 0;
    pid_t child;
    list_t *temp;
    struct stat stats;
	char **tok;
	char **tok_by_word;

    while (1) {
        if (isatty(STDIN_FILENO) != 0)
            write(STDOUT_FILENO, "($) ", 4);

        signal(SIGINT, signint);

        n_read = getline(&command, &line_len, stdin);

        if (n_read == -1) {
            if (isatty(STDIN_FILENO) != 0)
                write(STDOUT_FILENO, "\n", 1);
            if (command != NULL) {
                free(command);
                free_list(head_path);
            }
            exit(exit_stat);
        }

        command = handle_spaces(command);

        tok = malloc(sizeof(char*) * 10);
        if (tok == NULL) {
           
            perror("Error allocating memory for tokens");
            exit(1);
        }
        
        _strtok(tok, command, "\n");

        if (tok[0] == NULL) {
            free(tok);
            continue;
        }

        tok_by_word = malloc(sizeof(char*) * 10);
        if (tok_by_word == NULL) {
           
            perror("Error allocating memory for tokens");
            exit(1);
        }

        _strtok(tok_by_word, tok[0], " ");

        if (_strcmp(tok_by_word[0], "exit") == 0) {
            exit_builtin(argv, tok_by_word);
            free(command);
            free(tok);
            free(tok_by_word);
            free_list(head_path);
        } else if (_strcmp(tok_by_word[0], "env") == 0) {
            list_environment_variables();
        } else {
            exist = 0;
            if (stat(tok_by_word[0], &stats) != 0) {
                exist = -1;
                temp = head_path;
                while (temp != NULL) {
                    exist = check_for_path(&tok_by_word[0], temp->var);
                    if (exist == 1)
                        break;
                    temp = temp->next;
                }
            }

            if (exist == -1) {
                free(tok);
                free(tok_by_word);
                continue;
            }

            child = fork();
            if (child == -1) {
                if (command != NULL)
                    free(command);
                notfound(argv[0], tok_by_word[0]);
                free(tok);
                free(tok_by_word);
                exit(15);
            }

            if (child == 0) {
                exit_stat = execve(tok_by_word[0], tok_by_word, env);
                notfound(argv[0], tok_by_word[0]);
                free(tok);
                free(tok_by_word);
                exit(exit_stat);
            } else {
                wait(&status);
                exit_stat = WEXITSTATUS(status);
                kill(child, SIGKILL);
            }
        }

        free(tok);
        free(tok_by_word);
    }
}
