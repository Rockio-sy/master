#include <stdio.h>

#include "array.h"

size_t int_array_insert(int arr[], size_t len, int elem, size_t ind)
{
    int temp;
    for (size_t i = ind; i < len; i++)
    {
        temp = arr[i];
        arr[i] = elem;
        elem = temp;
    }
    arr[len] = elem;
    return ++len;
}

size_t size_t_array_insert(size_t arr[], size_t len, size_t elem, size_t ind)
{
    size_t temp;
    for (size_t i = ind; i < len; i++)
    {
        temp = arr[i];
        arr[i] = elem;
        elem = temp;
    }
    arr[len] = elem;
    return ++len;
}

void int_array_output(int arr[], size_t len)
{
    for (size_t i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void size_t_array_output(size_t arr[], size_t len)
{
    for (size_t i = 0; i < len; i++)
        printf("%zu ", arr[i]);
    printf("\n");
}
