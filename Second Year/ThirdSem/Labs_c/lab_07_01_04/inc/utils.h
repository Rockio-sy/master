#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARG_ERR            1
#define MEMORY_ERR         2
#define DATA_IS_EMPTY      3
#define NOT_FOUND_FILE     4
#define ARRAY_SRC_EMPTY    5
#define ARRAY_DST_EMPTY    6
#define FILE_IS_INCORRECT  7
#define PARAMS_ERR         8
#define AVR_ERR            9

int allocate_arr(int **arr_beg, int n);
void free_arr(int **arr_beg, int **arr_end);

int get_count_elements(FILE *f, int *count);
int read_array(FILE *f, int *arr, size_t n);
int create_array(FILE *f, int **arr, size_t *n);

void fprint(FILE *f, const int *arr_beg, const int *arr_end);
#endif