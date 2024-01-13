#include "check_memory.h"
#include "check_math_operations.h"

void print_result_tests(char *name_func, int test_neg, int neg_failed, int test_pos, int pos_failed)
{
    printf("===%s:\n -Негативные тесты: %d of %d - %s\n", name_func, test_neg - neg_failed, test_neg, neg_failed ? "FAILED" : "SUCCESS");
    printf(" -Позитивные тесты: %d of %d - %s\n", test_pos - pos_failed, test_pos, pos_failed ? "FAILED" : "SUCCESS");
}

int main()
{
    int failed_tests = 0;

    failed_tests += tests_create_and_free();
    failed_tests += tests_push_list_back();
    failed_tests += tests_allocate_and_free_string();

    failed_tests += test_check_simple_num();
    failed_tests += tests_get_simple_num();

    failed_tests += tests_len_str();
    failed_tests += tests_translate();

    failed_tests += tests_multiply_lists();
    failed_tests += tests_divide_lists();
    failed_tests += tests_sqr_lists();

    return failed_tests;
}