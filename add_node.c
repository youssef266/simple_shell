#include "shell.h"

/**
* add_node -  a function that adds a new node at the
* beginning of a list_t list
* @head: the list
* @str: the data in new node
* Return: the address of the new element, or NULL if it failed
*/
list_t *add_node(list_t **head, const char *str)
{
list_t *Newnode;
int len;
char *element;
element = strdup(str);
Newnode = malloc(sizeof(list_t));
if (Newnode == NULL)
return (NULL);
if (element == NULL)
{
free(Newnode);
return (NULL);
}
Newnode->var = element;
len = _strlen(element);
Newnode->len = len;
Newnode->next = *head;
*head = Newnode;
return (Newnode);
}
