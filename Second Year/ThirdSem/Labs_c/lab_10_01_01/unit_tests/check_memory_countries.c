#include "check_memory_countries.h"

void print_result_tests(char *name_func, int test_neg, int neg_failed, int test_pos, int pos_failed);

int tests_allocate_and_free_country(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 3, test_pos = 2;

    {
        country_t *array = NULL;
        int size = 0;

        array = allocate_struct_country(-1);
        if (array != NULL)
            neg_cnt++;

        array = allocate_struct_country(size);
        if (array != NULL)
            neg_cnt++;

        free_struct_country(&array, &size);
        if (array != NULL)
            neg_cnt++;
    }

    {
        country_t *array = NULL;
        int size = 100;

        array = (country_t *) allocate_struct_country(size);
        if (array == NULL)
            pos_cnt++;

        free_struct_country(&array, &size);
        if (array != NULL || size != 0)
            pos_cnt++;
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_allocate_and_free_str(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 3, test_pos = 2;

    {
        char *str = NULL;
        int len = 0;

        str = allocate_name_str(-10);
        if (str != NULL)
            neg_cnt++;

        str = allocate_name_str(len);
        if (str != NULL)
            neg_cnt++;

        free_name_str(&str);
        if (str != NULL)
            neg_cnt++;
    }

    {
        char *str = NULL;
        int len = 100;

        str = allocate_name_str(len);
        if (str == NULL)
            pos_cnt++;

        free_name_str(&str);
        if (str != NULL)
            pos_cnt++;
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}