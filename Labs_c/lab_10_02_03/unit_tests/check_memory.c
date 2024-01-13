#include "check_memory.h"

void print_result_tests(char *name_func, int test_neg, int neg_failed, int test_pos, int pos_failed);

int tests_create_and_free(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 1, test_pos = 2;

    {
        node_t *head = NULL;
        int n = 5;
        head = node_create(n);
        if (head == NULL || head->data != n)
            pos_cnt++;

        free_list(&head);
        if (head != NULL)
            pos_cnt++;

        free_list(&head);
        if (head != NULL)
            pos_cnt++;
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_push_list_back(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 1, test_pos = 2;

    {
        int n = 5;
        int rc = list_push_back(NULL, n);
        if (rc != EXIT_FAILURE)
            neg_cnt++;
    }

    {
        node_t *head = NULL;
        int n = 5;
        int rc = list_push_back(&head, n);
        if (rc != EXIT_SUCCESS || head->data != n)
            pos_cnt++;

        rc = list_push_back(&head, n + 1);
        if (rc != EXIT_SUCCESS || head->next->data != n + 1)
            pos_cnt++;

        free_list(&head);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_allocate_and_free_string(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 1, test_pos = 1;

    {
        int n = 0;
        char *str = allocate_malloc_string(n);
        if (str != NULL)
            neg_cnt++;

        free_malloc_string(&str);
        if (str != NULL)
            neg_cnt++;
    }

    {
        int n = 10;
        char *str = allocate_malloc_string(n);
        if (str == NULL)
            pos_cnt++;

        free_malloc_string(&str);
        if (str != NULL)
            pos_cnt++;
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}
