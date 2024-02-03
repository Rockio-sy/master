#include "math_operation_list.h"

int translate_list_in_num(node_t *list, int *num)
{
    int rc = EXIT_SUCCESS;
    if (list == NULL)
        rc = PARAMS_ERROR;
    else
    {
        *num = 1;
        int base_degree = 2;

        while (list != NULL)
        {
            for (int i = 0; i < list->data; i++)
                (*num) *= base_degree;

            while (check_simple_num(++base_degree) != 1);

            list = list->next;
        }
    }

    return rc;
}

int translate_num_in_list(node_t **list, int num)
{
    int rc = EXIT_SUCCESS;
    if (list == NULL || *list != NULL)
        rc = PARAMS_ERROR;
    else
    {
        if (num < LIMIT_TRANSLATE)
            rc = TASK_ERROR;
        else
        {
            int last_num = 1;
            int power = 0;

            while (num != 1 && !rc)
            {
                last_num = get_simple_num(last_num);
                if (last_num == INT_MAX)
                    rc = TASK_ERROR;
                else
                {
                    while (num % last_num == 0)
                    {
                        num /= last_num;
                        power++;
                    }
                    rc = list_push_back(list, power);
                    power = 0;
                }
            }
        }
    }

    return rc;
}

int len_list(node_t *list)
{
    int len = 0;

    for (; list; list = list->next, len++);

    return len;
}

int multiply_lists(node_t **result, node_t *list_1, node_t *list_2)
{
    int rc = EXIT_SUCCESS;

    if (result == NULL || *result != NULL || list_1 == NULL || list_2 == NULL)
        rc = PARAMS_ERROR;
    else
    {
        node_t *short_list = NULL, *long_list = NULL;
        if (len_list(list_1) >= len_list(list_2))
        {
            long_list = list_1;
            short_list = list_2;
        }
        else
        {
            long_list = list_2;
            short_list = list_1;
        }

        while (long_list != NULL && !rc)
        {
            if (short_list)
            {
                rc = list_push_back(result, long_list->data + short_list->data);
                short_list = short_list->next;
            }
            else
                rc = list_push_back(result, long_list->data);
            long_list = long_list->next;
        }
    }

    return rc;
}

int divide_lists(node_t **result, node_t *list_1, node_t *list_2)
{
    int rc = EXIT_SUCCESS;

    if (result == NULL || *result != NULL || list_1 == NULL || list_2 == NULL)
        rc = PARAMS_ERROR;
    else
    {
        int div_1, div_2;
        translate_list_in_num(list_1, &div_1);
        translate_list_in_num(list_2, &div_2);
        if (div_2 == 0)
            rc = DIVIDE_ERROR;
        else
        {
            int res_num = 0;
            if (div_1 != 0)
                res_num = div_1 / div_2;
            rc = translate_num_in_list(result, res_num);
        }
    }

    return rc;
}

int sqr_list(node_t **result, node_t *list)
{
    int rc = EXIT_SUCCESS;
    if (result == NULL || *result != NULL || list == NULL)
        rc = PARAMS_ERROR;
    else
        rc = multiply_lists(result, list, list);

    return rc;
}