#include "check_math_operations.h"

void fprint_usual_matrix(FILE *f, const matrix_t *matrix);
int tests_copy_matrix(void)
{
    int pos_cnt = 0, test_pos = 1;
    {
        int rc = 0;
        matrix_t origin, copy;

        double matrix_full[5][5] = {{1.0, 23.023, 12.45, 12.0, 12.9012},
                                    {4.0, 2312.23, 12.45, 12.0, 12.9012},
                                    {5.0, 231.23, 12.45, 12.0, 12.9012},
                                    {6.0, 29.323, 12.45, 12.0, 12.9012},
                                    {7.0, 23.123, 12.45, 12.0, 12.9012}};
        int n = 5, m = 5;
        origin.n = n;
        origin.m = m;
        copy.n = n;
        copy.m = m;


        origin.matrix = allocate_matrix_third(n, m);
        copy.matrix = allocate_matrix_third(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                origin.matrix[i][j] = matrix_full[i][j];
                copy.matrix[i][j] = 0.0;
            }

        copy_matrix(&copy, &origin);

        for (int i = 0; i < n && !rc; i++)
            for (int j = 0; j < m && !rc; j++)
                if (fabs(origin.matrix[i][j] - copy.matrix[i][j]) > EPS)
                {
                    pos_cnt++;
                    rc = 1;
                }

        free_matrix_third(&origin.matrix);
        free_matrix_third(&copy.matrix);
    }

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS\n");

    return pos_cnt;
}

int tests_sum_matrix(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 4, test_pos = 4;
    // PARAMS_ERROR
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, sum_1, sum_2;
        default_usual_matrix(&sum_1);
        default_usual_matrix(&sum_2);

        result.matrix = allocate_matrix_third(1, 1);
        result.m = 0;
        result.n = 0;

        rc = sum_usual_matrix(&result, &sum_1, &sum_2);
        if (	rc != PARAMS_ERROR)
            neg_cnt++;

        free_matrix_third(&result.matrix);
        result.m = 1;
        result.n = 1;

        rc = sum_usual_matrix(&result, &sum_1, &sum_2);
        if (rc != PARAMS_ERROR)
            neg_cnt++;
    }
    // PARAMS_ERROR
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, sum_1, sum_2;
        default_usual_matrix(&result);
        default_usual_matrix(&sum_1);
        default_usual_matrix(&sum_2);

        rc = sum_usual_matrix(&result, &sum_1, &sum_2);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

    }
    // SUM_ERROR
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, sum_1, sum_2;
        default_usual_matrix(&result);
        default_usual_matrix(&sum_1);
        default_usual_matrix(&sum_2);

        sum_1.n = 5;
        sum_1.m = 5;
        sum_1.matrix = allocate_matrix_third(sum_1.n, sum_1.m);

        sum_2.n = 6;
        sum_2.m = 6;
        sum_2.matrix = allocate_matrix_third(sum_1.n, sum_1.m);

        rc = sum_usual_matrix(&result, &sum_1, &sum_2);
        if (rc != SUM_ERROR || result.matrix != NULL)
            neg_cnt++;

        free_matrix_third(&sum_1.matrix);
        free_matrix_third(&sum_2.matrix);
    }
    // POSITIVE_1
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, sum_1, sum_2;
        default_usual_matrix(&result);
        default_usual_matrix(&sum_1);
        default_usual_matrix(&sum_2);

        sum_1.n = sum_2.n = 5;
        sum_1.m = sum_2.m = 5;

        sum_1.matrix = allocate_matrix_third(sum_1.n, sum_1.m);
        sum_2.matrix = allocate_matrix_third(sum_2.n, sum_2.m);

        for (int i = 0; i < sum_1.n; i++)
            for (int j = 0; j < sum_1.m; j++)
            {
                sum_1.matrix[i][j] = i + j;
                sum_2.matrix[i][j] = -(i + j);
            }

        rc = sum_usual_matrix(&result, &sum_1, &sum_2);
        if (rc == EXIT_SUCCESS)
        {
            int check = 0;
            for (int i = 0; i < sum_1.n && !check; i++)
                for (int j = 0; j < sum_1.m && !check; j++)
                    if (fabs(result.matrix[i][j]) > EPS)
                    {
                        pos_cnt++;
                        check = 1;
                    }
        }
        else
            pos_cnt++;

        free_matrix_third(&result.matrix);
        default_usual_matrix(&result);

        for (int i = 0; i < sum_1.n; i++)
            for (int j = 0; j < sum_1.m; j++)
            {
                sum_1.matrix[i][j] = i + j;
                sum_2.matrix[i][j] = i + j - 2;
            }

        rc = sum_usual_matrix(&result, &sum_1, &sum_2);
        if (rc == EXIT_SUCCESS)
        {
            int check = 0;
            for (int i = 0; i < sum_1.n && !check; i++)
                for (int j = 0; j < sum_1.m && !check; j++)
                    if (fabs(result.matrix[i][j] - ((i + j) * 2 - 2)) > EPS)
                    {
                        pos_cnt++;
                        check = 1;
                    }
        }
        else
            pos_cnt++;

        free_matrix_third(&sum_1.matrix);
        free_matrix_third(&sum_2.matrix);
        free_matrix_third(&result.matrix);
    }
    // POSITIVE_2
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, sum_1, sum_2;
        default_usual_matrix(&result);
        default_usual_matrix(&sum_1);
        default_usual_matrix(&sum_2);

        sum_1.n = sum_2.n = 10;
        sum_1.m = sum_2.m = 15;

        sum_1.matrix = allocate_matrix_third(sum_1.n, sum_1.m);
        sum_2.matrix = allocate_matrix_third(sum_2.n, sum_2.m);

        for (int i = 0; i < sum_1.n; i++)
            for (int j = 0; j < sum_1.m; j++)
            {
                sum_1.matrix[i][j] = i + j;
                sum_2.matrix[i][j] = -(i + j);
            }

        rc = sum_usual_matrix(&result, &sum_1, &sum_2);
        if (rc == EXIT_SUCCESS)
        {
            int check = 0;
            for (int i = 0; i < sum_1.n && !check; i++)
                for (int j = 0; j < sum_1.m && !check; j++)
                    if (fabs(result.matrix[i][j]) > EPS)
                    {
                        pos_cnt++;
                        check = 1;
                    }
        }
        else
            pos_cnt++;

        free_matrix_third(&result.matrix);
        default_usual_matrix(&result);

        for (int i = 0; i < sum_1.n; i++)
            for (int j = 0; j < sum_1.m; j++)
            {
                sum_1.matrix[i][j] = i + j;
                sum_2.matrix[i][j] = i + j - 2;
            }

        rc = sum_usual_matrix(&result, &sum_1, &sum_2);
        if (rc == EXIT_SUCCESS)
        {
            int check = 0;
            for (int i = 0; i < sum_1.n && !check; i++)
                for (int j = 0; j < sum_1.m && !check; j++)
                    if (fabs(result.matrix[i][j] - ((i + j) * 2 - 2)) > EPS)
                    {
                        pos_cnt++;
                        check = 1;
                    }
        }
        else
            pos_cnt++;

        free_matrix_third(&sum_1.matrix);
        free_matrix_third(&sum_2.matrix);
        free_matrix_third(&result.matrix);
    }
    printf("===%s:\n -Негативные тесты: %d of %d - %s\n", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
    printf(" -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS\n");

    return neg_cnt + pos_cnt;
}

int tests_multiplication_matrix(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 4, test_pos = 2;
    // PARAMS_ERROR
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, sum_1, sum_2;
        default_usual_matrix(&sum_1);
        default_usual_matrix(&sum_2);

        result.matrix = allocate_matrix_third(1, 1);
        result.m = 0;
        result.n = 0;

        rc = multiplication_usual_matrix(&result, &sum_1, &sum_2);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        free_matrix_third(&result.matrix);
        result.m = 1;
        result.n = 1;

        rc = multiplication_usual_matrix(&result, &sum_1, &sum_2);
        if (rc != PARAMS_ERROR)
            neg_cnt++;
    }
    // PARAMS_ERROR
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, sum_1, sum_2;
        default_usual_matrix(&result);
        default_usual_matrix(&sum_1);
        default_usual_matrix(&sum_2);

        rc = multiplication_usual_matrix(&result, &sum_1, &sum_2);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

    }
    // MULTI_ERROR
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, sum_1, sum_2;
        default_usual_matrix(&result);
        default_usual_matrix(&sum_1);
        default_usual_matrix(&sum_2);

        sum_1.n = 5;
        sum_1.m = 5;
        sum_1.matrix = allocate_matrix_third(sum_1.n, sum_1.m);

        sum_2.n = 6;
        sum_2.m = 4;
        sum_2.matrix = allocate_matrix_third(sum_1.n, sum_1.m);

        rc = multiplication_usual_matrix(&result, &sum_1, &sum_2);
        if (rc != MULTI_ERROR || result.matrix != NULL)
            neg_cnt++;

        free_matrix_third(&sum_1.matrix);
        free_matrix_third(&sum_2.matrix);
    }
    // POSITIVE_1
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, sum_1, sum_2;
        default_usual_matrix(&result);
        default_usual_matrix(&sum_1);
        default_usual_matrix(&sum_2);

        sum_1.n = sum_2.n = 5;
        sum_1.m = sum_2.m = 5;

        sum_1.matrix = allocate_matrix_third(sum_1.n, sum_1.m);
        sum_2.matrix = allocate_matrix_third(sum_2.n, sum_2.m);

        for (int i = 0; i < sum_1.n; i++)
            for (int j = 0; j < sum_1.m; j++)
            {
                sum_1.matrix[i][j] = i + j;
                sum_2.matrix[i][j] = 0;
            }

        rc = multiplication_usual_matrix(&result, &sum_1, &sum_2);

        if (rc == EXIT_SUCCESS)
        {
            int check = 0;
            for (int i = 0; i < sum_1.n && !check; i++)
                for (int j = 0; j < sum_1.m && !check; j++)
                    if (fabs(result.matrix[i][j]) > EPS)
                    {
                        pos_cnt++;
                        check = 1;
                    }
        }
        else
            pos_cnt++;

        free_matrix_third(&sum_1.matrix);
        free_matrix_third(&sum_2.matrix);
        free_matrix_third(&result.matrix);
    }
    // POSITIVE_2
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, sum_1, sum_2;
        default_usual_matrix(&result);
        default_usual_matrix(&sum_1);
        default_usual_matrix(&sum_2);

        sum_1.n = 6;
        sum_2.n = 5;
        sum_1.m = 5;
        sum_2.m = 7;

        sum_1.matrix = allocate_matrix_third(sum_1.n, sum_1.m);
        sum_2.matrix = allocate_matrix_third(sum_2.n, sum_2.m);

        for (int i = 0; i < sum_1.n; i++)
            for (int j = 0; j < sum_1.m; j++)
                sum_1.matrix[i][j] = i + j;

        for (int i = 0; i < sum_2.n; i++)
            for (int j = 0; j < sum_2.m; j++)
                sum_2.matrix[i][j] = 0;

        rc = multiplication_usual_matrix(&result, &sum_1, &sum_2);

        if (rc == EXIT_SUCCESS)
        {
            int check = 0;
            for (int i = 0; i < result.n && !check; i++)
                for (int j = 0; j < result.m && !check; j++)
                    if (fabs(result.matrix[i][j]) > EPS)
                    {
                        pos_cnt++;
                        check = 1;
                    }
        }
        else
            pos_cnt++;

        free_matrix_third(&sum_1.matrix);
        free_matrix_third(&sum_2.matrix);
        free_matrix_third(&result.matrix);
    }
    printf("===%s:\n -Негативные тесты: %d of %d - %s\n", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
    printf(" -Позитивные тесты: %d of %d - %s\n", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return neg_cnt + pos_cnt;
}

int tests_det_matrix(void)
{
    int pos_cnt = 0, test_pos = 5;

    {
        double res = 0.0;

        matrix_t test;
        default_usual_matrix(&test);

        test.n = 3;
        test.m = 3;

        test.matrix = allocate_matrix_third(test.n, test.m);

        for (int i = 0; i < test.n; i++)
            for (int j = 0; j < test.m; j++)
                test.matrix[i][j] = i + j;

        res = det_matrix(&test);
        if (fabs(res) > EPS)
            pos_cnt++;

        for (int i = 0; i < test.n; i++)
            for (int j = 0; j < test.m; j++)
                test.matrix[i][j] = i;

        res = det_matrix(&test);
        if (fabs(res) > EPS)
            pos_cnt++;

        for (int i = 0; i < test.n; i++)
            for (int j = 0; j < test.m; j++)
                test.matrix[j][i] = i;

        res = det_matrix(&test);
        if (fabs(res) > EPS)
            pos_cnt++;

        for (int i = 0; i < test.n; i++)
            for (int j = 0; j < test.m; j++)
                if (i == 0 && j == 0)
                    test.matrix[j][i] = i + 1;
                else if (j % 2 == 0)
                    test.matrix[j][i] = i + j + 5;
                else
                    test.matrix[j][i] = i + 9.8;

        res = det_matrix(&test);
        if (fabs(res - 11.2) > EPS)
            pos_cnt++;

        for (int i = 0; i < test.n; i++)
            for (int j = 0; j < test.m; j++)
                if (i == 0 && j == 0)
                    test.matrix[j][i] = i + 2;
                else if (j % 2 == 0)
                    test.matrix[j][i] = i + j + 10;
                else
                    test.matrix[j][i] = i + 1.8;

        res = det_matrix(&test);
        if (fabs(res - 81.6) > EPS)
            pos_cnt++;

        free_matrix_third(&test.matrix);
    }

    printf("===%s:\n", __func__);
    printf(" -Позитивные тесты: %d of %d - %s\n", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

int tests_check_degenerate_matrix(void)
{
    int pos_cnt = 0, test_pos = 5;

    {
        int res = 0;
        matrix_t test;
        default_usual_matrix(&test);

        test.n = 3;
        test.m = 3;

        test.matrix = allocate_matrix_third(test.n, test.m);

        for (int i = 0; i < test.n; i++)
            for (int j = 0; j < test.m; j++)
                test.matrix[i][j] = i + j;

        res = check_degenerate_matrix(&test);
        if (res != 1)
            pos_cnt++;

        for (int i = 0; i < test.n; i++)
            for (int j = 0; j < test.m; j++)
                test.matrix[i][j] = i;

        res = check_degenerate_matrix(&test);
        if (res != 1)
            pos_cnt++;

        for (int i = 0; i < test.n; i++)
            for (int j = 0; j < test.m; j++)
                test.matrix[j][i] = i;

        res = check_degenerate_matrix(&test);
        if (res != 1)
            pos_cnt++;

        for (int i = 0; i < test.n; i++)
            for (int j = 0; j < test.m; j++)
                if (i == 0 && j == 0)
                    test.matrix[j][i] = i + 1;
                else if (j % 2 == 0)
                    test.matrix[j][i] = i + j + 5;
                else
                    test.matrix[j][i] = i + 9.8;

        res = check_degenerate_matrix(&test);
        if (res == 1)
            pos_cnt++;

        for (int i = 0; i < test.n; i++)
            for (int j = 0; j < test.m; j++)
                if (i == 0 && j == 0)
                    test.matrix[j][i] = i + 2;
                else if (j % 2 == 0)
                    test.matrix[j][i] = i + j + 10;
                else
                    test.matrix[j][i] = i + 1.8;

        res = check_degenerate_matrix(&test);
        if (res == 1)
            pos_cnt++;

        free_matrix_third(&test.matrix);
    }

    printf("===%s:\n", __func__);
    printf(" -Позитивные тесты: %d of %d - %s\n", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

int tests_zeroing_corners(void)
{
    int pos_cnt = 0, test_pos = 6;
    {
        int rc = 0;

        double result_l[3][4] = {{1, 2, 4, 1},
                                 {0, 1, 4, 2},
                                 {0, 0, 1, 1}};

        double result_u[3][4] = {{1, 0, 0, 1},
                                 {0, 1, 0, -2},
                                 {0, 0, 1, 1}};

        matrix_t slau, origin;
        slau.n = 3;
        slau.m = 4;

        origin.n = origin.m = slau.n;

        slau.matrix = allocate_matrix_third(slau.n, slau.m);
        origin.matrix = allocate_matrix_third(origin.n, origin.m);

        slau.matrix[0][0] = origin.matrix[0][0] = 1;
        slau.matrix[0][1] = origin.matrix[0][1]= 2;
        slau.matrix[0][2] = origin.matrix[0][2]= 4;
        slau.matrix[0][3] = 1;
        slau.matrix[1][0] = origin.matrix[1][0] = 2;
        slau.matrix[1][1] = origin.matrix[1][1] = 3;
        slau.matrix[1][2] = origin.matrix[1][2] = 4;
        slau.matrix[1][3] = 0;
        slau.matrix[2][0] = origin.matrix[2][0] = 5;
        slau.matrix[2][1] = origin.matrix[2][1] = 6;
        slau.matrix[2][2] = origin.matrix[2][2] = 7;
        slau.matrix[2][3] = 0;

        zeroing_the_lower_right_corner(&slau, &origin);

        for (int i = 0; i < slau.n && !rc; i++)
            for (int j = 0; j < slau.m && !rc; j++)
                if (fabs(slau.matrix[i][j] - result_l[i][j]) > EPS)
                {
                    pos_cnt++;
                    rc = 1;
                }

        zeroing_the_upper_left_corner(&slau, &origin);

        for (int i = 0; i < slau.n && !rc; i++)
            for (int j = 0; j < slau.m && !rc; j++)
                if (fabs(slau.matrix[i][j] - result_u[i][j]) > EPS)
                {
                    pos_cnt++;
                    rc = 1;
                }

        free_matrix_third(&slau.matrix);
        free_matrix_third(&origin.matrix);
    }

    {
        int rc = 0;

        double result_l[3][4] = {{1, 2, 4, 0},
                                 {0, 1, 4, -1},
                                 {0, 0, 1, -1.33333333333333315788138}};

        double result_u[3][4] = {{1, 0, 0, -3.33333333333333315788138},
                                 {0, 1, 0, 4.33333333333333315788138},
                                 {0, 0, 1, -1.33333333333333315788138}};

        matrix_t slau, origin;
        slau.n = 3;
        slau.m = 4;

        origin.n = origin.m = slau.n;

        slau.matrix = allocate_matrix_third(slau.n, slau.m);
        origin.matrix = allocate_matrix_third(origin.n, origin.m);

        slau.matrix[0][0] = origin.matrix[0][0] = 1;
        slau.matrix[0][1] = origin.matrix[0][1]= 2;
        slau.matrix[0][2] = origin.matrix[0][2]= 4;
        slau.matrix[0][3] = 0;
        slau.matrix[1][0] = origin.matrix[1][0] = 2;
        slau.matrix[1][1] = origin.matrix[1][1] = 3;
        slau.matrix[1][2] = origin.matrix[1][2] = 4;
        slau.matrix[1][3] = 1;
        slau.matrix[2][0] = origin.matrix[2][0] = 5;
        slau.matrix[2][1] = origin.matrix[2][1] = 6;
        slau.matrix[2][2] = origin.matrix[2][2] = 7;
        slau.matrix[2][3] = 0;

        zeroing_the_lower_right_corner(&slau, &origin);

        for (int i = 0; i < slau.n && !rc; i++)
            for (int j = 0; j < slau.m && !rc; j++)
                if (fabs(slau.matrix[i][j] - result_l[i][j]) > EPS)
                {
                    pos_cnt++;
                    rc = 1;
                }

        zeroing_the_upper_left_corner(&slau, &origin);

        for (int i = 0; i < slau.n && !rc; i++)
            for (int j = 0; j < slau.m && !rc; j++)
                if (fabs(slau.matrix[i][j] - result_u[i][j]) > EPS)
                {
                    pos_cnt++;
                    rc = 1;
                }

        free_matrix_third(&slau.matrix);
        free_matrix_third(&origin.matrix);
    }

    {
        int rc = 0;

        double result_l[3][4] = {{1, 2, 4, 0},
                                 {0, 1, 4, 0},
                                 {0, 0, 1, 0.33333333333333315788138}};

        double result_u[3][4] = {{1, 0, 0, 1.33333333333333315788138},
                                 {0, 1, 0, -1.33333333333333315788138},
                                 {0, 0, 1, 0.33333333333333315788138}};

        matrix_t slau, origin;
        slau.n = 3;
        slau.m = 4;

        origin.n = origin.m = slau.n;

        slau.matrix = allocate_matrix_third(slau.n, slau.m);
        origin.matrix = allocate_matrix_third(origin.n, origin.m);

        slau.matrix[0][0] = origin.matrix[0][0] = 1;
        slau.matrix[0][1] = origin.matrix[0][1]= 2;
        slau.matrix[0][2] = origin.matrix[0][2]= 4;
        slau.matrix[0][3] = 0;
        slau.matrix[1][0] = origin.matrix[1][0] = 2;
        slau.matrix[1][1] = origin.matrix[1][1] = 3;
        slau.matrix[1][2] = origin.matrix[1][2] = 4;
        slau.matrix[1][3] = 0;
        slau.matrix[2][0] = origin.matrix[2][0] = 5;
        slau.matrix[2][1] = origin.matrix[2][1] = 6;
        slau.matrix[2][2] = origin.matrix[2][2] = 7;
        slau.matrix[2][3] = 1;

        zeroing_the_lower_right_corner(&slau, &origin);

        for (int i = 0; i < slau.n && !rc; i++)
            for (int j = 0; j < slau.m && !rc; j++)
                if (fabs(slau.matrix[i][j] - result_l[i][j]) > EPS)
                {
                    pos_cnt++;
                    rc = 1;
                }

        zeroing_the_upper_left_corner(&slau, &origin);

        for (int i = 0; i < slau.n && !rc; i++)
            for (int j = 0; j < slau.m && !rc; j++)
                if (fabs(slau.matrix[i][j] - result_u[i][j]) > EPS)
                {
                    pos_cnt++;
                    rc = 1;
                }

        free_matrix_third(&slau.matrix);
        free_matrix_third(&origin.matrix);
    }
    printf("===%s:\n", __func__);
    printf(" -Позитивные тесты: %d of %d - %s\n", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

int test_gaussian_inverse_matrix(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 7, test_pos = 1;
    //PARAMS_ERROR
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, data;
        default_usual_matrix(&data);

        result.matrix = allocate_matrix_third(1, 1);
        result.m = 0;
        result.n = 0;

        rc = gaussian_inverse_matrix(&result, &data);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        free_matrix_third(&result.matrix);
        result.m = 1;
        result.n = 1;

        rc = gaussian_inverse_matrix(&result, &data);
        if (rc != PARAMS_ERROR)
            neg_cnt++;
    }
    // PARAMS_ERROR
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, data;
        default_usual_matrix(&result);
        default_usual_matrix(&data);

        rc = gaussian_inverse_matrix(&result, &data);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

    }
    // INVERSE_MATRIX_ERROR
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, data;
        default_usual_matrix(&result);
        default_usual_matrix(&data);

        data.n = 3;
        data.m = 4;

        data.matrix = allocate_matrix_third(data.n, data.m);

        rc = gaussian_inverse_matrix(&result, &data);
        if (rc != INVERSE_MATRIX_ERROR || result.matrix != NULL)
            neg_cnt++;

        free_matrix_third(&data.matrix);
    }
    // NON_DEG_ERROR
    {
        int rc = EXIT_SUCCESS;
        matrix_t result, data;
        default_usual_matrix(&result);
        default_usual_matrix(&data);

        data.n = 3;
        data.m = 3;

        data.matrix = allocate_matrix_third(data.n, data.m);

        for (int i = 0; i < data.n; i++)
            for (int j = 0; j < data.n; j++)
                data.matrix[i][j] = i + j;

        rc = gaussian_inverse_matrix(&result, &data);
        if (rc != NON_DEG_ERROR || result.matrix != NULL)
            neg_cnt++;

        for (int i = 0; i < data.n; i++)
            for (int j = 0; j < data.n; j++)
                data.matrix[i][j] = i;

        rc = gaussian_inverse_matrix(&result, &data);
        if (rc != NON_DEG_ERROR || result.matrix != NULL)
            neg_cnt++;

        for (int i = 0; i < data.n; i++)
            for (int j = 0; j < data.n; j++)
                data.matrix[j][i] = i;

        rc = gaussian_inverse_matrix(&result, &data);
        if (rc != NON_DEG_ERROR || result.matrix != NULL)
            neg_cnt++;

        free_matrix_third(&data.matrix);
        free_matrix_third(&result.matrix);
    }
    // POSITIVE_1
    {
        int rc = EXIT_SUCCESS;

        double result_data[3][3] = {{1, -3.33333333333333315788138, 1.33333333333333315788138},
                                    {-2, 4.33333333333333315788138, -1.33333333333333315788138},
                                    {1, -1.33333333333333315788138, 0.33333333333333315788138}};

        matrix_t result, data;
        default_usual_matrix(&result);
        default_usual_matrix(&data);

        data.n = data.m = 3;

        data.matrix = allocate_matrix_third(data.n, data.m);

        data.matrix[0][0] = 1;
        data.matrix[0][1] = 2;
        data.matrix[0][2] = 4;
        data.matrix[1][0] = 2;
        data.matrix[1][1] = 3;
        data.matrix[1][2] = 4;
        data.matrix[2][0] = 5;
        data.matrix[2][1] = 6;
        data.matrix[2][2] = 7;

        rc = gaussian_inverse_matrix(&result, &data);
        if (rc == EXIT_SUCCESS)
        {
            int check = 0;
            for (int i = 0; i < result.n && !check; i++)
                for (int j = 0; j < result.m&& !check; j++)
                    if (fabs(result.matrix[i][j] - result_data[i][j]) > EPS)
                    {
                        pos_cnt++;
                        check = 1;
                    }
        }
        else
            pos_cnt++;

        free_matrix_third(&data.matrix);
        free_matrix_third(&result.matrix);
    }
    printf("===%s:\n -Негативные тесты: %d of %d - %s\n", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
    printf(" -Позитивные тесты: %d of %d - %s\n", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt + neg_cnt;
}
