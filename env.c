#include "shell.h"

extern char **environ;

void list_environment_variables(void) {
 int i = 0;
    while (environ[i] != NULL) {
        size_t len = _strlen(environ[i]);
        write(STDOUT_FILENO, environ[i], len);
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}
