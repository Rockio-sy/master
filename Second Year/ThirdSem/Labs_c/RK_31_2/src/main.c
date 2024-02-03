#include "/home/rockio/sec_year/Labs_c/RK_31_2/inc/errs.h"

int isPalindrome(int num) {
    // Function to find palindrome number
    int original = num;
    int reverse = 0;
    while (num > 0) {
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        num /= 10;
    }
    return original == reverse;
}

void sortArray(int* arr, int size){
    // Function to sort the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int** allocateMatrix(int rows, int cols) {
    // Function to allocate the matrix
    int** matrix = (int**)malloc(rows * sizeof(int*));
    if (!matrix) {
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        if (!matrix[i]) {
            // Check memory
            for (int u = 0; u < i; u++) {
                free(matrix[u]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main(int argc, char* argv[]) {

    if (argc != 3){
        return ERR_ARG;
    }
    // Open the input file for reading
    FILE* input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening input.txt");
        return ERR_OPEN_FILE;
    }

    // Read matrix dimensions
    int rows, cols;
    if (fscanf(input, "%d %d", &rows, &cols) != 2) {
        fclose(input);  // Close the input file
        return ERR_IO_OR_EMPTY;
    }
    if (rows <= 0 || cols <= 0) {
        fclose(input);  // Close the input file
        return ERR_DIM;
    }

    // Dynamically allocate memory for the matrix
    int** matrix = allocateMatrix(rows, cols);
    if (!matrix) {
        fclose(input);  // Close the input file
        return ERR_ALLOC;
    }

    // Read matrix values from the input file
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(input, "%d", &matrix[i][j]) != 1) {
                fclose(input);  // Close the input file
                freeMatrix(matrix, rows); // Free matrix memory
                return ERR_IO_OR_EMPTY;
            }
        }
    }

    // Create an array for palindromic numbers
    int* palindromes = (int*)malloc(rows * cols * sizeof(int));
    if (!palindromes) {
        fclose(input);  // Close the input file
        freeMatrix(matrix, rows); // Free matrix memory
        return ERR_ALLOC;
    }
    int palindromesCount = 0;


    // Extract palindromic numbers and store them in the palindromes array
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (isPalindrome(matrix[i][j])) {
                palindromes[palindromesCount++] = matrix[i][j];
            }
        }
    }

    if (palindromesCount > 0) {
        // Sort the palindromic numbers
        sortArray(palindromes, palindromesCount);

        // Return the sorted elements to the matrix
        int p = 0;
        for (int j = 0; j < cols; j++) {
            for (int i = 0; i < rows; i++) {
                if (isPalindrome(matrix[i][j])) {
                    matrix[i][j] = palindromes[p++];
                }
            }
        }
    } else {
        printf("No palindromic numbers found in the matrix.\n");
    }

    // Open the output file for writing
    FILE* output = fopen(argv[2], "w");
    if (!output) {
        perror("Error opening output.txt");
        fclose(input); // Close the input file
        freeMatrix(matrix, rows); // Free matrix memory
        free(palindromes); // Free palindromes array
        return ERR_OPEN_FILE;
    }

    // Write the updated matrix to the output file
    fprintf(output, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(output, "%d ", matrix[i][j]);
        }
        fprintf(output, "\n");
    }

    // Close files and free memory
    fclose(input);
    fclose(output);
    freeMatrix(matrix, rows);
    free(palindromes);

    return 0;
}
