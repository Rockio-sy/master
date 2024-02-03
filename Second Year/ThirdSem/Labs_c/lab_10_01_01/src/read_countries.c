#include "read_countries.h"

void default_country(country_t *country)
{
    country->name_country = NULL;
    country->name_capital = NULL;
    country->population = 0;
}

void default_array_country(countries_t *data)
{
    data->array = NULL;
    data->size = 0;
}

int get_size_string(FILE *f)
{
    int count = 0;
    if (f != NULL)
    {
        char buff_symbol;
        while ((buff_symbol = (char) fgetc(f)) != '\n' && buff_symbol != EOF)
            count++;
    }

    return count;
}

int get_size_struct(FILE *f, size_t *size)
{
    int rc = EXIT_SUCCESS;
    if (f == NULL || size == NULL)
        rc = PARAMS_ERROR;
    else
    {
        char buff_c = '.', buff_l = buff_c;
        int count_string = 0, coutn_sym = 0;
        while (buff_c != EOF)
        {
            buff_c = fgetc(f);
            if ((buff_c == '\n' || (buff_c == EOF && buff_l != '\n')) && coutn_sym)
            {
                count_string++;
                coutn_sym = 0;
            }
            if (buff_c != '\n')
                coutn_sym++;
            buff_l = buff_c;
        }
        if (count_string > 0 && count_string % COUNT_STRING_STRUCT == 0)
            *size = count_string / COUNT_STRING_STRUCT;
        else
            *size = 0;
    }

    return rc;
}

int fread_name_str(FILE *f, char **str, int size_str)
{
    int rc = EXIT_SUCCESS;
    if (f == NULL || str == NULL || *str != NULL || size_str <= 0)
        rc = PARAMS_ERROR;
    else
    {
        *str = allocate_name_str(size_str);
        if (*str == NULL)
            rc = MEMORY_ERROR;
        else
        {
            if (fgets(*str, size_str, f) == NULL)
                rc = ERR_IO;
            else
            {
                if (str_not_only_spaces(*str))
                {
                    size_t len;
                    len = strlen(*str);
                    if ((*str)[len - 1] == '\n')
                        (*str)[len - 1] = '\0';
                    if (strlen(*str) <= 0)
                        rc = STRUCT_ERROR;
                }
                else
                    rc = STRUCT_ERROR;
            }
        }
    }

    return rc;
}

int fread_country_info(FILE *f, country_t *country, size_t count_st)
{
    char buff;
    int rc = EXIT_SUCCESS;
    if (f == NULL || country == NULL)
        rc = PARAMS_ERROR;
    else
    {
        int size_country, size_capital;
        size_country = get_size_string(f);
        size_capital = get_size_string(f);
        if (size_country > 0)
        {
            fseek(f, 0, SEEK_SET); // rewind(f);
            for (int i = 0; i < count_st; i++)
            {
                char buff_c;
                while ((buff_c = fgetc(f)) != '\n' && buff_c != EOF);
                while ((buff_c = fgetc(f)) != '\n' && buff_c != EOF);
                while ((buff_c = fgetc(f)) != '\n' && buff_c != EOF);
            }
            rc = fread_name_str(f, &country->name_country, size_country + 2);
            if (rc == EXIT_SUCCESS)
            {
                rc = fread_name_str(f, &country->name_capital, size_capital + 2);
                if (rc == EXIT_SUCCESS)
                {
                    if (fscanf(f, "%ld", &country->population) != 1)
                        rc = STRUCT_ERROR;
                    if (country->population <= 0)
                    {
                        country->population = 0;
                        rc = STRUCT_ERROR;
                    }
                    while ((buff = fgetc(f)) != '\n' && buff != EOF);
                }
            }
        }
        else
            rc = ERR_IO;
    }

    return rc;
}

int fread_countries(FILE *f, country_t **data, int *n)
{
    int rc = EXIT_SUCCESS;
    if (f == NULL || data == NULL || *data != NULL || n == NULL)
        rc = PARAMS_ERROR;
    else
    {
        int i = 0;

        rc = get_size_struct(f, (size_t *) n);
        if (*n <= 0)
            rc = STRUCT_ERROR;
        else
        {
            rewind(f);

            *data = allocate_struct_country(*n);
            if (*data == NULL)
                rc = MEMORY_ERROR;

            while (i < *n && rc == EXIT_SUCCESS)
            {
                rc = fread_country_info(f, (*data + i), i);
                i++;
            }

            if (rc == ERR_IO)
                rc = STRUCT_ERROR;
        }
    }

    return rc;
}