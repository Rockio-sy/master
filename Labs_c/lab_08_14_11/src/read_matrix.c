#include "read_matrix.h"

void default_usual_matrix(matrix_t *matrix)
{
    matrix->matrix = NULL;
    matrix->n = 0;
    matrix->m = 0;
}

int fread_usual_matrix(FILE *f, matrix_t *matrix)
{
    int rc = EXIT_SUCCESS;
    if (f == NULL || matrix->n != 0 || matrix->m != 0)
        rc = PARAMS_ERROR;
    else
    {
        if (fscanf(f, "%d %d", &matrix->n, &matrix->m) != 2)
        {
            matrix->n = 0;
            matrix->m = 0;
            rc = INVALID_ERROR;
        }
        else if (matrix->n <= 0)
        {
            matrix->n = 0;
            matrix->m = 0;
            rc = SIZE_N_ERROR;
        }
        else if (matrix->m <= 0)
        {
            matrix->n = 0;
            matrix->m = 0;
            rc = SIZE_M_ERROR;
        }
        else
        {
            matrix->matrix = (double **) allocate_matrix_third(matrix->n, matrix->m);
            if (!matrix->matrix)
                rc = MEMORY_ERROR;
            else
            {
                int result = 0;
                for (int i = 0; i < matrix->n && rc == 0; i++)
                    for (int j = 0; j < matrix->m && rc == 0; j++)
                    {
                        result = fscanf(f, "%lf", *(matrix->matrix + i) + j);
                        if (result == 0)
                            rc = INVALID_ERROR;
                        else if (result == -1)
                            rc = MATRIX_DATA_EMPTY;
                    }
            }
            double buff;
            if (f != stdin && fscanf(f, "%lf", &buff) == 1)
                rc = MATRIX_DATA_OVERFLOW;
        }
    }

    return rc;
}