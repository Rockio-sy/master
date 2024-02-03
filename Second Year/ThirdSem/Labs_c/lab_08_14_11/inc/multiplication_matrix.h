#ifndef _MULTIPLICATION_MATRIX_H
#define _MULTIPLICATION_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "struct_matrix.h"
#include "errors.h"
#include "memory_matrix.h"
#include "checks.h"

int multiplication_usual_matrix(matrix_t *result, const matrix_t *multiplicanda, const matrix_t *multiplier);

#endif //_MULTIPLICATION_MATRIX_H