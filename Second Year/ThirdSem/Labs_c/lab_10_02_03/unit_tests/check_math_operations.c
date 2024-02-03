#include "check_math_operations.h"

void print_result_tests(char *name_func, int test_neg, int neg_failed, int test_pos, int pos_failed);

int test_check_simple_num(void)
{
    int pos_cnt = 0,  test_pos = 6;

    {
        int result = check_simple_num(1);
        if (result)
            pos_cnt++;

        result = check_simple_num(0);
        if (result)
            pos_cnt++;

        result = check_simple_num(-10);
        if (result)
            pos_cnt++;
    }

    {
        int result = check_simple_num(2);
        if (!result)
            pos_cnt++;

        result = check_simple_num(5);
        if (!result)
            pos_cnt++;

        result = check_simple_num(11);
        if (!result)
            pos_cnt++;
    }

    print_result_tests((char *) __func__, 0, 0, test_pos, pos_cnt);

    return pos_cnt;
}

int tests_get_simple_num(void)
{
    int pos_cnt = 0,  test_pos = 3;

    {
        int result = get_simple_num(24);
        if (result != 29)
            pos_cnt++;

        result = get_simple_num(1);
        if (result != 2)
            pos_cnt++;

        result = get_simple_num(50);
        if (result != 53)
            pos_cnt++;

    }

    print_result_tests((char *) __func__, 0, 0, test_pos, pos_cnt);

    return pos_cnt;
}

int tests_len_str(void)
{
    int pos_cnt = 0,  test_pos = 3;

    {
        node_t *head = NULL;
        int len = 0;

        len = len_list(head);
        if (len != 0)
            pos_cnt++;

        (void) list_push_back(&head, len + 1);

        len = len_list(head);
        if (len != 1)
            pos_cnt++;

        (void) list_push_back(&head, len + 1);
        (void) list_push_back(&head, len + 2);

        len = len_list(head);
        if (len != 3)
            pos_cnt++;

        free_list(&head);
    }

    print_result_tests((char *) __func__, 0, 0, test_pos, pos_cnt);

    return pos_cnt;
}

int tests_translate(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 5, test_pos = 2;

    {
        int rc = EXIT_SUCCESS;
        node_t *head = NULL;
        int n = 10;


        rc = translate_num_in_list(NULL, n);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        head = node_create(n + 1);


        rc = translate_num_in_list(&head, n);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        rc = translate_list_in_num(NULL, &n);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        free_list(&head);
    }

    {
        int rc = EXIT_SUCCESS;
        node_t *head = NULL;
        int n = -1;

        rc = translate_num_in_list(&head, n);
        if (rc != TASK_ERROR)
            neg_cnt++;

        n = 1;

        rc = translate_num_in_list(&head, n);
        if (rc != TASK_ERROR)
            neg_cnt++;

        free_list(&head);
    }

    {
        int rc = EXIT_SUCCESS;
        node_t *head = NULL;
        int n = 10;

        rc = translate_num_in_list(&head, n);
        if (rc != EXIT_SUCCESS)
            pos_cnt++;

        free_list(&head);
    }

    {
        int rc = EXIT_SUCCESS;
        node_t *head = NULL;
        int n = 16;

        rc = translate_num_in_list(&head, n);
        if (rc != EXIT_SUCCESS)
            pos_cnt++;

        free_list(&head);
    }

    {
        int rc = EXIT_SUCCESS, n;
        node_t *head = NULL;
        (void) list_push_back(&head, 1);
        (void) list_push_back(&head, 2);

        rc = translate_list_in_num(head, &n);
        if (rc != EXIT_SUCCESS || n != 18)
            pos_cnt++;

        free_list(&head);
    }

    {
        int rc = EXIT_SUCCESS, n;
        node_t *head = NULL;
        (void) list_push_back(&head, 0);
        (void) list_push_back(&head, 0);
        (void) list_push_back(&head, 0);
        (void) list_push_back(&head, 1);

        rc = translate_list_in_num(head, &n);
        if (rc != EXIT_SUCCESS || n != 7)
            pos_cnt++;

        free_list(&head);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_multiply_lists(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 3, test_pos = 2;

    {
        int rc = EXIT_SUCCESS;

        node_t *list_1 = NULL, *list_2 = NULL, *res = NULL;

        list_1 = node_create(1);
        list_2 = node_create(2);

        rc = multiply_lists(NULL, list_1, list_2);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        rc = multiply_lists(&res, NULL, list_2);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        rc = multiply_lists(&res, list_1, NULL);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        free_list(&list_1);
        free_list(&list_2);
        free_list(&res);
    }

    {
        int rc = EXIT_SUCCESS;

        node_t *list_1 = NULL, *list_2 = NULL, *res = NULL;

        list_1 = node_create(1);
        list_2 = node_create(1);

        rc = multiply_lists(&res, list_1, list_2);
        if (rc != EXIT_SUCCESS || res->data != 2)
            pos_cnt++;

        free_list(&list_1);
        free_list(&list_2);
        free_list(&res);
    }

    {
        int rc = EXIT_SUCCESS;

        node_t *list_1 = NULL, *list_2 = NULL, *res = NULL;

        list_1 = node_create(1);
        list_2 = node_create(2);

        rc = multiply_lists(&res, list_1, list_2);
        if (rc != EXIT_SUCCESS || res->data != 3)
            pos_cnt++;

        free_list(&list_1);
        free_list(&list_2);
        free_list(&res);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_divide_lists(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 3, test_pos = 2;

    {
        int rc = EXIT_SUCCESS;

        node_t *list_1 = NULL, *list_2 = NULL, *res = NULL;

        list_1 = node_create(1);
        list_2 = node_create(2);

        rc = divide_lists(NULL, list_1, list_2);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        rc = divide_lists(&res, NULL, list_2);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        rc = divide_lists(&res, list_1, NULL);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        free_list(&list_1);
        free_list(&list_2);
        free_list(&res);
    }

    {
        int rc = EXIT_SUCCESS;

        node_t *list_1 = NULL, *list_2 = NULL, *res = NULL;

        (void) list_push_back(&list_1, 1);
        (void) list_push_back(&list_1, 0);
        (void) list_push_back(&list_1, 1);
        list_2 = node_create(1);

        rc = divide_lists(&res, list_1, list_2);
        if (rc != EXIT_SUCCESS || res->data != 0)
            pos_cnt++;

        free_list(&list_1);
        free_list(&list_2);
        free_list(&res);
    }

    {
        int rc = EXIT_SUCCESS;

        node_t *list_1 = NULL, *list_2 = NULL, *res = NULL;

        (void) list_push_back(&list_1, 1);
        (void) list_push_back(&list_1, 0);
        (void) list_push_back(&list_1, 1);
        (void) list_push_back(&list_2, 0);
        (void) list_push_back(&list_2, 0);
        (void) list_push_back(&list_2, 1);

        rc = divide_lists(&res, list_1, list_2);
        if (rc != EXIT_SUCCESS || res->data != 1)
            pos_cnt++;

        free_list(&list_1);
        free_list(&list_2);
        free_list(&res);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_sqr_lists(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 2, test_pos = 1;

    {
        int rc = EXIT_SUCCESS;

        node_t *list_1 = NULL, *res = NULL;

        list_1 = node_create(2);

        rc = sqr_list(NULL, list_1);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        rc = sqr_list(&res, NULL);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        free_list(&list_1);
        free_list(&res);
    }

    {
        int rc = EXIT_SUCCESS;

        node_t *list_1 = NULL, *res = NULL;

        (void) list_push_back(&list_1, 1);


        rc = sqr_list(&res, list_1);
        if (rc != EXIT_SUCCESS || res->data != 2)
            pos_cnt++;

        free_list(&list_1);
        free_list(&res);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}