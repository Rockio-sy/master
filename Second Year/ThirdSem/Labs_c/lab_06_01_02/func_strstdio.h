#ifndef _FUNC_STRSTDIO_H_
#define _FUNC_STRSTDIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define L_S        25
#define SIZE_ARRAY 15

#define PARAMS_ERR       1
#define ARRAY_OVERFLOW   2
#define SUBJECT_OVERFLOW 3
#define STRUCT_ERROR     4
#define FILE_IS_EMPTY    5
#define FILE_NOT_FOUND   6
#define ERR_IO           7
#define NOT_FOUND_STRUCT 8
#define NEGATIVE_DATA    9
#define PREFIX_OVERFLOW  10

typedef struct
{
    char name_subject[L_S + 1];
    double weight;
    double volume;
} st_nwv;

int read_struct_info(FILE *f, st_nwv *nwv);

int read_struct(FILE *f, st_nwv *arr, size_t *n);

void print_struct_info(FILE *f, st_nwv *nwv);

void printf_struct(FILE *f, st_nwv *arr, size_t n);

int print_struct_begining_string(FILE *f, st_nwv *arr, size_t n, char *str);

void sort_array_by_density(st_nwv *arr, size_t n);

int check_prefix(char *str, char *prefix);

void str_shift_left(char *str, size_t i);

void trim_beg_end_str(char *str);

void swap_struct(st_nwv *st_1, st_nwv *st_2);

#endif