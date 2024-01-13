#include "check_read.h"

#define UNIT_TESTS_FILE "unit_test.txt"
#define WRITE_SEQUENCE(fd, sequence) \
    rewind((fd));                    \
    fprintf((fd), sequence);         \
    rewind((fd))

int tests_default_usual_matrix(void)
{
    int pos_cnt = 0, test_pos = 1;

    matrix_t matrix;
    default_usual_matrix(&matrix);

    if (matrix.matrix != NULL || matrix.n != 0 || matrix.m != 0)
        pos_cnt++;

    printf("===%s:\n", __func__);
    printf(" -Позитивные тесты: %d of %d - %s\n", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

int tests_read_matrix(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 11, test_pos = 2;
    // PARAMS_ERROR
    {
        int rc = EXIT_SUCCESS;

        matrix_t matrix;
        default_usual_matrix(&matrix);

        rc = fread_usual_matrix(NULL, &matrix);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        matrix.n = 1;
        matrix.m = 1;

        FILE *f = fopen(UNIT_TESTS_FILE, "w+");

        rc = fread_usual_matrix(f, &matrix);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    // SIZE_ERRORS
    {
        int rc = EXIT_SUCCESS;
        FILE *f = fopen(UNIT_TESTS_FILE, "w+");

        matrix_t matrix;
        default_usual_matrix(&matrix);

        WRITE_SEQUENCE(f, "a 2\n"
                                  "1 2\n"
                                  "2 3\n");

        rc = fread_usual_matrix(f, &matrix);
        if (rc != INVALID_ERROR || matrix.matrix != NULL)
            neg_cnt++;

        WRITE_SEQUENCE(f, "2 a\n"
                          "1 2\n"
                          "2 3\n");
        rc = fread_usual_matrix(f, &matrix);
        if (rc != INVALID_ERROR || matrix.matrix != NULL)
            neg_cnt++;

        WRITE_SEQUENCE(f, "0 2\n"
                          "1 2\n"
                          "2 3\n");

        rc = fread_usual_matrix(f, &matrix);
        if (rc != SIZE_N_ERROR || matrix.matrix != NULL)
            neg_cnt++;

        WRITE_SEQUENCE(f, "-2 2\n"
                          "1 2\n"
                          "2 3\n");

        rc = fread_usual_matrix(f, &matrix);
        if (rc != SIZE_N_ERROR || matrix.matrix != NULL)
            neg_cnt++;

        WRITE_SEQUENCE(f, "2 0\n"
                          "1 2\n"
                          "2 3\n");

        rc = fread_usual_matrix(f, &matrix);
        if (rc != SIZE_M_ERROR || matrix.matrix != NULL)
            neg_cnt++;

        WRITE_SEQUENCE(f, "2 -2\n"
                          "1 2\n"
                          "2 3\n");

        rc = fread_usual_matrix(f, &matrix);
        if (rc != SIZE_M_ERROR || matrix.matrix != NULL)
            neg_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    // MATRIX_DATA_EMPTY
    {
        int rc = EXIT_SUCCESS;
        FILE *f = fopen(UNIT_TESTS_FILE, "w+");

        matrix_t matrix;
        default_usual_matrix(&matrix);

        WRITE_SEQUENCE(f, "2 2\n");

        rc = fread_usual_matrix(f, &matrix);
        if (rc != MATRIX_DATA_EMPTY)
            neg_cnt++;

        free_matrix_third(&matrix.matrix);
        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    // MATRIX_DATA_OVERFLOW
    {
        int rc = EXIT_SUCCESS;
        FILE *f = fopen(UNIT_TESTS_FILE, "w+");

        matrix_t matrix;
        default_usual_matrix(&matrix);

        WRITE_SEQUENCE(f, "2 2\n"
                          "1 2\n"
                          "2 4 5\n");

        rc = fread_usual_matrix(f, &matrix);
        if (rc != MATRIX_DATA_OVERFLOW)
            neg_cnt++;

        free_matrix_third(&matrix.matrix);
        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    // INVALID_ERROR
    {
        int rc = EXIT_SUCCESS;
        FILE *f = fopen(UNIT_TESTS_FILE, "w+");

        matrix_t matrix;
        default_usual_matrix(&matrix);

        WRITE_SEQUENCE(f, "2 2\n"
                          "1 2\n"
                          "2 a\n");

        rc = fread_usual_matrix(f, &matrix);
        if (rc != INVALID_ERROR)
            neg_cnt++;

        free_matrix_third(&matrix.matrix);
        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    // POSITIVE_1
    {
        int rc = EXIT_SUCCESS;
        FILE *f = fopen(UNIT_TESTS_FILE, "w+");

        matrix_t matrix;
        default_usual_matrix(&matrix);

        WRITE_SEQUENCE(f, "4 4\n"
                          "1 2 3 4\n"
                          "1 2 3 4\n"
                          "1 2 3 4\n"
                          "1 2 3 4\n");

        rc = fread_usual_matrix(f, &matrix);
        if (rc != EXIT_SUCCESS || matrix.n != 4 || matrix.m != 4)
            pos_cnt++;

        free_matrix_third(&matrix.matrix);
        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    // POSITIVE_1
    {
        int rc = EXIT_SUCCESS;
        FILE *f = fopen(UNIT_TESTS_FILE, "w+");

        matrix_t matrix;
        default_usual_matrix(&matrix);

        WRITE_SEQUENCE(f, "10 10\n"
                          "1 2 3 4 5 6 7 8 9 10\n"
                          "1 2 3 4 5 6 7 8 9 10\n"
                          "1 2 3 4 5 6 7 8 9 10\n"
                          "1 2 3 4 5 6 7 8 9 10\n"
                          "1 2 3 4 5 6 7 8 9 10\n"
                          "1 2 3 4 5 6 7 8 9 10\n"
                          "1 2 3 4 5 6 7 8 9 10\n"
                          "1 2 3 4 5 6 7 8 9 10\n"
                          "1 2 3 4 5 6 7 8 9 10\n"
                          "1 2 3 4 5 6 7 8 9 10\n");

        rc = fread_usual_matrix(f, &matrix);

        if (rc != EXIT_SUCCESS || matrix.n != 10 || matrix.m != 10)
            pos_cnt++;

        free_matrix_third(&matrix.matrix);
        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    printf("===%s:\n -Негативные тесты: %d of %d - %s\n", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
    printf(" -Позитивные тесты: %d of %d - %s\n", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return neg_cnt + pos_cnt;
}