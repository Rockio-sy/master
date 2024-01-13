#ifndef _CHECKS_H_H
#define _CHECKS_H_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "errors.h"

int check_file(FILE *f);
int check_argc(int argc, char *action, int min, int max);
int str_not_only_spaces(char *str);

#endif //_CHECKS_H_H
