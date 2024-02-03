#ifndef _DYNAMIC_UTILS_H_
#define _DYNAMIC_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic.h"

#define ARG_ERR            1
#define MEMORY_ERR         2
#define DATA_IS_EMPTY      3
#define NOT_FOUND_FILE     4
#define ARRAY_SRC_EMPTY    5
#define ARRAY_DST_EMPTY    6
#define FILE_IS_INCORRECT  7
#define PARAMS_ERR         8
#define AVR_ERR            9
#define OPEN_LIBRARY_ERROR 10

ARR_DLL int ARR_DECL allocate_arr(int **arr_beg, int n);
ARR_DLL void ARR_DECL free_arr(int **arr_beg, int **arr_end);

ARR_DLL int ARR_DECL get_count_elements(FILE *f, int *count);
ARR_DLL int ARR_DECL read_array(FILE *f, int *arr, size_t n);
ARR_DLL int ARR_DECL create_array(FILE *f, int **arr, size_t *n);

ARR_DLL void ARR_DECL fprint(FILE *f, const int *arr_beg, const int *arr_end);

#endif