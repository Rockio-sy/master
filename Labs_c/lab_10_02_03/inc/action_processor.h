#ifndef _ACTION_PROCESSOR_H
#define _ACTION_PROCESSOR_H

#include <stdio.h>
#include <stdlib.h>

#include "struct_list.h"
#include "errors.h"
#include "memory.h"
#include "read_action_and_num.h"
#include "math_operation_list.h"
#include "print_list.h"

int action_out(void);
int action_mul(void);
int action_div(void);
int action_sqr(void);

#endif