#include "read_action_and_num.h"

int read_action(int *action)
{
    int rc = EXIT_SUCCESS;
    char *buff = NULL;
    if (action == NULL)
        rc = PARAMS_ERROR;
    else
    {
        buff = allocate_malloc_string(LEN_ACTION + 2);
        if (buff == NULL)
            rc = MEMORY_ERROR;
        else
        {
            if (fgets(buff, LEN_ACTION + 2, stdin) == NULL)
                rc = ACTION_STR_EMPTY;
            buff[strlen(buff) - 1] = '\0';
            if (strlen(buff) > LEN_ACTION - 1)
                rc = ACTION_STR_ERROR;
            else if (strlen(buff) < 1)
                rc = ACTION_STR_EMPTY;
            else
            {
                if (!strcmp(buff, "out"))
                    *action = OUT;
                else if (!strcmp(buff, "mul"))
                    *action = MUL;
                else if (!strcmp(buff, "sqr"))
                    *action = SQR;
                else if (!strcmp(buff, "div"))
                    *action = DIV;
                else
                    rc = ACTION_NOT_FOUND;
            }
        }
    }

    free_malloc_string(&buff);

    return rc;
}

int read_num(int *num)
{
    int rc = EXIT_SUCCESS;
    if (num == NULL)
        rc = PARAMS_ERROR;
    else
    {
        if (scanf("%d", num) != 1)
            rc = INVALID_ERROR;
        else if (*num < 0)
            rc = NEGATIVE_NUM;
    }
    return rc;
}