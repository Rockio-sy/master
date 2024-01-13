#include "check_read.h"
#include "check_sort.h"
#include "check_filter.h"

int main(void)
{
    int failed_tests = 0;
    SRunner *run_func = NULL;

    run_func = srunner_create(read_array_suite());
    srunner_run_all(run_func, CK_VERBOSE);
    failed_tests += srunner_ntests_failed(run_func);
    srunner_free(run_func);
    run_func = NULL;

    run_func = srunner_create(create_array_suite());
    srunner_run_all(run_func, CK_VERBOSE);
    failed_tests += srunner_ntests_failed(run_func);
    srunner_free(run_func);
    run_func = NULL;

    run_func = srunner_create(sort_suite());
    srunner_run_all(run_func, CK_VERBOSE);
    failed_tests += srunner_ntests_failed(run_func);
    srunner_free(run_func);
    run_func = NULL;

    run_func = srunner_create(cmp_int_suite());
    srunner_run_all(run_func, CK_VERBOSE);
    failed_tests += srunner_ntests_failed(run_func);
    srunner_free(run_func);
    run_func = NULL;

    run_func = srunner_create(filter_suite());
    srunner_run_all(run_func, CK_VERBOSE);
    failed_tests += srunner_ntests_failed(run_func);
    srunner_free(run_func);
    run_func = NULL;

    run_func = srunner_create(calc_avg_suite());
    srunner_run_all(run_func, CK_VERBOSE);
    failed_tests += srunner_ntests_failed(run_func);
    srunner_free(run_func);
    run_func = NULL;

    return (failed_tests == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}