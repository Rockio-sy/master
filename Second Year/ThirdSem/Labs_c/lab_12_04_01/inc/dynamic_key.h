#ifndef _DYNAMIC_KEY_H_
#define _DYNAMIC_KEY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic.h"

#define MEMORY_ERR         2
#define ARRAY_SRC_EMPTY    5
#define ARRAY_DST_EMPTY    6
#define PARAMS_ERR         8

ARR_DLL double ARR_DECL calc_avg(const int *arr_beg, const int *arr_end);
ARR_DLL int ARR_DECL get_count_for_key(const int *pb_src, const int *pe_src);
ARR_DLL int ARR_DECL key(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst);

#endif