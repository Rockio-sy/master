#ifndef PRINT_H
#define PRINT_H

// Constants for return values and lengths
#define OK 0
#define LEN 100
#define NO 0
#define YES 1
#define TRUE 1
#define FALSE 0
#define ERROR_INPUT -1
#define EXIT 2
#define MAX_LEN_POW 99999
#define MAX_LEN_MANTISSA 40
#define MAX_LEN_INT 30
#define STRUCT_INIT {0, {0}, 0, 0}

// Structure containing characteristics of a number
typedef struct
{
    int sign_number;    // Sign of the number (0: +, 1: -)
    int mantissa[LEN];  // Mantissa of the number
    int power;          // Position of the decimal point
    int exp;            // Exponent of the number
} number_attributes;

// Function prototypes
int number_int(char number[MAX_LEN_INT]);
void print_arr(int arr[LEN], int len);
void reverse(int *num);
int len_int_number(int num);
void print_struct(number_attributes num, int len);
int char_to_int(char symbol);
int char_to_int_s(char *symbol);
void lower(char *str);
int my_strchr(char *str, char symbol);
void reset_to_zero(number_attributes *number);
int count_symbol(char *str, char symbol);
int correctness_number_int(char number[LEN]);
int correctness_number(char number[LEN]);
void round_num(number_attributes *number, int last, int len);
void multiplication(int arr1[LEN], int arr2[LEN], int len1, int len2, int arr_result[LEN]);
int exp_to_number(char str_number[LEN], number_attributes *number);
int float_to_number(char str_number[LEN], number_attributes *number);
void print_result(number_attributes number, int len);
int int_to_number(char str_number[LEN], number_attributes *number);
int format_numer(char number[LEN]);
void swap(char *a, char *b);
int sign_of_number(char symbol);
void convenient_input();
void information();

#endif
