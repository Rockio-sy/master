#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIGITS 10

int* read_digits() {
    char input[MAX_DIGITS+2]; // allow for MAX_DIGITS digits plus a newline and null terminator
    int num_digits = 0;
    int* digits = malloc(sizeof(int) * MAX_DIGITS);

    if (digits == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        return NULL;
    }

    printf("Enter up to %d digits followed by Enter:\n", MAX_DIGITS);

    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        free(digits);
        return NULL;
    }

    // check if input was too long
    if (strlen(input) > MAX_DIGITS+1 || (strlen(input) == MAX_DIGITS+1 && input[MAX_DIGITS] != '\n')) {
        fprintf(stderr, "Input must be up to %d digits\n", MAX_DIGITS);
        free(digits);
        return NULL;
    }

    // remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // convert input to array of digits
    for (int i = 0; i < strlen(input); i++) {
        if (num_digits >= MAX_DIGITS) {
            break;
        }
        if (input[i] < '0' || input[i] > '9') {
            fprintf(stderr, "Invalid input: must be digits only\n");
//            free(digits);
            return NULL;
        }
        digits[num_digits++] = input[i] - '0';
    }

    int* resized_digits = realloc(digits, sizeof(int) * num_digits);
    if (resized_digits == NULL) {
        fprintf(stderr, "Error allocating memory\n");
//        free(digits);
        return NULL;
    }

    return resized_digits;
}
int* remove_duplicates(int* arr, int size, int* new_size) {
    int* result = malloc(sizeof(int) * size);
    if (result == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        return NULL;
    }
    int num_duplicates = 0;
    for (int i = 0; i < size; i++) {
        int is_duplicate = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            result[num_duplicates++] = arr[i];
        }
    }
    int* resized_result = realloc(result, sizeof(int) * num_duplicates);
    if (resized_result == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        free(result);
        return NULL;
    }
    *new_size = num_duplicates;
    return resized_result;
}
void reverse_array(int* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main() {
    int* digits = read_digits();
    if (digits == NULL) {
        return 1;
    }
    int num_digits = 0;
    int* unique_digits = remove_duplicates(digits, MAX_DIGITS, &num_digits);
    free(digits);
    if (unique_digits == NULL) {
        return 1;
    }
    printf("Unique digits entered (%d total):\n", num_digits - 1);
    for (int i = 0; i < num_digits - 1; i++) {
        printf("%d ", unique_digits[i]);
    }
    printf("\n");
//    free(unique_digits);
    reverse_array(unique_digits, num_digits);
    printf("Unique digits entered in reverse order (%d total):\n", num_digits - 1);
    for (int i = 0; i < num_digits; i++) {
        if ("%d",unique_digits[i] != 0 ){
            printf("%d ", unique_digits[i]);
        }
    }
    printf("\n");

    return 0;
}


//#################
//#include <stdio.h>
//
//
//#define MAX_DIGITS 10
//
//int main() {
//    int num, digits[MAX_DIGITS], unique_digits[MAX_DIGITS], new_num_array[MAX_DIGITS], i, j, num_digits = 0, num_unique_digits = 0;
//
//    // read input integer
//    if (scanf("%d", &num) != 1) {
//        fprintf(stderr, "Input must be an integer\n");
//        return 1;
//    }
//
//    // convert number to list of digits
//    while (num > 0 && num_digits < MAX_DIGITS) {
//        digits[num_digits++] = num % 10;
//        num /= 10;
//    }
//
//    // remove repeated digits
//    for (i = 0; i < num_digits; i++) {
//        int is_duplicate = 0;
//        for (j = 0; j < num_unique_digits; j++) {
//            if (digits[i] == unique_digits[j]) {
//                is_duplicate = 1;
//                break;
//            }
//        }
//        if (!is_duplicate) {
//            unique_digits[num_unique_digits++] = digits[i];
//        }
//    }
//
//    // form new number from unique digits
//    num = 0;
//    for (i = num_unique_digits - 1; i >= 0; i--) {
//        new_num_array[num_unique_digits - 1 - i] = unique_digits[i];
//        num = num * 10 + unique_digits[i];
//    }
//
//    // display new number
//    for (i = 0; i < num_unique_digits; i++) {
//        printf("%c", new_num_array[i] + '0');
//    }
//    printf("\n");
//
//    return 0;
//}

