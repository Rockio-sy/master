#include "sum_matrix.h"

int sum_usual_matrix(matrix_t *result, const matrix_t *f_summand, const matrix_t *s_summand)
{
    int rc = EXIT_SUCCESS;
    if (check_matrix_params(result) || !check_matrix_params(f_summand) || !check_matrix_params(s_summand))
        return PARAMS_ERROR;
    else
    {
        if (f_summand->n != s_summand->n || f_summand->m != s_summand->m)
            rc = SUM_ERROR;
        else
        {
            result->n = f_summand->n;
            result->m = f_summand->m;
            result->matrix = (double **) allocate_matrix_third(result->n, result->m);
            if (!result->matrix)
                rc = MEMORY_ERROR;
            else
            {
                for (int i = 0; i < result->n; i++)
                    for (int j = 0; j < result->m; j++)
                        result->matrix[i][j] = f_summand->matrix[i][j] + s_summand->matrix[i][j];
            }
        }
    }

    return rc;
}
