#ifndef _KEY_H_
#define _KEY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_ERR         2
#define ARRAY_SRC_EMPTY    5
#define ARRAY_DST_EMPTY    6
#define PARAMS_ERR         8

double calc_avg(const int *arr_beg, const int *arr_end);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif