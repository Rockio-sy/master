#include "checks.h"

int check_file(FILE *f)
{
    int rc = EXIT_SUCCESS;
    if (f == NULL)
        rc = FILE_NOT_FOUND;
    else
    {
        long size;
        fseek(f, 0, SEEK_END);
        size = ftell(f);
        if (size == 0)
        {
            rc = FILE_IS_EMPTY;
            fclose(f);
        }
        else
            fseek(f, 0, SEEK_SET);
    }

    return rc;
}

int check_argc(int argc, char *action, int min, int max)
{
    int rc = EXIT_SUCCESS;
    if (argc <= 0 || min <= 0 || max <= 0 || min > max)
        rc = PARAMS_ERROR;
    else
    {
        if (argc < min || argc > max)
            rc = ARGC_ERROR;
        else if ((strcmp(action, "a") != 0 && strcmp(action, "m") != 0 && argc == SUM_OR_MULPTI) || (strcmp(action, "o") != 0 && argc == SPECIAL))
            rc = ACTION_ERROR;
    }
    
    return rc;
}

int check_matrix_params(const matrix_t *matrix)
{
    int rc = EXIT_SUCCESS;
    if (matrix->matrix != NULL || matrix->n != 0 || matrix->n != 0)
        rc = EXIT_FAILURE;

    return rc;
}
