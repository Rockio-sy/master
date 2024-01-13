#ifndef _DYNAMIC_LOAD_H_
#define _DYNAMIC_LOAD_H_

#include "dynamic_utils.h"
#include "dynamic_key.h"
#include "dynamic_sort.h"
#include <windows.h>

typedef int(ARR_DECL *fn_allocate_arr_t)(int **arr_beg, int n);
typedef void(ARR_DECL *fn_free_arr_t)(int **arr_beg, int **arr_end);

typedef int(ARR_DECL *fn_get_count_elements_t)(FILE *f, int *count);
typedef int(ARR_DECL *fn_read_array_t)(FILE *f, int *arr, size_t n);
typedef int(ARR_DECL *fn_create_array_t)(FILE *f, int **arr, size_t *n);

typedef void(ARR_DECL *fn_fprint_t)(FILE *f, const int *arr_beg, const int *arr_end);

typedef void(ARR_DECL *fn_swap_t)(void *el1, void *el2, size_t size);
typedef int(ARR_DECL *fn_cmp_int_t)(const void *p, const void *q);
typedef void(ARR_DECL *fn_mysort_t)(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *));

typedef double(ARR_DECL *fn_calc_avg_t)(const int *arr_beg, const int *arr_end);
typedef int(ARR_DECL *fn_get_count_for_key_t)(const int *pb_src, const int *pe_src);
typedef int(ARR_DECL *fn_key_t)(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst);

int lib_allocate_and_free(HMODULE hlib, fn_allocate_arr_t *allocate_arr, fn_free_arr_t *free_arr);
int lib_create_read_print(HMODULE hlib, fn_get_count_elements_t *get_count, fn_create_array_t *create,
                                        fn_read_array_t *read, fn_fprint_t *print);
int lib_sort_key(HMODULE hlib, fn_swap_t *swap, fn_cmp_int_t *cmp_int, fn_mysort_t *mysort,
                               fn_calc_avg_t *calc_avg, fn_get_count_for_key_t *get_count, fn_key_t *key);

#endif