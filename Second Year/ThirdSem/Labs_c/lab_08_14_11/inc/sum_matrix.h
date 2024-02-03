#ifndef _SUM_MATRIX_H
#define _SUM_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "struct_matrix.h"
#include "errors.h"
#include "memory_matrix.h"
#include "checks.h"

int sum_usual_matrix(matrix_t *result, const matrix_t *f_summand, const matrix_t *s_summand);

#endif //_SUM_MATRIX_H