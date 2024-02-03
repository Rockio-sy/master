#ifndef __STACK_H__
#define __STACK_H__

#include "defines.h"

typedef struct
{
    char opts[MAX_ARR_LEN];  // массив операторов
    int vals[MAX_ARR_LEN];   // массив операндов
    int length;              // длинна стека
} arr_stack_t;

int as_pop(arr_stack_t *stack, char *opt, int *val);

int as_push(arr_stack_t *stack, char opt, int val);

int as_print(arr_stack_t *stack);

int stack_res(int arr[NUMS_COUNT]);

#endif
