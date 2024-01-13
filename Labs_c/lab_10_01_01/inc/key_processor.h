#ifndef _KEY_PROCESSOR_H
#define _KEY_PROCESSOR_H

#include "struct_list.h"
#include "struct_country.h"
#include "memory_list.h"
#include "memory_countries.h"
#include "read_countries.h"
#include "checks.h"
#include "print_countries.h"
#include "errors.h"
#include "operations_with_element_list.h"
#include "operations_with_list.h"

void processor_key_pf(node_t **head);
void processor_key_pb(node_t **head);
int processor_key_a(node_t **head, char *name_f_in_2, char *name_f_out);
int processor_key_f(node_t **head, char *name_f_in_2, char *name_f_out);

#endif
