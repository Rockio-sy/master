#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include "my_time.h"

#define ALLOC_ERROR 2
#define DIFFERENT_SIZE 5

typedef struct
{
    int **data;

    size_t nrows;
    size_t ncols;
} matrix_t;

void matrix_free(matrix_t *matrix);

void matrix_output(matrix_t *matrix);

int matrices_add(matrix_t *matrix_res, matrix_t *matrix_1, matrix_t *matrix_2);

int matrix_alloc(matrix_t *matrix);

int time_matrices_add(microsecond_t *time, matrix_t *matrix_res, matrix_t *matrix_1, matrix_t *matrix_2);

size_t matrix_size(matrix_t *matrix);

#endif
