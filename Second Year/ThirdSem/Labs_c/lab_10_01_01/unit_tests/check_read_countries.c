#include "check_read_countries.h"

#define UNIT_TESTS_FILE "unit_test.txt"
#define WRITE_SEQUENCE(fd, sequence) \
    rewind((fd));                    \
    fprintf((fd), sequence);         \
    rewind((fd))

void print_result_tests(char *name_func, int test_neg, int neg_failed, int test_pos, int pos_failed);

int tests_default_country(void)
{
    int pos_cnt = 0, test_pos = 1;

    {
        country_t country;
        default_country(&country);
        if (country.name_country != NULL || country.name_capital != NULL || country.population != 0)
            pos_cnt++;
    }

    print_result_tests((char *) __func__, 0, 0, test_pos, pos_cnt);

    return pos_cnt;
}

int tests_default_array_country(void)
{
    int pos_cnt = 0, test_pos = 1;

    {
        countries_t data;
        default_array_country(&data);
        if (data.array != NULL || data.size != 0)
            pos_cnt++;
    }

    print_result_tests((char *) __func__, 0, 0, test_pos, pos_cnt);

    return pos_cnt;
}

int tests_get_size_string(void)
{
    int pos_cnt = 0, test_pos = 3;

    int n;
    FILE *f = fopen(UNIT_TESTS_FILE, "w+");
    WRITE_SEQUENCE(f, "Hello\n");

    n = get_size_string(f);
    if (n != 5)
        pos_cnt++;

    WRITE_SEQUENCE(f, "Maggi Maggi");

    n = get_size_string(f);
    if (n != 11)
        pos_cnt++;

    n = get_size_string(NULL);
    if (n != 0)
        pos_cnt++;

    fclose(f);
    remove(UNIT_TESTS_FILE);

    print_result_tests((char *) __func__, 0, 0, test_pos, pos_cnt);

    return pos_cnt;
}

int tests_get_size_struct(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 2, test_pos = 4;

    {
        FILE *f = NULL;
        int rc = EXIT_SUCCESS;
        size_t n = 0;

        rc = get_size_struct(f, &n);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f, "Hello\n");

        rc = get_size_struct(f, NULL);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    {
        FILE *f = NULL;
        size_t len = 0;
        int rc = EXIT_SUCCESS;

        f = fopen(UNIT_TESTS_FILE, "w+");

        rc = get_size_struct(f, &len);
        if (rc != EXIT_SUCCESS || len != 0)
            pos_cnt++;

        WRITE_SEQUENCE(f, "Hello\n"
                          "Hello\n"
                          "Hello\n");

        rc = get_size_struct(f, &len);
        if (rc != EXIT_SUCCESS || len != 1)
            pos_cnt++;

        WRITE_SEQUENCE(f, "Hello\n"
                          "Hello\n"
                          "12121\n"
                          "Hello\n"
                          "Hello\n"
                          "11212\n");

        rc = get_size_struct(f, &len);
        if (rc != EXIT_SUCCESS || len != 2)
            pos_cnt++;

        WRITE_SEQUENCE(f, "Hello\n"
                          "Hello\n"
                          "12121\n"
                          "Hello\n"
                          "Hello\n"
                          "11212\nasasas");

        rc = get_size_struct(f, &len);
        if (rc != EXIT_SUCCESS || len != 0)
            pos_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_fread_name_str(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 4, test_pos = 2;

    {
        FILE *f = NULL;
        int rc = EXIT_SUCCESS;
        char *str = NULL;

        rc = fread_name_str(f, &str, 20);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        f = fopen(UNIT_TESTS_FILE, "w+");

        rc = fread_name_str(f, NULL, 20);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        rc = fread_name_str(f, &str, 0);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        rc = fread_name_str(f, &str, -100);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    {
        FILE *f = NULL;
        int rc = EXIT_SUCCESS, len = 30;
        char *str = NULL;

        f = fopen(UNIT_TESTS_FILE, "w+");
        WRITE_SEQUENCE(f, "Hello! I am student of BMSTU!\n");

        rc = fread_name_str(f, &str, len);
        if (rc != EXIT_SUCCESS || strcmp(str, "Hello! I am student of BMSTU!"))
            pos_cnt++;

        free_name_str(&str);
        if (str != NULL)
            pos_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    {
        FILE *f = NULL;
        int rc = EXIT_SUCCESS, len = 31;
        char *str = NULL;

        f = fopen(UNIT_TESTS_FILE, "w+");
        WRITE_SEQUENCE(f, "Hello! I am student of BMSTU!\n");

        rc = fread_name_str(f, &str, len);
        if (rc != EXIT_SUCCESS || strcmp(str, "Hello! I am student of BMSTU!"))
            pos_cnt++;

        free_name_str(&str);
        if (str != NULL)
            pos_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_fread_country_info(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 12, test_pos = 2;
    //PARAMS_ERROR
    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        country_t country;
        default_country(&country);

        f = fopen(UNIT_TESTS_FILE, "w+");
        WRITE_SEQUENCE(f, "Russia\nMoscow\n1700000000\n");

        rc = fread_country_info(NULL, &country, 0);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        rc = fread_country_info(f, NULL, 0);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    //ERR_IO
    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        country_t country;
        default_country(&country);

        f = fopen(UNIT_TESTS_FILE, "w+");

        rc = fread_country_info(f, &country, 0);
        if (rc != ERR_IO || country.name_country != NULL || country.name_capital != NULL || country.population != 0)
            neg_cnt++;

        WRITE_SEQUENCE(f, "Russia\nMoscow\n1700000000\n");
        rc = fread_country_info(f, &country, 0);
        if (rc != EXIT_SUCCESS)
            neg_cnt++;

        free_name_str(&country.name_country);
        free_name_str(&country.name_capital);
        default_country(&country);

        rc = fread_country_info(f, &country, 1);
        if (rc != ERR_IO || country.name_country != NULL || country.name_capital != NULL || country.population != 0)
            neg_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    //STRUCT_ERROR
    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        country_t country;
        default_country(&country);

        f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f, "      \nMoscow\n1700000000\n");
        rc = fread_country_info(f, &country, 0);
        if (rc != STRUCT_ERROR)
            neg_cnt++;

        free_name_str(&country.name_country);
        free_name_str(&country.name_capital);

        WRITE_SEQUENCE(f, "\nMoscow\n1700000000\n");
        rc = fread_country_info(f, &country, 0);
        if (rc != ERR_IO || country.name_country != NULL)
            neg_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        country_t country;
        default_country(&country);

        f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f, "Russia\n      \n1700000000\n");
        rc = fread_country_info(f, &country, 0);
        if (rc != STRUCT_ERROR)
            neg_cnt++;

        free_name_str(&country.name_country);
        free_name_str(&country.name_capital);

        WRITE_SEQUENCE(f, "Russia\n\n1700000000\n");
        rc = fread_country_info(f, &country, 0);
        if (rc != STRUCT_ERROR)
            neg_cnt++;

        free_name_str(&country.name_country);
        free_name_str(&country.name_capital);

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        country_t country;
        default_country(&country);

        f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f, "Russia\nMoscow\n \n");
        rc = fread_country_info(f, &country, 0);
        if (rc != STRUCT_ERROR)
            neg_cnt++;

        free_name_str(&country.name_country);
        free_name_str(&country.name_capital);

        WRITE_SEQUENCE(f, "Russia\nMoscow\n-1700000000\n");
        rc = fread_country_info(f, &country, 0);
        if (rc != STRUCT_ERROR)
            neg_cnt++;

        free_name_str(&country.name_country);
        free_name_str(&country.name_capital);

        WRITE_SEQUENCE(f, "Russia\nMoscow\n0\n");
        rc = fread_country_info(f, &country, 0);
        if (rc != STRUCT_ERROR)
            neg_cnt++;

        free_name_str(&country.name_country);
        free_name_str(&country.name_capital);

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    //POSITIVE
    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        country_t country;
        default_country(&country);

        f = fopen(UNIT_TESTS_FILE, "w+");
        WRITE_SEQUENCE(f, "Russia\nMoscow\n1700000000\n");

        rc = fread_country_info(f, &country, 0);
        if (rc != EXIT_SUCCESS || strcmp(country.name_country, "Russia") || strcmp(country.name_capital, "Moscow") || country.population != 1700000000)
            pos_cnt++;

        free_name_str(&country.name_country);
        free_name_str(&country.name_capital);

        WRITE_SEQUENCE(f, "Russia\nMoscow\n1700000000");

        rc = fread_country_info(f, &country, 0);
        if (rc != EXIT_SUCCESS || strcmp(country.name_country, "Russia") || strcmp(country.name_capital, "Moscow") || country.population != 1700000000)
            pos_cnt++;

        free_name_str(&country.name_country);
        free_name_str(&country.name_capital);

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_fread_countries(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 10, test_pos = 1;
    //PARAMS_ERROR
    {
        int rc = EXIT_SUCCESS, n = 0;
        FILE *f = NULL;
        countries_t countries;
        default_array_country(&countries);

        f = fopen(UNIT_TESTS_FILE, "w+");
        WRITE_SEQUENCE(f, "Russia\nMoscow\n1700000000\n");

        rc = fread_countries(NULL, &countries.array, &n);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        rc = fread_countries(f, NULL, &n);
        if (rc != PARAMS_ERROR)
            neg_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        countries_t countries;
        default_array_country(&countries);

        f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f, "USA\nVashigton\n129239928\n \nMoscow\n1700000000\n");
        rc = fread_countries(f, &countries.array, &countries.size);
        if (rc != STRUCT_ERROR)
            neg_cnt++;

        free_struct_country(&countries.array, &countries.size);

        WRITE_SEQUENCE(f, "USA\nVashigton\n129239928\n\nMoscow\n1700000000\n");
        rc = fread_countries(f, &countries.array, &countries.size);
        if (rc != STRUCT_ERROR)
            neg_cnt++;

        free_struct_country(&countries.array, &countries.size);

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        countries_t countries;
        default_array_country(&countries);

        f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f, "USA\nVashigton\n129239928\nRussia\n \n1700000000\n");
        rc = fread_countries(f, &countries.array, &countries.size);
        if (rc != STRUCT_ERROR)
            neg_cnt++;

        free_struct_country(&countries.array, &countries.size);

        WRITE_SEQUENCE(f, "USA\nVashigton\n129239928\nRussia\n\n1700000000\n");
        rc = fread_countries(f, &countries.array, &countries.size);
        if (rc != STRUCT_ERROR)
            neg_cnt++;

        free_struct_country(&countries.array, &countries.size);

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        countries_t countries;
        default_array_country(&countries);

        f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f, "USA\nVashigton\n129239928\nRussia\nMoscow\n \n");
        rc = fread_countries(f, &countries.array, &countries.size);
        if (rc != STRUCT_ERROR)
            neg_cnt++;

        free_struct_country(&countries.array, &countries.size);

        WRITE_SEQUENCE(f, "USA\nVashigton\n129239928\nRussia\nMoscow\n-1700000000\n");
        rc = fread_countries(f, &countries.array, &countries.size);
        if (rc != STRUCT_ERROR)
            neg_cnt++;

        free_struct_country(&countries.array, &countries.size);

        WRITE_SEQUENCE(f, "USA\nVashigton\n129239928\nRussia\nMoscow\n0\n");
        rc = fread_countries(f, &countries.array, &countries.size);
        if (rc != STRUCT_ERROR)
            neg_cnt++;

        free_struct_country(&countries.array, &countries.size);

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    //POSITIVE
    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        countries_t countries;
        default_array_country(&countries);

        f = fopen(UNIT_TESTS_FILE, "w+");
        WRITE_SEQUENCE(f, "USA\nVashigton\n129239928\nRussia\nMoscow\n1700000000\n");

        rc = fread_countries(f, &countries.array, &countries.size);
        if (rc != EXIT_SUCCESS)
            pos_cnt++;

        free_struct_country(&countries.array, &countries.size);

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}