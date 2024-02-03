#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <stdio.h>

#include "matrix.h"
#include "my_time.h"

#define INCORRECT_INPUT 1

#define EXISTING_ELEMENT_ERROR 3
#define INVALID_FILE 4
#ifndef MATRIX_H
#define DIFFERENT_SIZE 5
#define ALLOC_ERROR 2
#endif

typedef struct
{
    size_t nrows; // Количество строк
    size_t ncols; // Количество столбцов
    size_t nelems; // Количество ненулевых элементов
    
    int *A; // вектор A содержит значения ненулевых элементов;
    size_t *IA; // вектор IA содержит номера строк для элементов вектора A;
    size_t *JA; // вектор, в элементе Nk которого находится номер компонент, с которых начинается описание столбца Nk
} sparse_matrix_t;

int sparse_matrix_input(sparse_matrix_t *sparse_matrix);

int sparse_matrix_alloc(sparse_matrix_t *sparse_matrix);

void sparse_matrix_free(sparse_matrix_t *sparse_matrix);

int sparse_matrix_to_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix);

int sparse_matrix_fscan(sparse_matrix_t *sparse_matrix, FILE *f);

int sparse_matrices_add(sparse_matrix_t *matrix_res, sparse_matrix_t *matrix_1, sparse_matrix_t *matrix_2);

int time_sparse_matrices_add(microsecond_t *time, sparse_matrix_t *matrix_res, sparse_matrix_t *matrix_1, sparse_matrix_t *matrix_2);

void sparse_matrix_output(sparse_matrix_t *sparse_matrix);

size_t sparse_matrix_size(sparse_matrix_t *sparse_matrix);

#endif
