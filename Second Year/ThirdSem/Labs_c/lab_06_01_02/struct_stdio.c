#include "func_strstdio.h"

#define BUFF_READ 8 //количество символов для чтение перевода на следующую строку

int read_struct_info(FILE *f, st_nwv *nwv)
{
    int len;
    char buf[BUFF_READ];
    int rc = EXIT_SUCCESS;
    if (f == NULL)
        rc = PARAMS_ERR;
    else
    {
        if (fgets(nwv->name_subject, L_S + 2, f) == NULL)
            rc = ERR_IO;
        else
        {
            trim_beg_end_str(nwv->name_subject);
            len = strlen(nwv->name_subject);
            if (nwv->name_subject[len - 1] == '\n')
                nwv->name_subject[len - 1] = '\0';
            if (len <= 2)
                rc = STRUCT_ERROR;
            else if (len > L_S)
                rc = SUBJECT_OVERFLOW;
            else
            {
                if ((rc = fscanf(f, "%lf", &nwv->weight) != 1))
                    rc = STRUCT_ERROR;
                if ((rc = fscanf(f, "%lf", &nwv->volume) != 1))
                    rc = STRUCT_ERROR;
                if (nwv->weight <= 0 || nwv->volume <= 0)
                    rc = NEGATIVE_DATA;
                fgets(buf, sizeof(buf), f);
            }
        }   
    }
    return rc;
}

int read_struct(FILE *f, st_nwv *arr, size_t *n)
{
    st_nwv cur;
    int i = 0, rc = EXIT_SUCCESS;
    while (rc == EXIT_SUCCESS)
    {
        rc = read_struct_info(f, &cur);
        if (rc == EXIT_SUCCESS)
        {
            if (i <= SIZE_ARRAY)
            {
                arr[i] = cur;
                i++;
            }
            else
                rc = ARRAY_OVERFLOW;
        }  
    }
    *n = i;
    if (rc == ERR_IO)
        rc = EXIT_SUCCESS;
    if (i <= 0 && rc == EXIT_SUCCESS)
        rc = FILE_IS_EMPTY;
    return rc;
}

void print_struct_info(FILE *f, st_nwv *nwv)
{
    fprintf(f, "%s\n", nwv->name_subject);
    fprintf(f, "%.6lf\n", nwv->weight);
    fprintf(f, "%.6lf\n", nwv->volume);    
}

void printf_struct(FILE *f, st_nwv *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
        print_struct_info(f, &arr[i]);
}

