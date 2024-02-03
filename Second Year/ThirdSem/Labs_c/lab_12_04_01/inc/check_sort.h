#ifndef _CHECK_SORT_H_
#define _CHECK_SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#ifdef DYNAMIC_UNIT
#include "dynamic_sort.h"
#else
#include "sort.h"
#endif

Suite *sort_suite(void);
Suite *cmp_int_suite(void);

#endif