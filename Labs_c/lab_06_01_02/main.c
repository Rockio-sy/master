#include "func_strstdio.h"

int main(int argc, char **argv)
{
    if (!(argc >= 2 && argc <= 3) || argv == NULL)
        return PARAMS_ERR;
    FILE *f_in;
    size_t n = 0;
    int rc = EXIT_SUCCESS;
    st_nwv arr[SIZE_ARRAY];
    
    f_in = fopen(argv[1], "r");
    if (f_in == NULL)
        return FILE_NOT_FOUND;
    rc = read_struct(f_in, arr, &n);
    if (rc != EXIT_SUCCESS)
        return rc;
    if (argc == 2)
    {
        sort_array_by_density(arr, n);
        printf_struct(stdout, arr, n);
    }
    else if (argc == 3)
    {
        if (strlen(argv[2]) > L_S + 1)
            return PREFIX_OVERFLOW;
        if (check_prefix(argv[2], "ALL") == 1)
            printf_struct(stdout, arr, n);
        else
            rc = print_struct_begining_string(stdout, arr, n, argv[2]);
    }
    fclose(f_in);
    return rc;
}
