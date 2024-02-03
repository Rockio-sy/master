#ifndef _STRUCT_MATRIX_H
#define _STRUCT_MATRIX_H

#define MAX_ARGC       5
#define MIN_ARGC       4
#define SUM_OR_MULPTI  MAX_ARGC
#define SPECIAL        MIN_ARGC

#define EPS 1e-8

typedef struct usual_matrix_t
{
    double **matrix;
    int n;
    int m;
} matrix_t;

#endif //_STRUCT_MATRIX_H
