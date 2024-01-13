#include "check_memory_list.h"

void print_result_tests(char *name_func, int test_neg, int neg_failed, int test_pos, int pos_failed);

int tests_list_push(void)
{
    int pos_cnt = 0, test_pos = 2;

    node_t *head = NULL;
    int rc = EXIT_SUCCESS;

    int array[5] = {1, 2, 3 ,4, 5};

    rc = list_push(&head, array);
    if (rc != EXIT_SUCCESS || head == NULL || *(int *)head->data != *(array))
        pos_cnt++;

    rc = list_push(&head, array + 1);
    if (rc != EXIT_SUCCESS || head == NULL || *(int *)head->next->data != *(array + 1))
        pos_cnt++;

    free_list(&head);
    print_result_tests((char *) __func__, 0, 0, test_pos, pos_cnt);

    return pos_cnt;
}

int tests_node_create(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 1, test_pos = 2;

    int array[5] = {1, 2, 3 ,4, 5};
    int n = 5;
    {
        node_t *head = NULL;
        head = node_create(NULL);
        if (head != NULL)
            neg_cnt++;
    }

    {
        node_t *head = NULL;
        head = node_create(array + 0);

        if (head == NULL && *(int *) head->data != array[0])
            pos_cnt++;

        free_list(&head);
    }

    {
        node_t *head = NULL;
        int rc = EXIT_SUCCESS;

        for (int i = 0; i < n && !rc; i++)
            rc = list_push(&head, array + i);

        if (rc != EXIT_SUCCESS || head == NULL)
            pos_cnt++;
        else
        {
            int check = 0;
            node_t *check_head = head;
            for (int i = 0; i < n && !check; i++, check_head = check_head->next)
                if (*(int *) check_head->data != *(array + i))
                {
                    pos_cnt++;
                    check = 1;
                }
        }

        free_list(&head);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_list_free(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 2, test_pos = 2;

    {
        node_t **head = NULL;

        free_list(head);
        if (head != NULL)
            neg_cnt++;
    }

    {
        node_t *head = NULL;

        free_list(&head);
        if (head != NULL)
            neg_cnt++;
    }

    {
        int n = 5;
        node_t *head = node_create(&n);
        free_list(&head);
        if (head != NULL)
            pos_cnt++;
    }

    {
        int array[5] = {1, 2, 3 ,4, 5};
        int n = 5, rc = EXIT_SUCCESS;
        node_t *head = NULL;

        for(int i = 0; i < n && !rc; i++)
            rc = list_push(&head, array + i);
        free_list(&head);
        if (rc != EXIT_SUCCESS || head != NULL)
            pos_cnt++;
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}