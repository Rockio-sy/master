#ifndef _OPERATIONS_WITH_ELEMENT_LIST_H
#define _OPERATIONS_WITH_ELEMENT_LIST_H
#include "struct_list.h"
#include "struct_country.h"
#include "errors.h"

int comparator(const void *f_data, const void *s_data);
int comparator_find_country(void *f_struct, void *s_struct);

node_t *find(node_t *head, const void *data, int (*comparator)(const void*, const void*));

void *pop_front(node_t **head);
void *pop_back(node_t **head);

void insert(node_t **head, node_t *elem, node_t *before);

#endif //_OPERATIONS_WITH_ELEMENT_LIST_H
