#include "key.h"

double calc_avg(const int *arr_beg, const int *arr_end)
{
    double avr = 0;
    for (const int *i = arr_beg; i < arr_end; i++)
        avr += *i;
    if (avr != 0)
        avr /= (arr_end - arr_beg);
    return avr;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    double avr = 0;
    int rc = EXIT_SUCCESS;
    if (pb_src == NULL || pe_src == NULL || *pb_dst != NULL || *pe_dst != NULL)
        rc = PARAMS_ERR;
    else
    {
        int len_dst = 0;
        if (pe_src <= pb_src)
        {
            rc = ARRAY_SRC_EMPTY;
            *pb_dst = NULL;
            *pe_dst = NULL;
        }
        else
        {
            avr = calc_avg(pb_src, pe_src);
            for (const int *i = pb_src; i < pe_src; i++)
                if (*i > avr)
                    len_dst++;
            if (len_dst == 0)
                rc = ARRAY_DST_EMPTY;
            else
            {
                *pb_dst = malloc(len_dst * sizeof(int));
                if (*pb_dst == NULL)
                    rc = MEMORY_ERR;
                else
                {
                    *pe_dst = *pb_dst + len_dst;
                    int *j = *pb_dst;
                    for (const int *i = pb_src; i < pe_src; i++)
                        if (*i > avr)
                        {
                            *j = *i;
                            j++;
                        }
                }
            }
        }
    }
    return rc;
}