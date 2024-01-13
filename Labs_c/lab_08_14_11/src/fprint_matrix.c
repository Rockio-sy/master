#include "fprint_matrix.h"

void fprint_usual_matrix(FILE *f, const matrix_t *matrix)
{
    fprintf(f, "%d %d\n", matrix->n, matrix->m);
    for (int i = 0; i < matrix->n; i++)
    {
        for (int j = 0; j < matrix->m; j++)
            fprintf(f, "%.6lf ", matrix->matrix[i][j]);
        fprintf(f, "\n");
    }
}