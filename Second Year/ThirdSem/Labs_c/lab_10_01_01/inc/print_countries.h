#ifndef _PRINT_COUNTRIES_H
#define _PRINT_COUNTRIES_H

#include "struct_country.h"
#include "errors.h"

void fprint_country(FILE *f, country_t *country);
void fprint_countries(FILE *f, country_t *countries, int n);
void print_error(int rc);

#endif //_PRINT_COUNTRIES_H
