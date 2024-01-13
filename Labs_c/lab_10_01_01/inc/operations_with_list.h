#ifndef _OPERATIONS_WITH_LIST_H
#define _OPERATIONS_WITH_LIST_H



#include "errors.h"
#include "struct_list.h"
#include "struct_country.h"
#include "print_countries.h"

int comparator_name_country(void *f_struct, void *s_struct);

int fwrite_countries(char *namefile, node_t *head);
void fprint_list(FILE *f, node_t *head);

void append(node_t **head_a, node_t **head_b);
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

#endif //_OPERATIONS_WITH_LIST_H