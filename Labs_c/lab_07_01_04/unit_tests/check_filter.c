#include "../inc/check_filter.h"
#include "../inc/key.h"

static int unfiltered[] = {1, 1, 3, 70, 50, 80};
static int filtered[] = {70, 50, 80};
static int same_data[] =  {1, 1, 1, 1, 1, 1};

START_TEST(calc_avg_not_same_data)
{
    int *arr = unfiltered;
    int *arr_end = arr + 6;
    int avr = calc_avg(arr, arr_end);
    ck_assert_int_eq(avr, 34);
}
END_TEST

START_TEST(calc_avg_same_data)
{
    int *arr = same_data;
    int *arr_end = arr + 6;
    int avr = calc_avg(arr, arr_end);
    ck_assert_int_eq(avr, 1);
}
END_TEST

START_TEST(filter_params_err)
{
    int rc;
    int *filter_begin = NULL, *filter_end = NULL;
    int *arr_beg = unfiltered;
    int *arr_end = arr_beg + 6;

    rc = key(NULL, arr_end, &filter_begin, &filter_end);
    ck_assert_int_eq(rc, PARAMS_ERR);
    free(filter_begin);
    filter_begin = NULL;
    filter_end = NULL;

    rc = key(arr_beg, NULL, &filter_begin, &filter_end);
    ck_assert_int_eq(rc, PARAMS_ERR);
    free(filter_begin);
    filter_begin = NULL;
    filter_end = NULL;

    rc = key(arr_beg, arr_end, &arr_beg, &filter_end);
    ck_assert_int_eq(rc, PARAMS_ERR);
    free(filter_begin);
    filter_begin = NULL;
    filter_end = NULL;

    rc = key(arr_beg, arr_end, &filter_begin, &arr_end);
    ck_assert_int_eq(rc, PARAMS_ERR);
    free(filter_begin);
    filter_begin = NULL;
    filter_end = NULL;
}
END_TEST

START_TEST(filter_array_src_empty)
{
    int rc;
    int *filter_begin = NULL, *filter_end = NULL;
    int *arr_beg = unfiltered;
    int *arr_end = arr_beg;
    rc = key(arr_beg, arr_end, &filter_begin, &filter_end);
    ck_assert_int_eq(rc, ARRAY_SRC_EMPTY);
    free(filter_begin);
    filter_begin = NULL;
    filter_end = NULL;
}
END_TEST

START_TEST(filter_array_dst_empty)
{
    int rc;
    int *filter_begin = NULL, *filter_end = NULL;
    int *arr_beg = same_data;
    int *arr_end = (arr_beg + 6);
    rc = key(arr_beg, arr_end, &filter_begin, &filter_end);
    ck_assert_int_eq(rc, ARRAY_DST_EMPTY);
    free(filter_begin);
    filter_begin = NULL;
    filter_end = NULL;
}
END_TEST

START_TEST(filter_unfiltered_array)
{
    int rc;
    int *filter_begin = NULL, *filter_end = NULL;
    int *arr_beg = unfiltered;
    int *arr_end = (arr_beg + 6);
    rc = key(arr_beg, arr_end, &filter_begin, &filter_end);
    ck_assert_int_eq(rc, 0);
    ck_assert_mem_eq(filtered, filter_begin, (filter_end - filter_begin) * sizeof(int));
    free(filter_begin);
    filter_begin = NULL;
    filter_end = NULL;
}
END_TEST

Suite *filter_suite(void)
{
    Suite *st_filter;
    TCase *tc_neg;
    TCase *tc_pos;

    st_filter = suite_create("_KEY_");

    tc_neg = tcase_create("_NEG_TEST_");
    tcase_add_test(tc_neg, filter_params_err);
    tcase_add_test(tc_neg, filter_array_dst_empty);
    tcase_add_test(tc_neg, filter_array_src_empty);
    suite_add_tcase(st_filter, tc_neg);

    tc_pos = tcase_create("_POS_TEST_");
    tcase_add_test(tc_pos, filter_unfiltered_array);
    suite_add_tcase(st_filter, tc_pos);

    return st_filter;
}

Suite *calc_avg_suite(void)
{
    Suite *st_avg;
    TCase *tc_pos;

    st_avg = suite_create("_CALC_AVG_");

    tc_pos = tcase_create("_POS_TEST_");
    tcase_add_test(tc_pos, calc_avg_not_same_data);
    tcase_add_test(tc_pos, calc_avg_same_data);
    suite_add_tcase(st_avg, tc_pos);

    return st_avg;
}