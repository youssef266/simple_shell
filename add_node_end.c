#include "shell.h"

/**
* add_node_end -  a function that adds a new node at the
* end of a list_t list
* @head: the list
* @str: the data in new node
* Return: the address of the new element, or NULL if it failed
*/
list_t *add_node_end(list_t **head, const char *str)
{
list_t *tail;
list_t *Newnode;
int len;
char *element;
element = strdup(str);
tail = *head;
if (*head != NULL)
{
while (tail->next != NULL)
tail = tail->next;
}
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
Newnode->next = NULL;
if (*head == NULL)
*head = Newnode;
else
tail->next = Newnode;
return (Newnode);
}
