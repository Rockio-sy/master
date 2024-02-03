#ifndef _CHECK_FILTER_H_
#define _CHECK_FILTER_H_

#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#ifdef DYNAMIC_UNIT
#include "dynamic_key.h"
#else
#include "key.h"
#endif

Suite *filter_suite(void);
Suite *calc_avg_suite(void);

#endif