#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "/home/rockio/sec_year/Data_structuers/lab_06/inc/tree.h"
#include "/home/rockio/sec_year/Data_structuers/lab_06/inc/stack.h"
#include "/home/rockio/sec_year/Data_structuers/lab_06/inc/defines.h"


int as_pop(arr_stack_t *stack, char *opt, int *val)
{
    if (!stack->length)
        return ERR_EMPTY_STACK;

    stack->length--;
    *opt = stack->opts[stack->length];
    *val = stack->vals[stack->length];
    return EXIT_SUCCESS;
}

int as_push(arr_stack_t *stack, char opt, int val)
{
    if (stack->length == MAX_ARR_LEN)
        return ERR_FULL_STACK;

    stack->opts[stack->length] = opt;
    stack->vals[stack->length] = val;
    stack->length++;
    return EXIT_SUCCESS;
}

int as_print(arr_stack_t *stack)
{
    if (!stack->length)
        return ERR_EMPTY_STACK;

    arr_stack_t tmp = { .length = 0 };
    while (stack->length)
    {
        char opt;
        int val;
        as_pop(stack, &opt, &val);
        as_push(&tmp, opt, val);
        printf("%c | %d\n", opt, val);
    }

    while (tmp.length)
    {
        char opt;
        int val;
        as_pop(&tmp, &opt, &val);
        as_push(stack, opt, val);
    }

    return EXIT_SUCCESS;
}

int stack_res(int arr[NUMS_COUNT])
{
    arr_stack_t *stack = malloc(sizeof(arr_stack_t));
    arr_stack_t *stack_opt = malloc(sizeof(arr_stack_t));

    if (stack == NULL || stack_opt == NULL)
        printf("Ошибка выделения памяти под стек!\n");

    // 2 + (3 - (4 + (5 * 6)))
    // 2 3 4 5 6 * + - +
    // 6 5 4 3 2
    // * + - +
    char opt;
    int val;

    as_push(stack_opt, '*', 0);
    as_push(stack_opt, '+', 0);
    as_push(stack, ' ', arr[0]);
    as_push(stack, ' ', arr[1]);
    as_push(stack, ' ', arr[2]);
    as_push(stack, ' ', arr[3]);
    as_push(stack, ' ', arr[4]);
    as_push(stack, ' ', arr[5]);

    while (stack_opt->length)
    {
        as_pop(stack_opt, &opt, &val);
        char a_opt, b_opt;
        int a_val, b_val;
        as_pop(stack, &a_opt, &a_val);
        as_pop(stack, &b_opt, &b_val);

        if (opt == '+')
            as_push(stack, ' ', a_val + b_val);
        else if (opt == '-')
            as_push(stack, ' ', b_val - a_val);
        else if (opt == '*')
            as_push(stack, ' ', a_val * b_val);
    }

    as_push(stack_opt, '+', 0);
    as_push(stack_opt, '-', 0);
    as_push(stack_opt, '-', 0);
    as_push(stack, ' ', arr[6]);
    as_push(stack, ' ', arr[7]);

    while (stack_opt->length)
    {
        as_pop(stack_opt, &opt, &val);
        char a_opt, b_opt;
        int a_val, b_val;
        as_pop(stack, &a_opt, &a_val);
        as_pop(stack, &b_opt, &b_val);

        if (opt == '+')
            as_push(stack, ' ', a_val + b_val);
        else if (opt == '-')
            as_push(stack, ' ', b_val - a_val);
        else if (opt == '*')
            as_push(stack, ' ', a_val * b_val);
    }

    as_push(stack_opt, '+', 0);
    as_push(stack_opt, '*', 0);
    as_push(stack_opt, '+', 0);
    as_push(stack, ' ', arr[8]);

    while (stack_opt->length)
    {
        as_pop(stack_opt, &opt, &val);
        char a_opt, b_opt;
        int a_val, b_val;
        as_pop(stack, &a_opt, &a_val);
        as_pop(stack, &b_opt, &b_val);

        if (opt == '+')
            as_push(stack, ' ', a_val + b_val);
        else if (opt == '-')
            as_push(stack, ' ', b_val - a_val);
        else if (opt == '*')
            as_push(stack, ' ', a_val * b_val);
    }

    as_pop(stack, &opt, &val);

    return val;
}
