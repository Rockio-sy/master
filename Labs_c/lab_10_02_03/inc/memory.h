#ifndef _MEMORY_H
#define _MEMORY_H

#include <stdio.h>
#include <stdlib.h>

#include "struct_list.h"
#include "errors.h"

int list_push_back(node_t **head, int element);

node_t *node_create(int data);
void free_list(node_t **head);

char *allocate_malloc_string(int len);
void free_malloc_string(char **str);

#endif //_MEMORY_H
