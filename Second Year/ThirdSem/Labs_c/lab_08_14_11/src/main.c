#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_matrix.h"
#include "errors.h"
#include "memory_matrix.h"
#include "read_matrix.h"
#include "checks.h"
#include "sum_matrix.h"
#include "multiplication_matrix.h"
#include "find_inverse_matrix.h"
#include "fprint_matrix.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = EXIT_SUCCESS;
    rc = check_argc(argc, argv[1], MIN_ARGC, MAX_ARGC);
    if (rc == EXIT_SUCCESS)
    {
        char *action = argv[1];
        if (argc == SUM_OR_MULPTI)
        {
            FILE *f_matrix_1 = NULL, *f_matrix_2 = NULL, *f_result = NULL;
            f_matrix_1 = fopen(argv[2], "r");
            rc = check_file(f_matrix_1);
            if (rc == EXIT_SUCCESS)
            {
                f_matrix_2 = fopen(argv[3], "r");
                rc = check_file(f_matrix_2);
                if (rc == EXIT_SUCCESS)
                {
                    matrix_t matrix_1, matrix_2, result;
                    default_usual_matrix(&matrix_1);
                    default_usual_matrix(&matrix_2);
                    default_usual_matrix(&result);

                    rc = fread_usual_matrix(f_matrix_1, &matrix_1);
                    if (rc == EXIT_SUCCESS)
                    {
                        rc = fread_usual_matrix(f_matrix_2, &matrix_2);
                        if (rc == EXIT_SUCCESS)
                        {
                            if (strcmp(action, "a") == 0)
                            {
                                rc = sum_usual_matrix(&result, &matrix_1, &matrix_2);
                                if (rc == EXIT_SUCCESS)
                                {
                                    f_result = fopen(argv[4], "w");
                                    if (f_result != NULL)
                                    {
                                        fprint_usual_matrix(f_result, &result);
                                        fclose(f_result);
                                    }
                                    else
                                        rc = WRITE_ERROR;
                                }
                                free_matrix_third(&result.matrix);
                            }
                            else if (strcmp(action, "m") == 0)
                            {
                                rc = multiplication_usual_matrix(&result, &matrix_1, &matrix_2);
                                if (rc == EXIT_SUCCESS)
                                {
                                    f_result = fopen(argv[4], "w");
                                    if (f_result != NULL)
                                    {
                                        fprint_usual_matrix(f_result, &result);
                                        fclose(f_result);
                                    }
                                    else
                                        rc = WRITE_ERROR;
                                }
                                free_matrix_third(&result.matrix);
                            }
                            else
                                rc = ACTION_ERROR;
                        }
                        free_matrix_third(&matrix_2.matrix);
                    }
                    free_matrix_third(&matrix_1.matrix);
                    fclose(f_matrix_2);
                }
                fclose(f_matrix_1);	
            }
        }
        else if (argc == SPECIAL && strcmp(action, "o") == 0)
        {
            FILE *f_matrix = NULL, *f_result = NULL;
            f_matrix = fopen(argv[2], "r");
            rc = check_file(f_matrix);
            if (rc == EXIT_SUCCESS)
            {
                matrix_t result, matrix;
                default_usual_matrix(&matrix);
                default_usual_matrix(&result);

                rc = fread_usual_matrix(f_matrix, &matrix);
                if (rc == EXIT_SUCCESS)
                {
                    rc = gaussian_inverse_matrix(&result, &matrix);
                    if (rc == EXIT_SUCCESS)
                    {
                        f_result = fopen(argv[3], "w");
                        fprint_usual_matrix(f_result, &result);
                        fclose(f_result);
                    }
                }

                free_matrix_third(&matrix.matrix);
                free_matrix_third(&result.matrix);

                fclose(f_matrix);
            }
        }
        else
            rc = ACTION_ERROR;
    }
    return rc;
}
