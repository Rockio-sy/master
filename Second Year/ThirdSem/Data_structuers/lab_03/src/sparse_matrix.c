#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sparse_matrix.h"
#include "array.h"
#include "matrix.h"
#include "my_time.h"

int sparse_matrix_input(sparse_matrix_t *sparse_matrix)
{
    printf("Введите количество строк и столбцов матрицы:\n");
    if (scanf("%zu %zu", &sparse_matrix->nrows, &sparse_matrix->ncols) != 2)
        return INCORRECT_INPUT;
    printf("Введите количество ненулевых элементов:\n");
    if (scanf("%zu", &sparse_matrix->nelems) != 1)
        return INCORRECT_INPUT;
        
    if (sparse_matrix_alloc(sparse_matrix) == ALLOC_ERROR)
        return ALLOC_ERROR;

    int elem;
    size_t row, col;
    for (size_t nelems = 0; nelems < sparse_matrix->nelems; nelems++)
    {

        printf("Введите номер строки и столбца (с нуля), в которых будет расположен ненулевой элемент:\n");
        if (scanf("%zu %zu", &row, &col) != 2 || row >= sparse_matrix->nrows || col >= sparse_matrix->ncols)
        {
            sparse_matrix_free(sparse_matrix);
            return INCORRECT_INPUT;
        }

        printf("Введите ненулевой элемент:\n");
        if (scanf("%d", &elem) != 1)
        {
            sparse_matrix_free(sparse_matrix);
            return INCORRECT_INPUT;
        }
        
        int is_put = 0;
        for (size_t i = sparse_matrix->JA[col]; i < sparse_matrix->JA[col + 1] && ! is_put; i++)
        {
            if (row == sparse_matrix->IA[i])
                return EXISTING_ELEMENT_ERROR;
            if (row < sparse_matrix->IA[i])
            {
                is_put = 1;
                size_t_array_insert(sparse_matrix->IA, nelems, row, i);
                int_array_insert(sparse_matrix->A, nelems, elem, i);
            }
        }
        if (! is_put)
        {
            is_put = 1;
            size_t_array_insert(sparse_matrix->IA, nelems, row, sparse_matrix->JA[col + 1]);
            int_array_insert(sparse_matrix->A, nelems, elem, sparse_matrix->JA[col + 1]);
        }

        for (size_t j = col + 1; j <= sparse_matrix->ncols; j++)
            (sparse_matrix->JA[j])++;
    }

    return EXIT_SUCCESS;
}

int sparse_matrix_alloc(sparse_matrix_t *sparse_matrix)
{
    if (! (sparse_matrix->A = malloc(sizeof(int) * sparse_matrix->nelems)))
        return ALLOC_ERROR;

    if (! (sparse_matrix->IA = malloc(sizeof(size_t) * sparse_matrix->nelems)))
    {
        free(sparse_matrix->A);
        return ALLOC_ERROR;
    }

    if (! (sparse_matrix->JA = calloc((sparse_matrix->ncols + 1), sizeof(size_t))))
    {
        free(sparse_matrix->A);
        free(sparse_matrix->IA);
        return ALLOC_ERROR;
    }

    return EXIT_SUCCESS;
}

void sparse_matrix_free(sparse_matrix_t *sparse_matrix)
{
    free(sparse_matrix->A);
    free(sparse_matrix->IA);
    free(sparse_matrix->JA);
}

int sparse_matrix_to_matrix(matrix_t *matrix, sparse_matrix_t *sparse_matrix)
{
    matrix->nrows = sparse_matrix->nrows;
    matrix->ncols = sparse_matrix->ncols;

    matrix->data = calloc(matrix->nrows, sizeof(int *));
    if (! matrix->data)
        return ALLOC_ERROR;

    for (size_t i = 0; i < matrix->nrows; i++)
    {
        matrix->data[i] = calloc(matrix->ncols, sizeof(int));
        if (! matrix->data[i])
        {
            matrix_free(matrix);
            return ALLOC_ERROR;
        }
    }

    for (size_t j = 0; j < sparse_matrix->ncols; j++)
        for (size_t i = sparse_matrix->JA[j]; i < sparse_matrix->JA[j + 1]; i++)
            matrix->data[sparse_matrix->IA[i]][j] = sparse_matrix->A[i];

    return EXIT_SUCCESS;
}

int sparse_matrix_fscan(sparse_matrix_t *sparse_matrix, FILE *f)
{
    if (fscanf(f, "%zu %zu %zu", &sparse_matrix->nrows, &sparse_matrix->ncols, &sparse_matrix->nelems) != 3)
        return INVALID_FILE;

    if (sparse_matrix_alloc(sparse_matrix) == ALLOC_ERROR)
        return ALLOC_ERROR;
    
    int elem;
    size_t row, col;

    for (size_t nelems = 0; nelems < sparse_matrix->nelems; nelems++)
    {
        if (fscanf(f, "%zu %zu %d", &row, &col, &elem) != 3)
        {
            sparse_matrix_free(sparse_matrix);
            return INVALID_FILE;
        }

        
        int is_put = 0;
        for (size_t i = sparse_matrix->JA[col]; i < sparse_matrix->JA[col + 1] && ! is_put; i++)
        {
            if (row == sparse_matrix->IA[i])
            {
                sparse_matrix_free(sparse_matrix);
                return EXISTING_ELEMENT_ERROR;
            }
            if (row < sparse_matrix->IA[i])
            {
                is_put = 1;
                size_t_array_insert(sparse_matrix->IA, nelems, row, i);
                int_array_insert(sparse_matrix->A, nelems, elem, i);
            }
        }
        if (! is_put)
        {
            is_put = 1;
            size_t_array_insert(sparse_matrix->IA, nelems, row, sparse_matrix->JA[col + 1]);
            int_array_insert(sparse_matrix->A, nelems, elem, sparse_matrix->JA[col + 1]);
        }

        for (size_t j = col + 1; j <= sparse_matrix->ncols; j++)
            (sparse_matrix->JA[j])++;
    }

    return EXIT_SUCCESS;
}

int sparse_matrices_add(sparse_matrix_t *matrix_res, sparse_matrix_t *matrix_1, sparse_matrix_t *matrix_2)
{
    if (matrix_1->nrows != matrix_2->nrows || matrix_1->ncols != matrix_2->ncols)
        return DIFFERENT_SIZE;

    matrix_res->ncols = matrix_1->ncols;
    matrix_res->nrows = matrix_1->nrows;

    matrix_res->nelems = matrix_1->nelems + matrix_2->nelems >= matrix_1->nrows * matrix_1->ncols \
                            ? matrix_1->ncols * matrix_1->nrows : matrix_1->nelems + matrix_2->nelems;

    if (sparse_matrix_alloc(matrix_res) == ALLOC_ERROR)
        return ALLOC_ERROR;

    size_t nelems = 0;

    for (size_t col = 0; col < matrix_res->ncols; col++)
    {
        size_t ja_add = 0;
        for (size_t i1 = matrix_1->JA[col]; i1 < matrix_1->JA[col + 1]; i1++)
        {   
            matrix_res->IA[nelems] = matrix_1->IA[i1];
            matrix_res->A[nelems] = matrix_1->A[i1];
            nelems++;
            ja_add++;
        }

        for (size_t i2 = matrix_2->JA[col]; i2 < matrix_2->JA[col + 1]; i2++)
        {
            int is_added = 0;
            for (size_t ires = matrix_res->JA[col]; ires < nelems && !is_added; ires++)
            {
                if (matrix_2->IA[i2] == matrix_res->IA[ires])
                {
                    matrix_res->A[ires] += matrix_2->A[i2];
                    is_added = 1;
                    if (matrix_res->A[ires] == 0)
                    {
                        memmove(matrix_res->A + ires, matrix_res->A + ires + 1, sizeof(int) * (nelems - ires - 1));
                        memmove(matrix_res->IA + ires, matrix_res->IA + ires + 1, sizeof(size_t) * (nelems - ires - 1));
                        nelems--;
                        ja_add--;
                    }
                }
            }

            if (!is_added)
            {
                matrix_res->IA[nelems] = matrix_2->IA[i2];
                matrix_res->A[nelems] = matrix_2->A[i2];
                nelems++;
                ja_add++;
            }
        }

        for (size_t j = col + 1; j < matrix_res->ncols + 1; j++)
            matrix_res->JA[j] += ja_add;
        ja_add = 0;
    }

    int *ptmp_A = realloc(matrix_res->A, nelems * sizeof(int));
    if (!ptmp_A)
    {
        sparse_matrix_free(matrix_res);
        return ALLOC_ERROR;
    }
    matrix_res->A = ptmp_A;

    size_t *ptmp_IA = realloc(matrix_res->IA, nelems * sizeof(size_t));
    if (!ptmp_IA)
    {
        sparse_matrix_free(matrix_res);
        return ALLOC_ERROR;
    }

    matrix_res->IA = ptmp_IA;
    matrix_res->nelems = nelems;
    
    return EXIT_SUCCESS;
}

int time_sparse_matrices_add(microsecond_t *time, sparse_matrix_t *matrix_res, sparse_matrix_t *matrix_1, sparse_matrix_t *matrix_2)
{
    microsecond_t tbeg = microseconds_now();
    int rc = sparse_matrices_add(matrix_res, matrix_1, matrix_2);
    microsecond_t tend = microseconds_now();
    *time = tend - tbeg;
    return rc;
}

void sparse_matrix_output(sparse_matrix_t *sparse_matrix)
{
    printf("A: ");
    int_array_output(sparse_matrix->A, sparse_matrix->nelems);
    printf("IA: ");
    size_t_array_output(sparse_matrix->IA, sparse_matrix->nelems);
    printf("JA: ");
    size_t_array_output(sparse_matrix->JA, sparse_matrix->ncols + 1);
}

size_t sparse_matrix_size(sparse_matrix_t *sparse_matrix)
{
    return sizeof(size_t) * 3 + sparse_matrix->nelems * (sizeof(int) + sizeof(size_t)) + (sparse_matrix->ncols + 1) * sizeof(size_t);
}