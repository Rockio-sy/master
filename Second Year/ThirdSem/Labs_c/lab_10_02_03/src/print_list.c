#include "print_list.h"

int print_list(node_t *head)
{
    int rc = EXIT_SUCCESS;
    if (head == NULL)
        rc = EMPTY_LIST;
    else
    {
        node_t *current = head;

        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }

        printf("%s", SYMBOL_PRINT);
    }

    return rc;
}