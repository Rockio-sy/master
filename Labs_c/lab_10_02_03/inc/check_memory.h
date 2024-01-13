#ifndef _CHECK_MEMORY_H
#define _CHECK_MEMORY_H

#include <stdio.h>
#include <stdlib.h>

#include "struct_list.h"
#include "errors.h"
#include "memory.h"

int tests_create_and_free(void);
int tests_push_list_back(void);
int tests_allocate_and_free_string(void);

#endif //_CHECK_MEMORY_H
