#include "check_memory_list.h"
#include "check_list_operations.h"
#include "check_checks.h"
#include "check_memory_countries.h"
#include "check_read_countries.h"

void print_result_tests(char *name_func, int test_neg, int neg_failed, int test_pos, int pos_failed)
{
    printf("%s:\n NEG TEST: %d of %d - %s\n", name_func, test_neg - neg_failed, test_neg, neg_failed ? "FAILED" : "SUCCESS");
    printf(" POS TEST: %d of %d - %s\n", test_pos - pos_failed, test_pos, pos_failed ? "FAILED" : "SUCCESS");
}

int main()
{
    int failed_tests = 0;

    failed_tests += tests_node_create();
    failed_tests += tests_list_free();
    failed_tests += tests_list_push();

    failed_tests += tests_comparator();
    failed_tests += tests_find();
    failed_tests += tests_pop_front();
    failed_tests += tests_pop_back();
    failed_tests += tests_insert();

    failed_tests += tests_append();
    failed_tests += tests_sort();

    failed_tests += tests_check_file();
    failed_tests += tests_check_argc();
    failed_tests += tests_str_not_only_spaces();

    failed_tests += tests_allocate_and_free_country();
    failed_tests += tests_allocate_and_free_str();

    failed_tests += tests_default_country();
    failed_tests += tests_default_array_country();

    failed_tests += tests_get_size_string();
    failed_tests += tests_get_size_struct();

    failed_tests += tests_fread_name_str();
    failed_tests += tests_fread_country_info();
    failed_tests += tests_fread_countries();

    return failed_tests;
}