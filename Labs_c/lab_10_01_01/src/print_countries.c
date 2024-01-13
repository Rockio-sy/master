#include "print_countries.h"

void fprint_country(FILE *f, country_t *country)
{
    fprintf(f, "%s\n", country->name_country);
    fprintf(f, "%s\n", country->name_capital);
    fprintf(f, "%ld\n", country->population);
}

void fprint_countries(FILE *f, country_t *countries, int n)
{
    if (f == NULL)
        printf("FILE ERROR\n");
    else if (countries == NULL)
        printf("EMPTY FILE!\n");
    else
        for (int i = 0; i < n; i++)
            fprint_country(f, countries + i);
}

void print_error(int rc)
{
    switch (rc)
    {
        case PARAMS_ERROR:
            printf("ERR_PAR\n");
            break;
        case FILE_NOT_FOUND:
            printf("FILE DOESN'T EXIST!\n");
            break;
        case FILE_IS_EMPTY:
            printf("EMPTY FILE\n");
            break;
        case RESULT_FILE:
            printf("ERR_NAME_FILE!\n");
            break;
        case ACTION_ERROR:
            printf("ERR_ACT!\n");
            break;
        case ARGC_ERROR:
            printf("ERR_ARG!\n");
            break;
        case MEMORY_ERROR:
            printf("ERR_MEM!\n");
            break;
        case FIND_OVERFLOW:
            printf("OVERFLOW!\n");
            break;
        case STRUCT_ERROR:
            printf("ERR_DATA!\n");
            break;
    }
}