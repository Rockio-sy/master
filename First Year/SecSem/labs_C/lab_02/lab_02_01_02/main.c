#include <stdio.h>
#include <stdlib.h>

// Define error codes for different error scenarios
#define ERROR_INCORRECT_INPUT_N 1
#define ERROR_INCORRECT_INPUT_ARRAY 2
#define ERROR_NO_NEGATIVE 3

// Define constants
#define NUMBER_OF_ARGUMENTS 1
#define N 10

// Function to input array elements
int input_array(int *a, size_t n)
{
    printf("Enter elements: ");
    for (size_t i = 0; i < n; i++)
    {
        // Input each element and check for incorrect input
        if (scanf("%d", &a[i]) != NUMBER_OF_ARGUMENTS)
        {
            printf("Error: incorrect input array\n");
            return ERROR_INCORRECT_INPUT_ARRAY;
        }
    }
    return EXIT_SUCCESS;
}

// Function to find the average of negative numbers in the array
int find_average_of_neg(int *a, size_t n)
{
    double average_neg = 0;
    int count_neg = 0;

    for (size_t i = 0; i < n; i++)
    {
        // Check if the current element is negative
        if (a[i] < 0)
        {
            // Accumulate the sum of negative numbers and count the number of negative numbers
            average_neg += a[i];
            count_neg++;
        }
    }

    // If no negative numbers found, return error
    if (count_neg == 0)
    {
        printf("Error: there are no negative numbers\n");
        return ERROR_NO_NEGATIVE;
    }

    // Calculate the average of negative numbers
    average_neg /= count_neg;

    // Print the calculated average
    printf("%lf", average_neg);

    return EXIT_SUCCESS;
}

int main(void)
{
    int a[N];
    size_t n;

    // Input the number of elements and check for incorrect input
    printf("Enter number of elements: ");
    if (scanf("%zu", &n) != NUMBER_OF_ARGUMENTS)
    {
        printf("Error: incorrect input n\n");
        return ERROR_INCORRECT_INPUT_N;
    }

    // Check if the number of elements is within the expected range
    if ((n <= 0) || (n > 10))
    {
        printf("Error: incorrect number of elements");
        return ERROR_INCORRECT_INPUT_N;
    }

    // Input the array elements
    int error = input_array(a, n);

    if (error != EXIT_SUCCESS)
    {
        return error;
    }

    // Find the average of negative numbers in the array
    error = find_average_of_neg(a, n);

    if (error != EXIT_SUCCESS)
        return error;

    return EXIT_SUCCESS;
}
