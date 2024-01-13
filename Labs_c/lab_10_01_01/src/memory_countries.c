#include "memory_countries.h"

char *allocate_name_str(int len)
{
    char *str = NULL;
    if (len > 0)
        str = malloc(len * sizeof(char));
    return str;
}

void free_name_str(char **str)
{
    if (str != NULL && *str != NULL)
    {
        free(*str);
        *str = NULL;
    }
}

country_t *allocate_struct_country(int size)
{
    country_t *data = NULL;
    if (size > 0)
    {
        data = malloc(size * sizeof(country_t));
        for (int i = 0; i < size; i++)
        {
            (data + i)->name_country = NULL;
            (data + i)->name_capital = NULL;
            (data + i)->population = 0;
        }
    }

    return data;
}

void free_struct_country(country_t **data, int *n)
{
    if (data != NULL && *data != NULL && *n > 0)
    {
        for (int i = 0; i < *n; i++)
        {
            free_name_str(&(*data + i)->name_country);
            free_name_str(&(*data + i)->name_capital);
        }
        free(*data);
        *data = NULL;
        *n = 0;
    }
}