#include "../inc/check_my_snprintf.h"

int main(void)
{
    int failed_tests = 0;

    failed_tests += test_snprintf_char();
    failed_tests += test_snprintf_string();

    failed_tests += test_snprintf_number_d();
    failed_tests += test_snprintf_number_i();
    failed_tests += test_snprintf_octal_number();

    return failed_tests;
}
