#include <stdio.h>
#include "help_func.h" // Include any necessary header files here

int main(void) {
    information();
    puts("To exit, type \"exit\"");

    char str_number[LEN];
    int correct = 0;
    int len1, len2;
    // Create 3 structures to store information about numbers
    // and initialize all fields to zero.
    number_attributes first_number = STRUCT_INIT;
    number_attributes second_number = STRUCT_INIT;
    number_attributes result_number = STRUCT_INIT;

    // The loop continues until the user enters "exit"
    while (correct != EXIT) {
        // Reset all structure fields to zero.
        reset_to_zero(&first_number);
        reset_to_zero(&second_number);
        reset_to_zero(&result_number);

        convenient_input();
        puts("\nEnter the first number: ");
        scanf("%s", str_number);
        correct = correctness_number(str_number);
        while (correct < 0) {
            puts("\nEnter a correct number:");
            scanf("%s", str_number);
            correct = correctness_number(str_number);
        }

        if (correct == EXIT)
            return OK;

        if (format_numer(str_number) == 1)
            len1 = exp_to_number(str_number, &first_number);
        else if (format_numer(str_number) == 2)
            len1 = float_to_number(str_number, &first_number);
        else
            len1 = int_to_number(str_number, &first_number);

        if (len1 > MAX_LEN_MANTISSA) {
            puts("Mantissa is too large");
            continue;
        }

        puts("Enter the second number: ");
        scanf("%s", str_number);
        correct = number_int(str_number);
        while (correct < 0) {
            puts("\nEnter a correct number:");
            scanf("%s", str_number);
            correct = number_int(str_number);
        }
        if (correct == EXIT)
            return OK;
        len2 = int_to_number(str_number, &second_number);

        if (len2 > MAX_LEN_INT) {
            puts("Integer is too large");
            continue;
        }

        // Multiplication
        multiplication(first_number.mantissa, second_number.mantissa, len1,
                       len2, result_number.mantissa);
        // Record information in the corresponding fields (result)
        result_number.sign_number = first_number.sign_number ^ second_number.sign_number;
        result_number.power = first_number.power + second_number.power;
        result_number.exp = first_number.exp + second_number.exp;

        puts("\nMultiplication of numbers");

        // Change text color
        printf("\nRESULT\n");
        print_result(result_number, len1 + len2);
    }
}
