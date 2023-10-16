#include "shell.h"

ssize_t _getline(char **lineptr, size_t *n, FILE *stream) {
    size_t bufsize = 128;
    size_t position = 0;
    int c;
    size_t new_size ;
    char *temp;

    if (!lineptr || !n || !stream) {
        return -1;
    }

    if (*lineptr == NULL) {
        *lineptr = (char *)malloc(bufsize);
        if (!*lineptr) {
            return -1;
        }
        *n = bufsize;
    }

    while (1) {
        c = fgetc(stream);

        if (c == EOF || c == '\n') {
            (*lineptr)[position] = '\0';
            return position;
        } else {
            (*lineptr)[position] = c;
        }

        position++;

    
        if (position >= *n) {
            new_size = *n + bufsize;
            temp = (char *)realloc(*lineptr, new_size);
            if (temp == NULL) {
                return -1;
            }
            *lineptr = temp;
            *n = new_size;
        }
    }
}