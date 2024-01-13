#include "dynamic_load.h"

int lib_allocate_and_free(HMODULE hlib, fn_allocate_arr_t *allocate_arr, fn_free_arr_t *free_arr)
{
    int rc = EXIT_SUCCESS;
    
    *allocate_arr = (fn_allocate_arr_t)GetProcAddress(hlib, "allocate_arr");
    if (!*allocate_arr)
        rc = OPEN_LIBRARY_ERROR;
    
    if (rc == EXIT_SUCCESS)
    {
        *free_arr = (fn_free_arr_t)GetProcAddress(hlib, "free_arr");
        if (!*free_arr)
            rc = OPEN_LIBRARY_ERROR;
    }
    
    return rc;
}

int lib_create_read_print(HMODULE hlib, fn_get_count_elements_t *get_count, fn_create_array_t *create,
                                        fn_read_array_t *read, fn_fprint_t *print)
{
    int rc = EXIT_SUCCESS;
    
    *get_count = (fn_get_count_elements_t)GetProcAddress(hlib, "get_count_elements");
    if (!*get_count)
        rc = OPEN_LIBRARY_ERROR;
    
    if (rc == EXIT_SUCCESS)
    {
        *create = (fn_create_array_t)GetProcAddress(hlib, "create_array");
        if (!*create)
            rc = OPEN_LIBRARY_ERROR;
    }
    
    if (rc == EXIT_SUCCESS)
    {
        *read = (fn_read_array_t)GetProcAddress(hlib, "read_array");
         if (!*read)
            rc = OPEN_LIBRARY_ERROR;
    }
    
    if (rc == EXIT_SUCCESS)
    {
        *print = (fn_fprint_t)GetProcAddress(hlib, "fprint");
        if (!*print)
            rc = OPEN_LIBRARY_ERROR;
    }

    return rc;
}

int lib_sort_key(HMODULE hlib, fn_swap_t *swap, fn_cmp_int_t *cmp_int, fn_mysort_t *mysort,
                               fn_calc_avg_t *calc_avg, fn_get_count_for_key_t *get_count, fn_key_t *key)
{
    int rc = EXIT_SUCCESS;
    
    *swap = (fn_swap_t)GetProcAddress(hlib, "swap");
    if (!*swap)
        rc = OPEN_LIBRARY_ERROR;
    
    if (rc == EXIT_SUCCESS)
    {
        *cmp_int = (fn_cmp_int_t)GetProcAddress(hlib, "cmp_int");
        if (!*cmp_int)
            rc = OPEN_LIBRARY_ERROR;
    }
    
    if (rc == EXIT_SUCCESS)
    {
        *mysort = (fn_mysort_t)GetProcAddress(hlib, "mysort");
        if (!*mysort)
            rc = OPEN_LIBRARY_ERROR;
    }
    
    if (rc == EXIT_SUCCESS)
    {
        *calc_avg = (fn_calc_avg_t)GetProcAddress(hlib, "calc_avg");
        if (!*calc_avg)
            rc = OPEN_LIBRARY_ERROR;
    }
    
    if (rc == EXIT_SUCCESS)
    {
        *get_count = (fn_get_count_for_key_t)GetProcAddress(hlib, "get_count_for_key");
        if (!*get_count)
            rc = OPEN_LIBRARY_ERROR;
    }
     
    if (rc == EXIT_SUCCESS)
    {
        *key = (fn_key_t)GetProcAddress(hlib, "key");
        if (!*key)
            rc = OPEN_LIBRARY_ERROR;
    }
    return rc;
}