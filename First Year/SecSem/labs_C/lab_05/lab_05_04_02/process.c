# include "process.h"

size_t filesize(FILE *f)
{
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    fseek(f, 0, SEEK_SET);
    return size;
}

int ending_with(char *str, char *substr)
{
    size_t str_len = strlen(str);
    size_t substr_len = strlen(substr);

    if (substr_len > str_len)
        return 0;
        
    do
    {
        str_len--;
        substr_len--;
        if (str[str_len] != substr[substr_len])
            return 0;
    } while (substr_len > 0);
    
    return 1;
}

void print_product(product_t *product)
{
    printf("%s\n%s\n%"PRIu32"\n%"PRIu32"\n", product->name, product->manufacturer, product->unit_price, product->unit_count);
}

int print_products_ending_with(char *filename, char *substr)
{
    FILE *f = fopen(filename, "rb");
    if (f == NULL)
        return 1;
    
    if (filesize(f) % sizeof(product_t) != 0)
        return 2;
    
    product_t product;
    size_t size = filesize(f) / sizeof(product_t);
    if (size == 0)
        return 3;

    int count = 0;
    for (size_t i = 0; i < size; i++)
    {
        fread(&product, sizeof(product_t), 1, f);
        if (ending_with(product.name, substr))
        {
            print_product(&product);
            count++;
        }
    }

    fclose(f);

    if (count == 0)
        return 4;

    return 0;
}


product_t get_by_pos(FILE *f, size_t pos)
{
    product_t product;

    fseek(f, 0, SEEK_SET);
    size_t product_size = sizeof(product_t);

    fseek(f, pos * product_size, SEEK_SET);
    fread(&product, product_size, 1, f);

    return product;
}

void set_by_pos(FILE *f, size_t pos, product_t *product)
{
    fseek(f, 0, SEEK_SET);
    size_t product_size = sizeof(product_t);

    fseek(f, pos * product_size, SEEK_SET);
    fwrite(product, product_size, 1, f);
}

void swap(FILE *f, size_t pos1, size_t pos2)
{
    size_t product_size = sizeof(product_t);

    // Read the products at the specified positions
    product_t product1, product2;

    fseek(f, pos1 * product_size, SEEK_SET);
    fread(&product1, product_size, 1, f);

    fseek(f, pos2 * product_size, SEEK_SET);
    fread(&product2, product_size, 1, f);

    // Write the products back to their respective positions
    fseek(f, pos1 * product_size, SEEK_SET);
    fwrite(&product2, product_size, 1, f);

    fseek(f, pos2 * product_size, SEEK_SET);
    fwrite(&product1, product_size, 1, f);
}

int sort_by_price(char *filename)
{
    FILE *f = fopen(filename, "r+b");
    if (f == NULL)
        return 1;

    if (filesize(f) % sizeof(product_t) != 0)
        return 2;

    size_t size = filesize(f) / sizeof(product_t);
    if (size == 0)
        return 3;

    // Read all products into an array
    product_t *products = malloc(size * sizeof(product_t));
    if (products == NULL)
    {
        fclose(f);
        return 4;
    }

    fseek(f, 0, SEEK_SET);
    fread(products, sizeof(product_t), size, f);

    // Perform bubble sort based on price and unit count
    for (size_t i = size - 1; i > 0; i--)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (products[j].unit_price < products[j + 1].unit_price)
            {
                product_t temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
            else if (products[j].unit_price == products[j + 1].unit_price && products[j].unit_count < products[j + 1].unit_count)
            {
                product_t temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }

    // Write the sorted products back to the file
    fseek(f, 0, SEEK_SET);
    fwrite(products, sizeof(product_t), size, f);

    fclose(f);
    free(products);

    return 0;
}

int copy_file(char *filename_dst, char *filename_src)
{
    FILE *src = fopen(filename_src, "rb");
    if (src == NULL)
        return 1;

    if (strcmp(filename_dst, filename_src) == 0)
    {
        fclose(src);
        return 0;
    }

    FILE *dst = fopen(filename_dst, "wb");
    if (dst == NULL)
    {
        fclose(src);
        return 1;
    }

    fseek(src, 0, SEEK_END);
    long file_size = ftell(src);
    rewind(src);

    size_t num_elements = file_size / sizeof(product_t);
    if (num_elements == 0)
    {
        fclose(src);
        fclose(dst);
        return 3;
    }

    product_t *products = malloc(num_elements * sizeof(product_t));
    if (products == NULL)
    {
        fclose(src);
        fclose(dst);
        return 4;
    }

    fread(products, sizeof(product_t), num_elements, src);
    fwrite(products, sizeof(product_t), num_elements, dst);

    fclose(src);
    fclose(dst);
    free(products);

    return 0;
}

int add_product(char *filename, product_t *product)
{
    FILE *f = fopen(filename, "r+b");
    if (f == NULL)
        return 1;

    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    size_t num_elements = file_size / sizeof(product_t);

    if (file_size % sizeof(product_t) != 0)
    {
        fclose(f);
        return 2;
    }

    product_t *products = malloc((num_elements + 1) * sizeof(product_t));
    if (products == NULL)
    {
        fclose(f);
        return 3;
    }

    fseek(f, 0, SEEK_SET);
    fread(products, sizeof(product_t), num_elements, f);

    size_t insert_index = 0;
    while (insert_index < num_elements && (product->unit_price < products[insert_index].unit_price || (product->unit_price == products[insert_index].unit_price && product->unit_count < products[insert_index].unit_count)))
    {
        insert_index++;
    }

    memmove(&products[insert_index + 1], &products[insert_index], (num_elements - insert_index) * sizeof(product_t));
    products[insert_index] = *product;

    fseek(f, 0, SEEK_SET);
    fwrite(products, sizeof(product_t), num_elements + 1, f);

    fclose(f);
    free(products);

    return 0;
}


int scan_product(product_t *product)
{
    memset(product, 0, sizeof(product_t));

    char input_buffer[256]; // Buffer to store user input

    printf("Please enter the product name: ");
    if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL)
        return 1;
    if (input_buffer[strlen(input_buffer) - 1] == '\n')
        input_buffer[strlen(input_buffer) - 1] = '\0';
    strncpy(product->name, input_buffer, sizeof(product->name) - 1);

    printf("Please enter the manufacturer of the product: ");
    if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL)
        return 1;
    if (input_buffer[strlen(input_buffer) - 1] == '\n')
        input_buffer[strlen(input_buffer) - 1] = '\0';
    strncpy(product->manufacturer, input_buffer, sizeof(product->manufacturer) - 1);

    printf("Please enter the unit price of the product: ");
    if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL)
        return 1;
    if (sscanf(input_buffer, "%" SCNu32, &product->unit_price) != 1)
        return 1;

    printf("Please enter the number of units of the product: ");
    if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL)
        return 1;
    if (sscanf(input_buffer, "%" SCNu32, &product->unit_count) != 1)
        return 1;

    return 0;
}
int fscan_product(FILE *f, product_t *product)
{
    memset(product, 0, sizeof(product_t));

    char input_buffer[256]; // Buffer to store file input

    if (fgets(input_buffer, sizeof(input_buffer), f) == NULL)
        return 0;
    if (input_buffer[strlen(input_buffer) - 1] == '\n')
        input_buffer[strlen(input_buffer) - 1] = '\0';
    strncpy(product->name, input_buffer, sizeof(product->name) - 1);

    if (fgets(input_buffer, sizeof(input_buffer), f) == NULL)
        return 0;
    if (input_buffer[strlen(input_buffer) - 1] == '\n')
        input_buffer[strlen(input_buffer) - 1] = '\0';
    strncpy(product->manufacturer, input_buffer, sizeof(product->manufacturer) - 1);

    if (fscanf(f, "%" SCNu32, &product->unit_price) != 1)
        return 0;

    if (fscanf(f, "%" SCNu32, &product->unit_count) != 1)
        return 0;

    fgetc(f); // Consume the newline character

    return 1;
}


int text_to_binary(char *filename)
{
    FILE *src = fopen(filename, "r");
    if (src == NULL)
        return 1;

    FILE *dst = fopen("out.tmp", "wb");
    if (dst == NULL)
    {
        fclose(src);
        return 1;
    }

    product_t product;
    char input_buffer[256]; // Buffer to store file input

    while (fgets(input_buffer, sizeof(input_buffer), src) != NULL)
    {
        // Remove newline character from the input_buffer
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        // Populate the product structure
        strncpy(product.name, input_buffer, sizeof(product.name) - 1);
        product.name[sizeof(product.name) - 1] = '\0';

        if (fgets(input_buffer, sizeof(input_buffer), src) == NULL)
            break;
        input_buffer[strcspn(input_buffer, "\n")] = '\0'; // Remove newline character
        strncpy(product.manufacturer, input_buffer, sizeof(product.manufacturer) - 1);
        product.manufacturer[sizeof(product.manufacturer) - 1] = '\0';

        if (fscanf(src, "%" SCNu32, &product.unit_price) != 1)
            break;

        if (fscanf(src, "%" SCNu32, &product.unit_count) != 1)
            break;

        fgetc(src); // Consume the newline character

        // Write the product structure to the binary file
        fwrite(&product, sizeof(product_t), 1, dst);
    }

    fclose(dst);
    fclose(src);

    rename("out.tmp", filename);

    return 0;
}


int binary_to_text(char *filename)
{
    FILE *src = fopen(filename, "rb");
    if (src == NULL)
        return 1;

    FILE *dst = fopen("out.tmp", "w");
    if (dst == NULL)
    {
        fclose(src);
        return 1;
    }

    product_t product;

    if (filesize(src) % sizeof(product_t) != 0)
    {
        fclose(dst);
        fclose(src);
        return 2;
    }

    size_t size = filesize(src) / sizeof(product_t);

    for (size_t i = 0; i < size; i++)
    {
        fread(&product, sizeof(product_t), 1, src);
        fprintf(dst, "%s\n%s\n%" PRIu32 "\n%" PRIu32 "\n", product.name, product.manufacturer, product.unit_price, product.unit_count);
    }

    fclose(dst);
    fclose(src);

    rename("out.tmp", filename);

    return 0;
}
