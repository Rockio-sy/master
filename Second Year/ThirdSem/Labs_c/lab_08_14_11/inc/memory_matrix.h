#ifndef _MEMORY_MATRIX_H
#define _MEMORY_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

double **allocate_matrix_third(int n, int m);
void free_matrix_third(double ***data);

#endif //_MEMORY_MATRIX_H