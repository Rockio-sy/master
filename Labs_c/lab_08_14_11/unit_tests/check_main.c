#include "check_memory.h"
#include "check_swap.h"
#include "check_math_operations.h"
#include "check_read.h"

int main(void)
{
    int failed_tests = 0;

    failed_tests += tests_allocate_and_free_matrix();

    failed_tests += tests_default_usual_matrix();
    failed_tests += tests_read_matrix();

    failed_tests += tests_copy_matrix();

    failed_tests += tests_sum_matrix();

    failed_tests += tests_multiplication_matrix();

    failed_tests += tests_det_matrix();
    failed_tests += tests_check_degenerate_matrix();
    failed_tests += tests_zeroing_corners();
    failed_tests += test_gaussian_inverse_matrix();

    failed_tests += tests_swap_double_el();
    failed_tests += tests_swap_column();

    return failed_tests;
}