#include "func_strstdio.h"

void swap_struct(st_nwv *st_1, st_nwv *st_2)
{
    st_nwv buff = *st_1;
    *st_1 = *st_2;
    *st_2 = buff;
}

void sort_array_by_density(st_nwv *arr, size_t n)
{
    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = i + 1; j < n; j++)
            if (((arr + i)->weight / (arr + i)->volume) > ((arr + j)->weight / (arr + j)->volume))
                swap_struct(arr + i, arr + j);
}

int print_struct_begining_string(FILE *f, st_nwv *arr, size_t n, char *str)
{
    int rc = EXIT_SUCCESS, flag = 0;
    for (size_t i = 0; i < n; i++)
        if (strspn(arr[i].name_subject, str) == strlen(str))
        {
            flag = 1;
            print_struct_info(f, &arr[i]);
        }
    if (flag == 0)
        rc = NOT_FOUND_STRUCT;
    return rc;
}

int check_prefix(char *str, char *prefix)
{
    int rc = 1;
    if (strlen(str) != strlen(prefix))
        rc = 0;
    for (size_t i = 0; i < strlen(prefix) && rc; i++)
        if (toupper(prefix[i]) != toupper(str[i]))
            rc = 0;
    return rc;
}

void str_shift_left(char *str, size_t i)
{
    for (size_t j = i; str[j] != '\0'; j++)
        str[j] = str[j + 1];
}

void trim_beg_end_str(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (isspace(str[i]))
            str[i] = ' ';
        if ((isspace(str[i]) && i == 0) || (isspace(str[i]) && !(isspace(str[i - 1]) == 0 && isspace(str[i + 1]) == 0)))
        {
            str_shift_left(str, i);
            i--;
        }
    }
}