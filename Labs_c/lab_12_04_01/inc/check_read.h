#ifndef _CHECK_READ_H_
#define _CHECK_READ_H_

#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#ifdef DYNAMIC_UNIT
#include "dynamic_utils.h"
#else
#include "utils.h"
#endif

Suite *create_array_suite(void);
Suite *read_array_suite(void);

#endif