#include "check_sort.h"

static int sorted[] =     {-234,-3, -2, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 940};
static int unsorted[] = {1, 9, 8, 7, -3, -234, 0, 940, -2, 2, 4, 3, 6, 5};
static int same_data[] =  {1, 1, 1, 1, 1, 1};
static int copy_same_data[] =  {1, 1, 1, 1, 1, 1};

START_TEST(mysort_unsorted_data)
{
    ck_assert_mem_ne(sorted, unsorted, sizeof(sorted) / sizeof(sorted[0]));
    mysort(unsorted, sizeof(unsorted) / sizeof(unsorted[0]), sizeof(unsorted[0]), cmp_int);
    ck_assert_mem_eq(sorted, unsorted, sizeof(sorted) / sizeof(sorted[0]));
}
END_TEST

START_TEST(mysort_sorted_data)
{
    mysort(same_data, sizeof(same_data) / sizeof(same_data[0]), sizeof(same_data[0]), cmp_int);
    ck_assert_mem_eq(copy_same_data, same_data, sizeof(copy_same_data) / sizeof(copy_same_data[0]));
}
END_TEST

START_TEST(compare_more_zero)
{
    int p = 25;
    int q = 10;
    int result = cmp_int(&p, &q);
    ck_assert(result > 0);
}
END_TEST

START_TEST(compare_below_zero)
{
    int p = 5;
    int q = 10;
    int result = cmp_int(&p, &q);
    ck_assert(result < 0);
}
END_TEST

START_TEST(compare_eq_zero)
{
    int p = 10;
    int q = 10;
    int result = cmp_int(&p, &q);
    ck_assert(result == 0);
}
END_TEST

Suite *sort_suite(void)
{
    Suite *st_sort;
    TCase *tc_pos;

    st_sort = suite_create("_MYSORT_");

    tc_pos = tcase_create("_POS_TEST_");
    tcase_add_test(tc_pos, mysort_unsorted_data);
    tcase_add_test(tc_pos, mysort_sorted_data);
    suite_add_tcase(st_sort, tc_pos);
    return st_sort;
}

Suite *cmp_int_suite(void)
{
    Suite *st_cmp;
    TCase *tc_pos;

    st_cmp = suite_create("_CMP_INT_");

    tc_pos = tcase_create("_POS_TEST_");
    tcase_add_test(tc_pos, compare_more_zero);
    tcase_add_test(tc_pos, compare_below_zero);
    tcase_add_test(tc_pos, compare_eq_zero);
    suite_add_tcase(st_cmp, tc_pos);
    return st_cmp;
}