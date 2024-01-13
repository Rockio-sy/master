#include "checks.h"

int str_not_only_spaces(char *str)
{
    int res = 0;
    if (str != NULL)
    {
        int i = 0;
        while (str[i] != '\0')
            if (!isspace(str[i++]))
                res = 1;
    }
    return res;
}

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
        if (argc < min || argc > max || action == NULL)
            rc = ARGC_ERROR;
        else
        {
            if (argc == 4 && strcmp("pf", action) != 0 && strcmp("pb", action) != 0 && strcmp("s", action) != 0)
                rc = ACTION_ERROR;
            else if (argc == 5 && strcmp("a", action) != 0 && strcmp("f", action) != 0)
                rc = ACTION_ERROR;
        }
    }

    return rc;
}