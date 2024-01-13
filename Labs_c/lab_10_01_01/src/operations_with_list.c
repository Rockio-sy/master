#include "operations_with_list.h"

int comparator_name_country(void *f_struct, void *s_struct)
{
    country_t *first = f_struct;
    country_t *second = s_struct;

    int res = (int) strcmp(first->name_country, second->name_country);

    return res;
}

int fwrite_countries(char *namefile, node_t *head)
{
    int rc = EXIT_SUCCESS;
    FILE *f_out = fopen(namefile, "w");
    if (f_out != NULL)
    {
        fprint_list(f_out, head);
        fclose(f_out);
    }
    else
        rc = RESULT_FILE;
    
    return rc;
}


void fprint_list(FILE *f, node_t *head)
{
    if (head != NULL)
    {
        for (; head; head = head->next)
            fprint_country(f, (country_t *) head->data);
    }
    else
    {
        if (f == stdout)
            printf("EMPTY!\n");
        else
            printf("EMPTY FILE!\n");
    }
}

void append(node_t **head_a, node_t **head_b)
{
    if (head_a != NULL && head_b != NULL)
    {
        if (*head_a == NULL)
            *head_a = *head_b;
        else
        {
            node_t *current = *head_a;
            for (; current->next; current = current->next);
            current->next = *head_b;
        }
        *head_b = NULL;
    }
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (head != NULL && comparator != NULL)
    {
        element->next = NULL;
        if (*head == NULL)
            *head = element;
        else
        {
            node_t *current = *head;
            node_t *prev = NULL;

            for (; current->next && comparator(element->data, current->data) >= 0; current = current->next)
                prev = current;

            if (prev == NULL)
            {
                if (comparator(element->data, current->data) < 0)
                {
                    element->next = *head;
                    *head = element;
                }
                else
                    (*head)->next = element;
            }
            else
            {
                if (!(current->next) && comparator(element->data, current->data) >= 0)
                    current->next = element;
                else
                {
                    element->next = current;
                    prev->next = element;
                }
            }
        }
    }
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *sort = NULL;
    if (head != NULL && comparator != NULL)
    {
        while (head != NULL)
        {
            node_t *node = head;
            head = head->next;
            sorted_insert(&sort, node, comparator);
        }
    }
    else
        sort = head;
    return sort;
}