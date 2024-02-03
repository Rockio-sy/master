# include "process.h"

int main(int argc, char **argv)
{
    if (argc < 3)
        return INCORRECT_ARGS;

    if (strcmp(argv[1], "sb") == 0)
    {
        if (argc != 4)
            return INCORRECT_ARGS;

        int rc = copy_file(argv[3], argv[2]);
        if (rc == 1)
            return FILE_OPEN_ERROR;
        if (rc == 2)
            return NOT_A_TYPED_FILE_ERROR;
        if (rc == 3)
            return EMPTY_FILE;

        rc = sort_by_price(argv[3]);
        if (rc == 1)
            return FILE_OPEN_ERROR;
        if (rc == 2)
            return NOT_A_TYPED_FILE_ERROR;
        if (rc == 3)
            return EMPTY_FILE;
    }
    else if (strcmp(argv[1], "fb") == 0)
    {
        if (argc != 4)
            return INCORRECT_ARGS;

        int rc = print_products_ending_with(argv[2], argv[3]);
        if (rc == 1)
            return FILE_OPEN_ERROR;
        if (rc == 2)
            return NOT_A_TYPED_FILE_ERROR;
        if (rc == 3)
            return EMPTY_FILE;
        if (rc == 4)
            return NO_MATCHES;
    }
    else if (strcmp(argv[1], "ab") == 0)
    {
        if (argc != 3)
            return INCORRECT_ARGS;

        product_t new_product;
        int rc = scan_product(&new_product);
        if (rc == 1)
            return PRODUCT_SCAN_ERROR;

        rc = add_product(argv[2], &new_product);
        if (rc == 1)
            return FILE_OPEN_ERROR;
        if (rc == 2)
            return NOT_A_TYPED_FILE_ERROR;
    }
    else if (strcmp(argv[1], "t2b") == 0)
    {
        if (argc != 3)
            return INCORRECT_ARGS;

        int rc = text_to_binary(argv[2]);
        if (rc == 1)
            return FILE_OPEN_ERROR;
    }
    else if (strcmp(argv[1], "b2t") == 0)
    {
        if (argc != 3)
            return INCORRECT_ARGS;

        int rc = binary_to_text(argv[2]);
        if (rc == 1)
            return FILE_OPEN_ERROR;
        if (rc == 2)
            return NOT_A_TYPED_FILE_ERROR;
    }
    else
        return INCORRECT_ARGS;

    return EXIT_SUCCESS;
}
