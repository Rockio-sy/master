#include "memory_matrix.h"

double **allocate_matrix_third(int n, int m)
{
    double **data = NULL;
    if (n > 0 && m > 0)
    {
        data = malloc(n * sizeof(double *) + n * m * sizeof(double));
        if (data != NULL)
        {
            for (int i = 0; i < n; i++)
                *(data + i) = (double *) ((char *) data + n * sizeof(double *) + i * m * sizeof(double));
        }
    }

    return data;
}

void free_matrix_third(double ***data)
{
    if (data != NULL)
    {
        free(*data);
        *data = NULL;
    }
}