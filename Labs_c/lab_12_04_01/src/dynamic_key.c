#include "../inc/dynamic_key.h"

ARR_DLL double ARR_DECL calc_avg(const int *arr_beg, const int *arr_end)
{
    double avr = 0;
    for (const int *i = arr_beg; i < arr_end; i++)
        avr += *i;
    if (avr != 0)
        avr /= (arr_end - arr_beg);
    return avr;
}

ARR_DLL int ARR_DECL get_count_for_key(const int *pb_src, const int *pe_src)
{
     int len_dst = 0;
     if (pb_src < pe_src)
     {
        double avr = 0.0;
        avr = calc_avg(pb_src, pe_src);
         for (const int *i = pb_src; i < pe_src; i++)
            if (*i > avr)
                len_dst++; 
     }

     return len_dst;   
}

ARR_DLL int ARR_DECL key(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst)
{
    int rc = EXIT_SUCCESS;
    if (pb_src == NULL || pe_src == NULL || pb_dst == NULL || pe_dst == NULL)
        rc = PARAMS_ERR;
    else
    {
        double avr = 0.0;
        if (pe_src <= pb_src)
            rc = ARRAY_SRC_EMPTY;
        else
        {
            avr = calc_avg(pb_src, pe_src);
            if (pe_dst <= pb_dst)
                rc = ARRAY_DST_EMPTY;
            else
            {
                int *j = pb_dst;
                for (const int *i = pb_src; i < pe_src; i++)
                    if (*i > avr)
                    {
                        *j = *i;
                        j++;
                    }
            }
        }
    }
    return rc;
}