#include "key_processor.h"

void processor_key_pf(node_t **head)
{
    country_t *pop = NULL;
    pop = pop_front(head);
    
    if (pop != NULL)
    {
        fprint_country(stdout, pop);
    }
}

void processor_key_pb(node_t **head)
{
    country_t *pop = NULL;
    pop = pop_back(head);
    if (pop != NULL)
    {
        fprint_country(stdout, pop);
    }
}

int processor_key_a(node_t **head, char *name_f_in_2, char *name_f_out)
{
    int rc = EXIT_SUCCESS;
    FILE *f_in_2 = NULL;
    f_in_2 = fopen(name_f_in_2, "r");
    rc = check_file(f_in_2);
    if (rc == EXIT_SUCCESS)
    {
        countries_t countries_2;
        default_array_country(&countries_2);
        rc = fread_countries(f_in_2, &countries_2.array, &countries_2.size);
        if (rc == EXIT_SUCCESS)
        {
            node_t *head_b = NULL;
            for (int i = 0; i < countries_2.size && !rc; i++)
                rc = list_push(&head_b, countries_2.array + i);
            if (rc == EXIT_SUCCESS)
            {
                append(head, &head_b);
                rc = fwrite_countries(name_f_out, *head);
            }
            free_list(&head_b);
        } 
        free_struct_country(&countries_2.array, &countries_2.size);
        fclose(f_in_2);
    }
    
    return rc;
}

int processor_key_f(node_t **head, char *name_f_in_2, char *name_f_out)
{
    int rc = EXIT_SUCCESS;
    
    FILE *f_in_2 = NULL;
    f_in_2 = fopen(name_f_in_2, "r");
    rc = check_file(f_in_2);
    if (rc == EXIT_SUCCESS)
    {
        country_t find_country;
        default_country(&find_country);
        size_t size_string = 0;
        rc = get_size_struct(f_in_2, &size_string);
        if (rc == EXIT_SUCCESS)
        {
            rewind(f_in_2);
            if (size_string == 0)
                rc = STRUCT_ERROR;
            else if (size_string == 1)
            {
                rc = fread_country_info(f_in_2, &find_country, 0);
                if (rc == EXIT_SUCCESS)
                {
                    node_t *find_el = NULL;
                    find_el = find(*head, &find_country, (int (*)(const void *, const void *)) comparator_find_country);
                    if (find_el == NULL)
                    {
                        rc = FIND_ERROR;
                    }
                    else
                    {
                        FILE *f_out = NULL;
                        f_out = fopen(name_f_out, "w");
                        if (f_out != NULL)
                        {
                            fprint_country(f_out, (country_t *) find_el->data);
                            fclose(f_out);
                        }
                        else
                            rc = RESULT_FILE;
                    }
                }
            }
            else
                rc = FIND_OVERFLOW;
        }
        free_name_str(&find_country.name_country);
        free_name_str(&find_country.name_capital);
        fclose(f_in_2);
    }
    
    return rc;
}