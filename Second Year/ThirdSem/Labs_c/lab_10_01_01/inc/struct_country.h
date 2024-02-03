#ifndef _STRUCT_COUNTRY_H
#define _STRUCT_COUNTRY_H

#define MAX_ARGV 5
#define MIN_ARGV 4

#define COUNT_STRING_STRUCT 3

typedef struct country
{
    char *name_country;
    char *name_capital;
    long population;
} country_t;

typedef struct array_countries
{
    country_t *array;
    int size;
}countries_t;

#endif //_STRUCT_COUNTRY_H
