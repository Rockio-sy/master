#include <stdio.h>
#include <stdlib.h>

// Define the dimensions of the matrix
#define N 100
#define M 100

// Function to read input values from standard input into a matrix
int input(int matrix[][M], size_t *n, size_t *m)
{
    // Read the number of rows and columns from standard input
    printf("Enter the number of rows and columns of the matrix:\n");
    if (scanf("%zu%zu", n, m) != 2) {
        fprintf(stderr, "Failed to read matrix dimensions\n");
        return EXIT_FAILURE;
    }
    // Read the matrix values from standard input
    printf("Enter the values of the matrix:\n");
    for (size_t i = 0; i < *n; i++) {
        for (size_t j = 0; j < *m; j++) {
            printf("Insert the value at row %zu, column %zu:\n", i, j);
            if (scanf("%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Failed to read matrix value\n");
                return EXIT_FAILURE;
            }
        }
    }
    return EXIT_SUCCESS;
}


// Function to determine whether each column of a matrix is alternating
void find_alternating_columns(int matrix[][M], size_t n, size_t m, int array[])
{
    // Iterate over the columns of the matrix
    for (size_t j = 0; j < m; j++) {
        // Assume the column is alternating until proven otherwise
        int alternate = 1;
        // Iterate over the rows of the matrix
        for (size_t i = 0; i < n; i++) {
            // If the current row's value is not equal to the previous row's value,
            // then the column is not alternating
            if (i > 0 && matrix[i][j] != matrix[i-1][j]) {
                alternate = 0;
                break;
            }
        }
        // Store the result in the array
        if (alternate) {
            array[j] = 1;
        }
    }
}

// Function to print the values of an array
void print_array(int array[], size_t n)
{
    printf("Print array:\n");
    for (size_t i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

#if 0
// Function to print the values of a matrix
void print_matrix(int matrix[][M], size_t n, size_t m)
{
    printf("Print matrix:\n");
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
#endif

int main(void)
{
    // Declare the matrix and its dimensions
    int matrix[N][M];
    size_t n;
    size_t m;

    // Read input values into the matrix
    int error = input(matrix, &n, &m);
    if (error != EXIT_SUCCESS) {
        return error;
    }

    // Declare an array to store the results and determine which columns are alternating
    int array[N];
    find_alternating_columns(matrix, n, m, array);

    // Print the results to standard output
    print_array(array, m);

    return EXIT_SUCCESS;
}
