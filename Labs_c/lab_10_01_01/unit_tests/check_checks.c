#include "check_checks.h"

#define UNIT_TESTS_FILE "unit_test.txt"
#define WRITE_SEQUENCE(fd, sequence) \
    rewind((fd));                    \
    fprintf((fd), sequence);         \
    rewind((fd))

void print_result_tests(char *name_func, int test_neg, int neg_failed, int test_pos, int pos_failed);

int tests_check_file(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 2, test_pos = 1;

    {
        FILE *f = NULL;
        int rc = check_file(f);
        if (rc != FILE_NOT_FOUND)
            neg_cnt++;
    }

    {
        FILE *f = NULL;
        f = fopen(UNIT_TESTS_FILE, "w+");
        int rc = check_file(f);
        if (rc != FILE_IS_EMPTY)
            neg_cnt++;
        remove(UNIT_TESTS_FILE);
    }

    {
        FILE *f = NULL;
        f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f, "data\n");

        int rc = check_file(f);
        if (rc != EXIT_SUCCESS)
            pos_cnt++;
        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_check_argc(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 6, test_pos = 5;

    {
        int rc = check_argc(-10, "a", 3, 5);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        rc = check_argc(0, "a", 3, 5);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        rc = check_argc(4, "a", -1, 5);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        rc = check_argc(4, "a", 5, 3);
        if (rc != PARAMS_ERROR)
            neg_cnt++;
    }

    {
        int rc = check_argc(4, "pg", 4, 5);
        if (rc != ACTION_ERROR)
            neg_cnt++;

        rc = check_argc(10, "pf", 4, 5);
        if (rc != ARGC_ERROR)
            neg_cnt++;
    }

    {
        int rc = check_argc(4, "pf", 4, 5);
        if (rc != EXIT_SUCCESS)
            pos_cnt++;

        rc = check_argc(4, "pb", 4, 5);
        if (rc != EXIT_SUCCESS)
            pos_cnt++;

        rc = check_argc(4, "s", 4, 5);
        if (rc != EXIT_SUCCESS)
            pos_cnt++;

        rc = check_argc(5, "a", 4, 5);
        if (rc != EXIT_SUCCESS)
            pos_cnt++;

        rc = check_argc(5, "f", 4, 5);
        if (rc != EXIT_SUCCESS)
            pos_cnt++;
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_str_not_only_spaces(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 1, test_pos = 2;

    {
        int rc = str_not_only_spaces(NULL);
        if (rc != 0)
            neg_cnt++;
    }

    {
        int rc = str_not_only_spaces("                 ");
        if (rc != 0)
            pos_cnt++;

        rc = str_not_only_spaces("        asasasas         ");
        if (rc != 1)
            pos_cnt++;
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}
