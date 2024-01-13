#include "check_read.h"

#define UNIT_TESTS_FILE "unit_test.txt"
#define WRITE_SEQUENCE(fd, sequence) \
    rewind((fd));                    \
    fprintf((fd), sequence);         \
    rewind((fd));

// CREATE_ARRAY TESTING

START_TEST(create_array_params_err)
{
    FILE *f = fopen(UNIT_TESTS_FILE, "w+");
    int rc;
    int *array = NULL;
    size_t n = 0;

    rc = create_array(NULL, &array, &n);
    ck_assert_int_eq(rc, PARAMS_ERR);
    free(array);
    array = NULL;

    fclose(f);
    remove(UNIT_TESTS_FILE);
}
END_TEST

START_TEST(create_array_file_is_incorrect)
{
    FILE *f = fopen(UNIT_TESTS_FILE, "w+");
    int rc;
    int *array = NULL;
    size_t n = 0;

    WRITE_SEQUENCE(f, "1 2 3 a 5");
    rc = create_array(f, &array, &n);
    ck_assert_int_eq(rc, FILE_IS_INCORRECT);
    free(array);
    array = NULL;

    WRITE_SEQUENCE(f, "1 2 3 4 5 a");
    rc = create_array(f, &array, &n);
    ck_assert_int_eq(rc, FILE_IS_INCORRECT);
    free(array);
    array = NULL;
    fclose(f);
    remove(UNIT_TESTS_FILE);
}
END_TEST

START_TEST(create_array_file_is_empty)
{
    FILE *f = fopen(UNIT_TESTS_FILE, "w+");
    int rc;
    int *array = NULL;
    size_t n = 0;

    WRITE_SEQUENCE(f, " ");
    rc = create_array(f, &array, &n);
    ck_assert_int_eq(rc, DATA_IS_EMPTY);
    free(array);
    array = NULL;

    fclose(f);
    remove(UNIT_TESTS_FILE);
}

START_TEST(create_array_correct_file)
{
    FILE *f = fopen(UNIT_TESTS_FILE, "w+");
    int rc;
    int *array = NULL;
    size_t n = 0;

    WRITE_SEQUENCE(f, "23 5 6 7 8 9");
    rc = create_array(f, &array, &n);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(n, 6);
    ck_assert_int_eq(*(array + 0), 23);
    ck_assert_int_eq(*(array + 1), 5);
    ck_assert_int_eq(*(array + 2), 6);
    ck_assert_int_eq(*(array + 3), 7);
    ck_assert_int_eq(*(array + 4), 8);
    ck_assert_int_eq(*(array + 5), 9);

    free(array);
    array = NULL;

    fclose(f);
    remove(UNIT_TESTS_FILE);
}
END_TEST

// READ_ARRAY TESTING
START_TEST(read_array_params_err)
{
    int rc = EXIT_SUCCESS;
    FILE *f = fopen(UNIT_TESTS_FILE, "w+");
    WRITE_SEQUENCE(f, "1 2 3 4 5");
    int array[5] = { 0 };
    size_t n = 5;
    rc = read_array(NULL, array, n);
    ck_assert_int_eq(rc, PARAMS_ERR);

    rc = read_array(f, NULL, n);
    ck_assert_int_eq(rc, PARAMS_ERR);

    rc = read_array(f, array, 0);
    ck_assert_int_eq(rc, PARAMS_ERR);

    fclose(f);
    remove(UNIT_TESTS_FILE);
}
END_TEST

START_TEST (read_array_incorrect_file)
{
    FILE *f = fopen(UNIT_TESTS_FILE, "w+");
    WRITE_SEQUENCE(f, "1 2 3 a 5");
    int array[5];
    size_t n = 5;
    int rc;
    rc = read_array(f, array, n);
    ck_assert_int_eq(rc, EXIT_FAILURE);
    fclose(f);
    remove(UNIT_TESTS_FILE);
}
END_TEST

START_TEST(read_array_correct_file)
{
    FILE *f = fopen(UNIT_TESTS_FILE, "w+");
    WRITE_SEQUENCE(f, "1 2 3 4 5");
    int array[5];
    size_t n = 5;
    int rc;
    rc = read_array(f, array, n);
    ck_assert_int_eq(rc, EXIT_SUCCESS);
    fclose(f);
    remove(UNIT_TESTS_FILE);
}
END_TEST

Suite *create_array_suite(void)
{
    Suite *st_create_array;
    TCase *tc_neg;
    TCase *tc_pos;

    st_create_array = suite_create("_CREATE_ARRAY_");

    tc_neg = tcase_create("_NEG_TEST_");
    tcase_add_test(tc_neg, create_array_params_err);
    tcase_add_test(tc_neg, create_array_file_is_empty);
    tcase_add_test(tc_neg, create_array_file_is_incorrect);
    suite_add_tcase(st_create_array, tc_neg);

    tc_pos = tcase_create("_POS_TEST_");
    tcase_add_test(tc_pos, create_array_correct_file);
    suite_add_tcase(st_create_array, tc_pos);
    return st_create_array;
}

Suite *read_array_suite(void)
{
    Suite *st_read_array;
    TCase *tc_neg;
    TCase *tc_pos;

    st_read_array = suite_create("_READ_ARRAY_");

    tc_neg = tcase_create("_NEG_TEST_");
    tcase_add_test(tc_neg, read_array_params_err);
    tcase_add_test(tc_neg, read_array_incorrect_file);
    suite_add_tcase(st_read_array, tc_neg);

    tc_pos = tcase_create("_POS_TEST_");
    tcase_add_test(tc_pos, read_array_correct_file);
    suite_add_tcase(st_read_array, tc_pos);
    return st_read_array;
}