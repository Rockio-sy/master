#ifndef _MEMORY_LIST_H
#define _MEMORY_LIST_H

#include "struct_list.h"
#include "errors.h"

int list_push(node_t **head, void *element);
node_t *node_create(void *data);
void free_list(node_t **head);

#endif //_MEMORY_LIST_H
