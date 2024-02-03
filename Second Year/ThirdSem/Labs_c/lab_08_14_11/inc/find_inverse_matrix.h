#ifndef _FIND_INVERSE_MATRIX_H
#define _FIND_INVERSE_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "struct_matrix.h"
#include "read_matrix.h"
#include "memory_matrix.h"
#include "errors.h"
#include "checks.h"
#include "swap.h"
#include "copy_matrix.h"

double det_matrix(matrix_t *matrix);
int check_degenerate_matrix(const matrix_t *matrix);
void fill_last_column_square_matrix(double **slau, int j_ind, int j_last);

void zeroing_the_lower_right_corner(matrix_t *slau, matrix_t *origin);
void zeroing_the_upper_left_corner(matrix_t *slau, matrix_t *origin);
void add_inverse_column(matrix_t *inverse_column, const matrix_t *slau, int obm, int j_ind);
int find_column_inverse_matrix(matrix_t *inverse_column, const matrix_t *origin, int j_ind);

int gaussian_inverse_matrix(matrix_t *inverse, matrix_t *origin);

#endif //_FIND_INVERSE_MATRIX_H