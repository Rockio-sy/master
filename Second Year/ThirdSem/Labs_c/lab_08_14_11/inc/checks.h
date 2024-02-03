#ifndef _CHECKS_H
#define _CHECKS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_matrix.h"
#include "errors.h"

int check_file(FILE *f);
int check_argc(int argc, char *action, int min, int max);
int check_matrix_params(const matrix_t *matrix);

#endif //_CHECKS_H