#include "copy_matrix.h"

void copy_matrix(matrix_t *dst, const matrix_t *src)
{
    dst->n = src->n;
    dst->m = src->m;

    for (int i = 0; i < src->n; i++)
        for (int j = 0; j < src->m; j++)
            dst->matrix[i][j] = src->matrix[i][j];
}