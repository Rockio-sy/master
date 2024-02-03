// Import necessary header files
#include <stdio.h>
#include <stdlib.h>

// Define error codes and constants
#define ERROR_INCORRECT_INPUT_PARAM 1
#define ERROR_INCORRECT_INPUT_MATRIX 2
#define NUMBER_OF_ARGUMENTS 1
#define N 10
#define M 10

// Function to read in a size_t parameter from the user
int input_matrix_param(size_t *x)
{
    int rc = scanf("%zu", x);  // Read in size_t from user
    // Check if input is valid
    if ((rc != NUMBER_OF_ARGUMENTS) || (*x <= 0) || (*x > 10))
    {
        printf("Error: incorrect input\n");  // Print error message
        return ERROR_INCORRECT_INPUT_PARAM;  // Return error code
    }

    return EXIT_SUCCESS;  // Return success code
}

// Function to read in a matrix from the user
int input_matrix(int matrix[][M], size_t n, size_t m)
{
    printf("Enter elements:\n");
    // Loop through each element in the matrix
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            if (scanf("%d", &matrix[i][j]) != NUMBER_OF_ARGUMENTS)
            {
                printf("Error: incorrect input matrix\n");  // Print error message
                return ERROR_INCORRECT_INPUT_MATRIX;  // Return error code
            }
        }

    return EXIT_SUCCESS;  // Return success code
}

// Function to read in the size of the matrix and the matrix itself from the user
int input(int matrix[][M], size_t *n, size_t *m)
{
    printf("Insert how many rows: ");
    int error = input_matrix_param(n);  // Read in n from user and check for errors
    if (error != EXIT_SUCCESS)
        return error;  // If error, return error code

    printf("Insert how many columns: ");
    error = input_matrix_param(m);  // Read in m from user and check for errors
    if (error != EXIT_SUCCESS)
        return error;  // If error, return error code

    error = input_matrix(matrix, *n, *m);  // Read in matrix from user and check for errors
    if (error != EXIT_SUCCESS)
        return error;  // If error, return error code

    return EXIT_SUCCESS;  // Return success code
}

// Function to print out the matrix
void print_matrix(int matrix[][M], size_t n, size_t m)
{
    printf("Print matrix:\n");
    // Loop through each row in the matrix
    for (size_t i = 0; i < n; i++)
    {
        // Loop through each element in the row
        for (size_t j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);  // Print out element
        printf("\n");  // Move to next row
    }
    printf("\n");  // Print new line for formatting
}

// Function to calculate the product of the elements in an array
int count_product(int array[], size_t n)
{
    int product = 1;
    // Loop through each element in the array
    for (size_t i = 0; i < n; i++)
        product *= array[i];  // Multiply current element with product so far

    return product;  // Return the final product
}
void swap_strings(int matrix[][M], size_t m, size_t a, size_t b)
{
    for (size_t j = 0; j < m; j++)
    {
        int temp = matrix[a][j];
        matrix[a][j] = matrix[b][j];
        matrix[b][j] = temp;
    }
}

void sort_strings(int matrix[][M], size_t n, size_t m)
// A function that swaps two rows in a 2D integer matrix
{
    for (size_t i = 0; i < n - 1; i++)
        // For every element in the row, swap the elements between the two rows
    {
        size_t min_string = i;
        for (size_t j = i + 1; j < n; j++)
        {
            if (count_product(matrix[j], m) < count_product(matrix[min_string], m))
                min_string = j;
        }

        if (min_string != i)
            swap_strings(matrix, m, i, min_string);
    }
}

int main(void)
{
    int matrix[N][M];
    size_t n;
    size_t m;
    // Get user input for the matrix dimensions and elements

    int error = input(matrix, &n, &m);
    if (error != EXIT_SUCCESS)
        return error;
    // Sort the rows of the matrix in ascending order based on their products

    sort_strings(matrix, n, m);

    /// Print the sorted matrix

    print_matrix(matrix, n, m);
    
    return EXIT_SUCCESS;
}
