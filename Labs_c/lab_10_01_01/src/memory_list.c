#include "memory_list.h"

int list_push(node_t **head, void *element)
{
    int rc = EXIT_SUCCESS;
    if (head == NULL)
        rc = EXIT_FAILURE;
    else
    {
        node_t *node = node_create(element);
        if (node != NULL)
        {
            if (*head == NULL)
                *head = node;
            else
            {
                node_t *tail = *head;
                for (;tail->next; tail = tail->next);
                tail->next = node;
            }
        }
        else
            rc = MEMORY_ERROR;
    }

    return rc;
}

node_t *node_create(void *data)
{
    node_t *node = NULL;
    if (data != NULL)
    {
        node = (node_t *) malloc(sizeof(node_t));
        if (node != NULL)
        {
            node->data = data;
            node->next = NULL;
        }
    }
    return node;
}

void free_list(node_t **head)
{
    if (head != NULL && *head != NULL)
    {
        node_t *next_elem;

        for (;*head; *head = next_elem)
        {
            next_elem = (*head)->next;
            free(*head);
        }
        *head = NULL;
    }
}