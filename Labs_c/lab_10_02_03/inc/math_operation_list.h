#ifndef _MATH_OPERATION_LIST_H
#define _MATH_OPERATION_LIST_H

#include <math.h>

#include "struct_list.h"
#include "read_action_and_num.h"
#include "check_prime.h"
#include "memory.h"
#include "errors.h"

int len_list(node_t *list);
int translate_list_in_num(node_t *list, int *num);
int translate_num_in_list(node_t **list, int num);
int multiply_lists(node_t **result, node_t *list_1, node_t *list_2);
int divide_lists(node_t **result, node_t *list_1, node_t *list_2);
int sqr_list(node_t **result, node_t *list);

#endif //MATH_OPERATION_LIST_H