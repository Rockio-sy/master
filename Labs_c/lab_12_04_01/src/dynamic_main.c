#include "dynamic_utils.h"
#include "dynamic_key.h"
#include "dynamic_sort.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = EXIT_SUCCESS;
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
    
    return rc;
}