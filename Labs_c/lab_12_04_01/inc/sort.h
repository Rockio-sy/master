#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *el1, void *el2, size_t size);
int cmp_int(const void *p, const void *q);
void mysort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *));

#endif