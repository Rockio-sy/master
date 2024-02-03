#include "check_memory.h"

void default_usual_matrix(matrix_t *matrix);

int tests_allocate_and_free_matrix(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 2, test_pos = 2;
    {
        matrix_t matrix;
        default_usual_matrix(&matrix);
        matrix.n = 5;
        matrix.m = 6;
        matrix.matrix = (double **) allocate_matrix_third(matrix.n, matrix.m);
        if (matrix.matrix == NULL)
            pos_cnt++;

        free_matrix_third(&matrix.matrix);
        if (matrix.matrix != NULL)
            pos_cnt++;

        matrix.n = 0;
        matrix.m = 0;
        matrix.matrix = (double **) allocate_matrix_third(0, 0);
        if (matrix.matrix != NULL)
            neg_cnt++;

        free_matrix_third(&matrix.matrix);
        if (matrix.matrix != NULL)
            neg_cnt++;
    }

    printf("===%s:\n -Негативные тесты: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS\n");

    return neg_cnt + pos_cnt;
}

