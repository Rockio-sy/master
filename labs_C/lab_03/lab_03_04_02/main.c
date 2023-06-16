#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define error codes as constants
#define ERROR_INCORRECT_INPUT_PARAM 1
#define ERROR_INCORRECT_INPUT_MATRIX 2
#define ERROR_NO_NUMBERS 3
#define ERROR_NOT_SQUARE 4

// define other constants
#define NUMBER_OF_ARGUMENTS 1
#define N 10

// function to read the size of the matrix from the user
int input_matrix_param(size_t *x)
{
    // read the size of the matrix from the user
    int rc = scanf("%zu", x);

    // check if the input is invalid
    if ((rc != NUMBER_OF_ARGUMENTS) || (*x <= 0) || (*x > 10))
    {
        // output an error message and return an error code
        printf("Error: incorrect input\n");
        return ERROR_INCORRECT_INPUT_PARAM;
    }

    // return success code
    return EXIT_SUCCESS;
}

// function to read the elements of the matrix from the user
int input_matrix(int matrix[][N], size_t n)
{
    // output a prompt for the user to enter the elements
    printf("Enter elements:\n");

    // read the elements of the matrix from the user
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
        {
            if (scanf("%d", &matrix[i][j]) != NUMBER_OF_ARGUMENTS)
            {
                // output an error message and return an error code if the input is invalid
                printf("Error: incorrect input matrix\n");
                return ERROR_INCORRECT_INPUT_MATRIX;
            }
        }

    // return success code
    return EXIT_SUCCESS;
}

// function to read the size and elements of the matrix from the user
int input(int matrix[][N], size_t *n, size_t *m)
{
    // output a prompt for the user to enter the size of the matrix
    printf("Insert How many rows: ");

    // read the size of the matrix from the user and check for errors
    int error = input_matrix_param(n);
    if (error != EXIT_SUCCESS)
        return error;

    // output a prompt for the user to enter the size of the matrix
    printf("Insert how many columns: ");

    // read the size of the matrix from the user and check for errors
    error = input_matrix_param(m);
    if (error != EXIT_SUCCESS)
        return error;

    // check if the matrix is square
    if (*n != *m)
    {
        // output an error message and return an error code if the matrix is not square
        printf("Error: Not a square matrix\n");
        return ERROR_NOT_SQUARE;
    }

    // read the elements of the matrix from the user and check for errors
    error = input_matrix(matrix, *n);
    if (error != EXIT_SUCCESS)
        return error;

    // return success code
    return EXIT_SUCCESS;
}

// function to search for the largest element in the lower triangular part of the matrix that ends with 5
int find_max_under_side(int matrix[][N], size_t n, int *max)
{
    // initialize variables
    int has_number = false;

    // loop through the lower triangular part of the matrix and search for the largest element that ends with 5
    for (size_t i = 1; i < n; i++)
        for (size_t j = n - i; j < n; j++)
        {
            int element = matrix[i][j];
            if (abs(element) % 10 == 5 && (!has_number || *max < element))
            {
                has_number = true;
                *max = element;
            }
        }

    if (has_number == false)
    /// If there isn't number ends with 5 --> Error
    {
        printf("Error: No numbers ends with five\n");
        return ERROR_NO_NUMBERS;
    }

    return EXIT_SUCCESS;    
}

int main(void)
{
    /// Calling the functions
    int matrix[N][N];
    size_t n;
    size_t m;

    int error = input(matrix, &n, &m);
    if (error != EXIT_SUCCESS)
        return error;

    int max_number;

    error = find_max_under_side(matrix, n, &max_number);
    if (error != EXIT_SUCCESS)
        return error;

    printf("Max number: %d\n", max_number);
    
    return EXIT_SUCCESS;
}
