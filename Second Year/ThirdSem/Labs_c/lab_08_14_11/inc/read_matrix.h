#ifndef _READ_MATRIX_H
#define _READ_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#include "struct_matrix.h"
#include "errors.h"
#include "memory_matrix.h"

void default_usual_matrix(matrix_t *matrix);
int fread_usual_matrix(FILE *f, matrix_t *matrix);


#endif //_READ_MATRIX_H