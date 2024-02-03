#include "help_func.h"
#include <stdio.h>

// Function to print an array of integers
void print_arr(int arr[LEN], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
}

// Reverses an integer
void reverse(int *num)
{
    int temp = *num;
    *num = 0;

    while (temp)
    {
        *num = *num * 10 + temp % 10;
        temp /= 10;
    }
}

// Determines the length of an integer
int len_int_number(int num)
{
    int len = 0;
    while (num)
    {
        len++;
        num /= 10;
    }
    return len;
}

// Prints the attributes of a number structure
void print_struct(number_attributes num, int len)
{
    printf("\nSign: %d\nPower: %d\nExponent: %d\n", num.sign_number, num.power, num.exp);
    for (int i = 0; i < len; i++)
        printf("%d", num.mantissa[i]);
}

// Converts a character to an integer
int char_to_int(char symbol)
{
    return symbol - '0';
}

// Converts a string to lowercase
void lower(char *str)
{
    while (*str)
    {
        if ((*str >= 'A') && (*str <= 'Z'))
            *str += 'a' - 'A';
        str++;
    }
}

// Finds the first occurrence of a character in a string
int my_strchr(char *str, char symbol)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == symbol)
            return i;
    }
    return FALSE;
}

// Resets all fields of a structure to zero
void reset_to_zero(number_attributes *number)
{
    number->sign_number = 0;
    number->power = 0;
    number->exp = 0;
    for (int i = 0; i < LEN; i++)
        number->mantissa[i] = 0;
}

// Counts the number of occurrences of a symbol in a string
int count_symbol(char *str, char symbol)
{
    int count = 0;
    while (*str)
    {
        if (*str == symbol)
            count++;
        str++;
    }
    return count;
}

// Function to check the format of a number's representation
int format_numer(char number[LEN])
{
    while (*number)
    {
        if (*number == 'e')
            return 1;
        if (*number == '.' && count_symbol(number, 'e') == 0)
            return 2;
        number++;
    }
    return 3;
}

// Swaps two characters
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Determines whether a symbol is '+' or '-' (0 / 1)
int sign_of_number(char symbol)
{
    return symbol == '-' ? 1 : 0;
}

// Displays input boundaries
void convenient_input()
{
    puts("\n 1      10        20       30        40  1   5\
	  \n±|--------|---------|---------|---------|E±|---|");
}

void round_num(number_attributes *number, int last, int len) {
    int transfer = 0;
    int i = len - 1;
    while (i >= 0 && (last >= 5 || transfer)) {
        last = 0;
        if (number->mantissa[i] == 9) {
            number->mantissa[i] = 0;
            transfer = 1;
        } else {
            number->mantissa[i] += 1;
            transfer = 0;
        }
        i--;
    }
    if (transfer) {
        for (int j = MAX_LEN_INT - 1; j > 0; j--)
            number->mantissa[j] = number->mantissa[j - 1];

        number->exp++;
    }
}

// Requests user's desire to learn information.
void information()
{
    printf("\t Instructions:\
	\nMultiplication of a floating-point number by an integer!\
	\nInput is done without spaces!\
	\nThe '+' sign is not required.\
	\nMantissa should not exceed 40 significant digits.\
	\nExponent should not exceed 5 significant digits.\
	\nExamples of correct input: \
	\n12.345; 0.345; 2.34e-75; 1234.232e56;\n");
}
