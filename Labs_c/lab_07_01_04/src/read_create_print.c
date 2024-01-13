#include "utils.h"
int allocate_arr(int **arr_beg, int n)
{
    int *p = NULL;
    int rc = EXIT_SUCCESS;
    p = malloc(n * sizeof(int));
    if (!p)
        rc = MEMORY_ERR;
    else
        *arr_beg = p;
    return rc;
}

void free_arr(int **arr_beg, int **arr_end)
{
    free(*arr_beg);
    *arr_beg = NULL;
    *arr_end = NULL;
}

int read_array(FILE *f, int *arr, size_t n)
{
    int rc = EXIT_SUCCESS;
    if (f == NULL || arr == NULL || n <= 0)
        rc = PARAMS_ERR;
    else
    {
        for (size_t i = 0; i < n && rc == 0; i++)
            if (fscanf(f, "%d", arr + i) != 1)
                rc = EXIT_FAILURE;
    }
    return rc;
}

int get_count_elements(FILE *f, int *count)
{
    int rc = EXIT_SUCCESS, i = 0, buff;
    while ((rc = fscanf(f, "%d", &buff)) == 1)
        i++;
    if (rc == 0)
        rc = FILE_IS_INCORRECT;
    else if (i == 0)
        rc = DATA_IS_EMPTY;
    else
    {
        *count = i;
        rc = EXIT_SUCCESS;
    }
    return rc;
}

int create_array(FILE *f, int **arr, size_t *n)
{
    int rc = EXIT_SUCCESS;
    if (f == NULL)
        rc = PARAMS_ERR;
    else
    {
        int *p = NULL, count = 0;
        rc = get_count_elements(f, &count);
        if (rc == EXIT_SUCCESS)
        {
            rc = allocate_arr(&p, count);
            if (rc == EXIT_SUCCESS)
            {
                rewind(f);
                rc = read_array(f, p, count);
                if (rc == EXIT_SUCCESS)
                {
                    *arr = p;
                    *n = count;
                }
                else
                {
                    free(p);
                    p = NULL;
                }
            }
        }
    }
    return rc;
}

void fprint(FILE *f, const int *arr_beg, const int *arr_end)
{
    for (size_t i = 0; i < arr_end - arr_beg; i++)
        fprintf(f, "%d ", *(arr_beg + i));
}
