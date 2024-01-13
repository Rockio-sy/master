#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_INCORRECT_INPUT_PARAM 1
#define ERROR_INCORRECT_INPUT_MATRIX 2
#define ERROR_NO_PRIME 3

#define NUMBER_OF_ARGUMENTS 1
#define N 10
#define M 10

// Function to read in the value of n or m
int input_matrix_param(size_t *x)
{
    // Read in size_t value from user input
    int rc = scanf("%zu", x);

    // Check if input is valid
    if ((rc != NUMBER_OF_ARGUMENTS) || (*x <= 0) || (*x > 10))
    {
        // Print error message and return error code
        printf("Error: incorrect input\n");
        return ERROR_INCORRECT_INPUT_PARAM;
    }

    // Return success code
    return EXIT_SUCCESS;
}

// Function to read in a matrix of size n x m
int input_matrix(int matrix[][M], size_t n, size_t m)
{
    // Print message to prompt user for input
    printf("Enter elements:\n");

    // Iterate through rows and columns of matrix to read in values
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
        {
            // Read in integer value from user input
            if (scanf("%d", &matrix[i][j]) != NUMBER_OF_ARGUMENTS)
            {
                // Print error message and return error code if input is invalid
                printf("Error: incorrect input matrix\n");
                return ERROR_INCORRECT_INPUT_MATRIX;
            }
        }

    // Return success code
    return EXIT_SUCCESS;
}

// Function to read in matrix size and values
int input(int matrix[][M], size_t *n, size_t *m)
{
    // Prompt user for input of n
    printf("Insert how many rows: ");

    // Read in value of n
    int error = input_matrix_param(n);
    if (error != EXIT_SUCCESS)
        return error;

    // Prompt user for input of m
    printf("Insert how many columns: ");
    error = input_matrix_param(m);
    if (error != EXIT_SUCCESS)
        return error;

    // Read in matrix values
    error = input_matrix(matrix, *n, *m);
    if (error != EXIT_SUCCESS)
        return error;

    // Return success code
    return EXIT_SUCCESS;
}

// Function to print matrix values
void print_matrix(int matrix[][M], size_t n, size_t m)
{
    // Print message to indicate printing matrix
    printf("Print matrix:\n");

    // Iterate through rows and columns of matrix to print values
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Function to check if a number is prime
int is_prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// Function to collect prime numbers in matrix and store them in an array
int collect_prime(int matrix[][M], size_t n, size_t m, int array_prime[], size_t *size_arr)
{
    // Iterate through rows and columns of matrix to check for prime numbers
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (is_prime(matrix[i][j]))
            {
                array_prime[*size_arr] = matrix[i][j];
                (*size_arr)++;
            }

    if (*size_arr == 0)
    {
        printf("Error: no prime elements\n");
        return ERROR_NO_PRIME;
    }

    return EXIT_SUCCESS;
}

void reverse_array(int array[], int n)
/// Function to reverse the array...
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = array[i];
        array[i] = array[n - 1 - i];
        array[n - 1 - i] = temp;
    }
}

void fill_matrix(int matrix[][M], size_t n, size_t m, int array_prime[])
/// Function to fill the matrix after implementation
{
    int index = 0;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (is_prime(matrix[i][j]))
            {
                matrix[i][j] = array_prime[index];
                index++;
            }
        }   
    }
}

int main(void)
{
    int matrix[N][M];
    size_t n;
    size_t m;

    int error = input(matrix, &n, &m);
    if (error != EXIT_SUCCESS)
        return error;

    int array_prime[N * M];
    size_t size_arr = 0;

    error = collect_prime(matrix, n, m, array_prime, &size_arr);
    if (error != EXIT_SUCCESS)
        return error;

    reverse_array(array_prime, size_arr);

    fill_matrix(matrix, n, m, array_prime);

    print_matrix(matrix, n, m);
    
    return EXIT_SUCCESS;
}
