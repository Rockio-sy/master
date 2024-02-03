#ifndef _DYNAMIC_SORT_H_
#define _DYNAMIC_SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dynamic.h"

ARR_DLL void ARR_DECL swap(void *el1, void *el2, size_t size);
ARR_DLL int ARR_DECL cmp_int(const void *p, const void *q);
ARR_DLL void ARR_DECL mysort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *));

#endif