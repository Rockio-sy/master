#include "dynamic_load.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = EXIT_SUCCESS;
    
    HMODULE hlib;
    fn_allocate_arr_t allocate_arr;
    fn_free_arr_t free_arr;
    fn_get_count_elements_t get_count_elements;
    fn_read_array_t read_array;
    fn_create_array_t create_array;
    fn_fprint_t fprint;
    fn_swap_t swap;
    fn_cmp_int_t cmp_int;
    fn_mysort_t mysort;
    fn_calc_avg_t calc_avg;
    fn_get_count_for_key_t get_count_for_key;
    fn_key_t key;
    
    hlib = LoadLibrary("dynamic_lib.dll");
    if (hlib == NULL)
        rc = OPEN_LIBRARY_ERROR;
    else
    {
        rc = lib_allocate_and_free(hlib, &allocate_arr, &free_arr);
        if (rc == EXIT_SUCCESS)
            rc = lib_create_read_print(hlib, &get_count_elements, &create_array, &read_array, &fprint);
        
        if (rc == EXIT_SUCCESS)
            rc = lib_sort_key(hlib, &swap, &cmp_int, &mysort, &calc_avg, &get_count_for_key, &key);
        
        if (rc == EXIT_SUCCESS)
        {
            if (argc < 3 || argc > 4)
               rc = ARG_ERR;
            else
            {
                FILE *f_in, *f_out;

                f_in = fopen(argv[1], "r");
                if (f_in == NULL)
                    rc = NOT_FOUND_FILE;
                else
                {
                    int *src_beg = NULL, *src_end = NULL, *dst_beg = NULL, *dst_end = NULL;
                    size_t len_src = 0;
                    
                    f_out = fopen(argv[2], "w");
                    rc = create_array(f_in, &src_beg, &len_src);
                    if (rc == EXIT_SUCCESS)
                    {
                        src_end = src_beg + len_src;
                        if (argc == 4)
                        {
                            if (strcmp(argv[3], "f") == 0)
                            {
                                int len_dst = get_count_for_key(src_beg, src_end);
                                if (len_dst == 0)
                                    rc = ARRAY_DST_EMPTY;
                                else
                                {
                                    dst_beg = (int *) malloc(len_dst * sizeof(int));
                                    if (dst_beg == NULL)
                                        rc = MEMORY_ERR;
                                    else
                                    {
                                        dst_end = dst_beg + len_dst;
                                        rc = key(src_beg, src_end, dst_beg, dst_end);
                                        if (rc == EXIT_SUCCESS)
                                        {
                                            mysort(dst_beg, dst_end - dst_beg, sizeof(int), cmp_int);
                                            fprint(f_out, dst_beg, dst_end);
                                        }
                                        free_arr(&dst_beg, &dst_end);
                                    }
                                }
                            }
                            else
                                rc = ARG_ERR;
                        }
                        else
                        {
                            mysort(src_beg, src_end - src_beg, sizeof(int), cmp_int);
                            fprint(f_out, src_beg, src_end);
                        }
                    }
                    free_arr(&src_beg, &src_end);
                    fclose(f_in);
                    fclose(f_out);
                } 
            }
        }
        
        FreeLibrary(hlib);
    }    
    return rc;
}
