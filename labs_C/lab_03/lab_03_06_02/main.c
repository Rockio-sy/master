#include <stdio.h>
#include <stdlib.h>

// Define constants to be used in the program
#define ERROR_INCORRECT_INPUT_PARAM 1
#define NUMBER_OF_ARGUMENTS 1
#define N 10
#define M 10

// Function to read a positive integer from the user
// and return an error code if the input is invalid
int input_matrix_param(size_t *x)
{
    int rc = scanf("%zu", x); // read an integer from user input
    if ((rc != NUMBER_OF_ARGUMENTS) || (*x <= 0) || (*x > 10)) // check if input is invalid
    {
        printf("Error: incorrect input\n"); // print error message to console
        return ERROR_INCORRECT_INPUT_PARAM; // return error code
    }
    return EXIT_SUCCESS; // return success code
}

// Function to fill a two-dimensional integer array with consecutive integers
// using a specific pattern
void fill_matrix(int matrix[][M], size_t n, size_t m)
{
    printf("Enter elements:\n"); // print prompt message to console
    int number = 1; // initialize the first number to be placed in the matrix
    for (size_t j = 0; j < m; j++) // loop through each column
        for (size_t i = 0; i < n; i++) // loop through each row
        {
            size_t index_j = m - 1 - j; // calculate the index for the current column
            size_t index_i;
            if (j % 2 == 0) // check if the current column is even
                index_i = n - 1 - i; // if it is, fill the row from right to left
            else
                index_i = i; // if it isn't, fill the row from left to right
            matrix[index_i][index_j] = number; // place the current number in the matrix
            number++; // increment the number
        }
}

// Function to print the contents of a two-dimensional integer array to the console
void print_matrix(int matrix[][M], size_t n, size_t m)
{
    printf("Print matrix:\n"); // print prompt message to console
    for (size_t i = 0; i < n; i++) // loop through each row
    {
        for (size_t j = 0; j < m; j++) // loop through each column in the current row
            printf("%d ", matrix[i][j]); // print the current element of the matrix
        printf("\n"); // print a newline character to start a new row
    }
    printf("\n"); // print an additional newline character for formatting
}

// Main function that controls the flow of the program
int main(void)
{
    int matrix[N][M]; // declare a two-dimensional integer array
    size_t n; // declare a variable to hold the number of rows
    size_t m; // declare a variable to hold the number of columns

    printf("How many rows: "); // print prompt message to console
    int error = input_matrix_param(&n); // read the number of rows from user input
    if (error != EXIT_SUCCESS) // check if an error occurred
        return error; // if so, return the error code

    printf("How many columns: "); // print prompt message to console
    error = input_matrix_param(&m); // read the number of columns from user input
    if (error != EXIT_SUCCESS) // check if an error occurred
        return error; // if so

    fill_matrix(matrix, n, m);//Fill the matrix after implementation
    print_matrix(matrix, n, m);//Print the matrix/array
    
    return EXIT_SUCCESS;
}
