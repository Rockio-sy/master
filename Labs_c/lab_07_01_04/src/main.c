#include "utils.h"
#include "key.h"
#include "sort.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = EXIT_SUCCESS;
    if (argc < 3 || argc > 4)
       return ARG_ERR;

    FILE *f_in, *f_out;
    int *src_beg = NULL, *src_end = NULL, *dst_beg = NULL, *dst_end = NULL;
    size_t n_src = 0;

    f_in = fopen(argv[1], "r");
    if (f_in == NULL)
        rc = NOT_FOUND_FILE;
    else
    {
        f_out = fopen(argv[2], "w");
        rc = create_array(f_in, &src_beg, &n_src);
        if (rc == EXIT_SUCCESS)
        {
            src_end = src_beg + n_src;
            if (argc == 4)
            {
                if (strcmp(argv[3], "f") == 0)
                {
                    rc = key(src_beg, src_end, &dst_beg, &dst_end);
                    if (rc == EXIT_SUCCESS)
                    {
                        mysort(dst_beg, dst_end - dst_beg, sizeof(int), cmp_int);
                        fprint(f_out, dst_beg, dst_end);
                    }
                    free_arr(&dst_beg, &dst_end);
                }
                else
                    rc = ARG_ERR;
            }
            else
            {
                mysort(src_beg, n_src, sizeof(int), cmp_int);
                fprint(f_out, src_beg, src_end);
            }
        }
        free_arr(&src_beg, &src_end);
        fclose(f_in);
        fclose(f_out);
    }
    return rc;
}
