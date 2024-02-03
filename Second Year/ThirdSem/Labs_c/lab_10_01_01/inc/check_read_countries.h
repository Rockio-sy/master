#ifndef _CHECK_READ_COUNTRIES_H
#define _CHECK_READ_COUNTRIES_H

#include <string.h>

#include "struct_country.h"
#include "memory_countries.h"
#include "read_countries.h"
#include "errors.h"

int tests_default_country(void);
int tests_default_array_country(void);

int tests_get_size_string(void);
int tests_get_size_struct(void);

int tests_fread_name_str(void);
int tests_fread_country_info(void);
int tests_fread_countries(void);

#endif //_CHECK_READ_COUNTRIES_H
