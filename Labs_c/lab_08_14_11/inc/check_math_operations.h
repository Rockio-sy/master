#ifndef _CHECK_MATH_OPERATIONS_H
#define _CHECK_MATH_OPERATIONS_H

#include "struct_matrix.h"
#include "sum_matrix.h"
#include "multiplication_matrix.h"
#include "find_inverse_matrix.h"
#include "copy_matrix.h"
#include "errors.h"

int tests_copy_matrix(void);
int tests_sum_matrix(void);
int tests_multiplication_matrix(void);

int tests_det_matrix(void);
int tests_check_degenerate_matrix(void);

int tests_zeroing_corners(void);

int test_gaussian_inverse_matrix(void);

#endif //_CHECK_MATH_OPERATIONS_H
