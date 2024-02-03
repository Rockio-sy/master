#include "errors.h"
#include "checks.h"
#include "memory_countries.h"
#include "read_countries.h"
#include "struct_list.h"
#include "print_countries.h"
#include "struct_country.h"
#include "memory_list.h"
#include "key_processor.h"
#include "operations_with_list.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = EXIT_SUCCESS;

    char *action = argv[1];
    rc = check_argc(argc, action, MIN_ARGV, MAX_ARGV);
    if (rc == EXIT_SUCCESS)
    {
        FILE *f_in_1 = NULL;
        f_in_1 = fopen(argv[2], "r");
        rc = check_file(f_in_1);
        if (rc == EXIT_SUCCESS)
        {
            countries_t countries_1;
            default_array_country(&countries_1);
            rc = fread_countries(f_in_1, &countries_1.array, &countries_1.size);
            if (rc == EXIT_SUCCESS)
            {
                node_t *head = NULL;

                for (int i = 0; i < countries_1.size && !rc; i++)
                    rc = list_push(&head, countries_1.array + i);
                if (rc == EXIT_SUCCESS)
                {
                    if (argc == MIN_ARGV)
                    {
                        if (strcmp("pf", action) == 0)
                        {
                            processor_key_pf(&head);
                            rc = fwrite_countries(argv[3], head);
                        }
                        else if (strcmp("pb", action) == 0)
                        {
                            processor_key_pb(&head);
                            rc = fwrite_countries(argv[3], head);
                        }
                        else if (strcmp("s", action) == 0)
                        {
                            head = sort(head, (int (*)(const void *, const void *)) comparator_name_country);
                            if (head != NULL)
                            {
                                rc = fwrite_countries(argv[3], head);
                            }
                        }
                    }
                    else if (argc == MAX_ARGV)
                    {
                        if (strcmp("a", action) == 0)
                            rc = processor_key_a(&head, argv[3], argv[4]);
                        else if (strcmp("f", action) == 0)
                            rc = processor_key_f(&head, argv[3], argv[4]);
                    }
                }
                free_list(&head);
            }
            free_struct_country(&countries_1.array, &countries_1.size);
            fclose(f_in_1);
        }
    }

    if (rc != EXIT_SUCCESS)
        print_error(rc);

    return rc;
}