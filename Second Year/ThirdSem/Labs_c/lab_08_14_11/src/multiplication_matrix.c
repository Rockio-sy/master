#include "multiplication_matrix.h"

int multiplication_usual_matrix(matrix_t *result, const matrix_t *multiplicanda, const matrix_t *multiplier)
{
    int rc = EXIT_SUCCESS;
    if (check_matrix_params(result) || !check_matrix_params(multiplicanda) || !check_matrix_params(multiplier))
        rc = PARAMS_ERROR;
    else
    {
        if (multiplicanda->m == multiplier->n && multiplicanda->m > 0 && multiplier->n)
        {
            result->matrix = (double **) allocate_matrix_third(multiplicanda->n, multiplier->m);
            if (result->matrix == NULL)
                rc = MEMORY_ERROR;
            else
            {
                result->n = multiplicanda->n;
                result->m = multiplier->m;
                double multy = 0.0;
                for (int i = 0; i < result->n; i++)
                    for (int j = 0; j < result->m; j++)
                    {
                        for (int k = 0; k < multiplier->n; k++)
                            multy += multiplicanda->matrix[i][k] * multiplier->matrix[k][j];
                        result->matrix[i][j] = multy;
                        multy = 0.0;
                    }
            }
        }
        else
            rc = MULTI_ERROR;
    }

    return rc;
}