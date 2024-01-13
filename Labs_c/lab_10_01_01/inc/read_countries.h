#ifndef _READ_COUNTRIES_H
#define _READ_COUNTRIES_H

#include "struct_country.h"
#include "memory_countries.h"
#include "checks.h"
#include "errors.h"

void default_country(country_t *country);
void default_array_country(countries_t *data);

int get_size_string(FILE *f);
int get_size_struct(FILE *f, size_t *size);

int fread_name_str(FILE *f, char **str, int size_str);
int fread_country_info(FILE *f, country_t *country, size_t count_st);
int fread_countries(FILE *f, country_t **data, int *n);

#endif //_READ_COUNTRIES_H
