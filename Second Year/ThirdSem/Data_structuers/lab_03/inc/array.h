#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

size_t int_array_insert(int arr[], size_t len, int elem, size_t ind);

size_t size_t_array_insert(size_t arr[], size_t len, size_t elem, size_t ind);

void int_array_output(int arr[], size_t len);

void size_t_array_output(size_t arr[], size_t len);

#endif
