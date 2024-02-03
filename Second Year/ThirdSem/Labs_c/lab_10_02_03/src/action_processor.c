#include "action_processor.h"

int action_out(void)
{
    int rc = EXIT_SUCCESS;
    
    int num = 0;
    rc = read_num(&num);
    if (rc == EXIT_SUCCESS)
    {
        node_t *list = NULL;
        rc = translate_num_in_list(&list, num);
        if (rc == EXIT_SUCCESS)
            rc = print_list(list);
        free_list(&list);
    }
    
    return rc;
}

int action_mul(void)
{
    int rc = EXIT_SUCCESS;
    
    int num_1 = 0, num_2 = 0;
    rc = read_num(&num_1);
    if (rc == EXIT_SUCCESS)
    {
        rc = read_num(&num_2);
        if (rc == EXIT_SUCCESS)
        {
            node_t *list_1 = NULL, *list_2 = NULL, *result = NULL;
            rc = translate_num_in_list(&list_1, num_1);
            if (rc == EXIT_SUCCESS)
            {
                rc = translate_num_in_list(&list_2, num_2);
                if (rc == EXIT_SUCCESS)
                {
                    rc = multiply_lists(&result, list_1, list_2);
                    if (rc == EXIT_SUCCESS)
                        rc = print_list(result);
                }
            }
            free_list(&list_1);
            free_list(&list_2);
            free_list(&result);
        }
    }
    
    return rc;
}

int action_div(void)
{
    int rc = EXIT_SUCCESS;
    
    int num_1 = 0, num_2 = 0;
    rc = read_num(&num_1);
    if (rc == EXIT_SUCCESS)
    {
        rc = read_num(&num_2);
        if (rc == EXIT_SUCCESS)
        {
            node_t *list_1 = NULL, *list_2 = NULL, *result = NULL;
            rc = translate_num_in_list(&list_1, num_1);
            if (rc == EXIT_SUCCESS)
            {
                rc = translate_num_in_list(&list_2, num_2);
                if (rc == EXIT_SUCCESS)
                {
                    rc = divide_lists(&result, list_1, list_2);
                    if (rc == EXIT_SUCCESS)
                        rc = print_list(result);
                }
            }
            free_list(&list_1);
            free_list(&list_2);
            free_list(&result);
        }
    }
    
    return rc;
}

int action_sqr(void)
{
    int rc = EXIT_SUCCESS;
    
    int num = 0;
    rc = read_num(&num);
    if (rc == EXIT_SUCCESS)
    {
        node_t *result = NULL, *list = NULL;
        rc = translate_num_in_list(&list, num);
        if (rc == EXIT_SUCCESS)
        {
            rc = sqr_list(&result, list);
            if (rc == EXIT_SUCCESS)
                rc = print_list(result);
        }
        free_list(&list);
        free_list(&result);
    }
    
    return rc;
}