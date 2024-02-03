#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define error codes for incorrect input
#define ERROR_INCORRECT_INPUT_PARAM 1
#define ERROR_INCORRECT_INPUT_MATRIX 2

// Define the expected number of arguments
#define NUMBER_OF_ARGUMENTS 1

// Define the maximum size of the matrix
#define N 10
#define M 10

// Reads a size_t parameter from the standard input and checks whether it is a valid input.
int input_matrix_param(size_t *x)
{
    int rc = scanf("%zu", x);
    // If scanf failed or the parameter is outside the allowed range, return an error code
    if ((rc != NUMBER_OF_ARGUMENTS) || (*x <= 0) || (*x > 10))
    {
        printf("Error: incorrect input\n");
        return ERROR_INCORRECT_INPUT_PARAM;
    }

    return EXIT_SUCCESS;
}

// Reads the matrix elements from the standard input and checks whether they are valid inputs.
int input_matrix(int matrix[][M], size_t n, size_t m)
{
    printf("Enter elements:\n");
    // Iterate over the rows and columns of the matrix
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            // Read an integer element from the standard input
            if (scanf("%d", &matrix[i][j]) != NUMBER_OF_ARGUMENTS)
            {
                // If scanf failed, return an error code
                printf("Error: incorrect input matrix\n");
                return ERROR_INCORRECT_INPUT_MATRIX;
            }
        }
    }

    return EXIT_SUCCESS;
}

// Combines the above two functions to read the matrix size and elements from the standard input.
int input(int matrix[][M], size_t *n, size_t *m)
{
    printf("Insert how many rows: ");
    // Read the number of rows from the standard input
    int error = input_matrix_param(n);
    if (error != EXIT_SUCCESS)
        return error;

    printf("Insert how many columns: ");
    // Read the number of columns from the standard input
    error = input_matrix_param(m);
    if (error != EXIT_SUCCESS)
        return error;

    // Read the matrix elements from the standard input
    error = input_matrix(matrix, *n, *m);
    if (error != EXIT_SUCCESS)
        return error;

    return EXIT_SUCCESS;
}

// Finds the columns where the elements alternate in sign by iterating over all columns and checking whether the product of any two consecutive elements in the column is negative.
void find_alternating_columns(int matrix[][M], size_t n, size_t m, int array[])
{
    // Iterate over the columns of the matrix
    for (size_t j = 0; j < m; j++)
    {
        // If there is only one row, the column cannot alternate in sign
        if (n == 1)
        {
            array[j] = 0;
            continue;
        }

        // Iterate over the rows of the column
        int alternate = true;
        for (size_t i = 0; i < n - 1; i++)
        {
            // If the product of two consecutive elements in the column is not negative, the column does not alternate in sign
            if (matrix[i][j] * matrix[i + 1][j] >= 0)
            {
                alternate = false;
                array[j] = 0;
                break;
            }
        }

        // If the column alternates in sign, mark it in the result
    if (alternate)
        array[j] = 1;
}
}

void print_array(int array[], size_t n)
/// Print the array after doing the loop
{
    printf("Print array:\n");
    for (size_t i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

#if 0
void print_matrix(int matrix[][M], size_t n, size_t m)
{
    printf("Print matrix:\n");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
                printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}
#endif

int main(void)
{
    /// Calling the functions then implementing
    int matrix[N][M];
    size_t n;
    size_t m;

    int error = input(matrix, &n, &m);
    if (error != EXIT_SUCCESS)
        return error;

    int array[N];

    find_alternating_columns(matrix, n, m, array);

    print_array(array, m);

    return EXIT_SUCCESS;
}

