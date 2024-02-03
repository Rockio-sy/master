#ifndef _READ_ACTION_AND_NUM_H
#define _READ_ACTION_AND_NUM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "memory.h"

#define LIMIT_TRANSLATE 2
#define LEN_ACTION  4
#define OUT         1
#define MUL         2
#define SQR         3
#define DIV         4

int read_action(int *action);
int read_num(int *num);

#endif //_READ_ACTION_AND_NUM_H
