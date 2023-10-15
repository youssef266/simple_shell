#include "shell.h"
/**
 * 
 * 
 * 
*/
char *handle_spaces(char *str) {
    char *end;
    
    while (_isspace(*str)) {
        str++;
    }

    if (*str == '\0') {
        return str;
    }

    end = str + _strlen(str) - 1;
    while (end > str && _isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';
    return str;
}