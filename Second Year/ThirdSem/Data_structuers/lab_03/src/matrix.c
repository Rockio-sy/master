#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "my_time.h"

void matrix_free(matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->nrows; i++)
        free(matrix->data[i]);
    free(matrix->data);
}

void matrix_output(matrix_t *matrix)
{
    for (size_t i = 0; i < matrix->nrows; i++)
    {
        for (size_t j = 0; j < matrix->ncols; j++)
            printf("%d ", matrix->data[i][j]);
        printf("\n");
    }
}

int matrices_add(matrix_t *matrix_res, matrix_t *matrix_1, matrix_t *matrix_2)
{
    if (matrix_1->nrows != matrix_2->nrows || matrix_1->ncols != matrix_2->ncols)
        return DIFFERENT_SIZE;
        
    matrix_res->ncols = matrix_1->ncols;
    matrix_res->nrows = matrix_1->nrows;

    if (matrix_alloc(matrix_res) == ALLOC_ERROR)
        return ALLOC_ERROR;

    for (size_t i = 0; i < matrix_res->nrows; i++)
        for (size_t j = 0; j < matrix_res->ncols; j++)
            matrix_res->data[i][j] = matrix_1->data[i][j] + matrix_2->data[i][j];

    return EXIT_SUCCESS;
}

int matrix_alloc(matrix_t *matrix)
{
    matrix->data = calloc(matrix->nrows, sizeof(int *));
    for (size_t i = 0; i < matrix->nrows; i++)
        if (!(matrix->data[i] = malloc(matrix->ncols * sizeof(int))))
        {
            matrix_free(matrix);
            return ALLOC_ERROR;
        }

    return EXIT_SUCCESS;
}

int time_matrices_add(microsecond_t *time, matrix_t *matrix_res, matrix_t *matrix_1, matrix_t *matrix_2)
{
    microsecond_t tbeg = microseconds_now();
    int rc = matrices_add(matrix_res, matrix_1, matrix_2);
    microsecond_t tend = microseconds_now();
    *time = tend - tbeg;
    return rc;
}

size_t matrix_size(matrix_t *matrix)
{
    return sizeof(int) * matrix->nrows * matrix->ncols;
}