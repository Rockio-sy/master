#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define FILE_OPEN_ERROR 1
#define PRODUCT_SCAN_ERROR 2
#define NOT_A_TYPED_FILE_ERROR 3
#define EMPTY_FILE 4
#define NO_MATCHES 5
#define INCORRECT_ARGS 53

#define NAME_LENGTH 31
#define MANUFACTURER_LENGTH 16

typedef struct
{
    char name[NAME_LENGTH];
    char manufacturer[MANUFACTURER_LENGTH];
    uint32_t unit_price;
    uint32_t unit_count;
} product_t;

size_t filesize(FILE *f);
int ending_with(char *str, char *substr);
void print_product(product_t *product);
int print_products_ending_with(char *filename, char *substr);
product_t get_by_pos(FILE *f, size_t pos);
void set_by_pos(FILE *f, size_t pos, product_t *product);
void swap(FILE *f, size_t pos1, size_t pos2);
int sort_by_price(char *filename);
int copy_file(char *filename_dst, char *filename_src);
int add_product(char *filename, product_t *product);
int scan_product(product_t *product);
int fscan_product(FILE *f, product_t *product);
int text_to_binary(char *filename);
int binary_to_text(char *filename);
