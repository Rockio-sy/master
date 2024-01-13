#include <stdio.h>

void calculate_numbers() {
    int number;
    int even_sum = 0;
    int odd_product = 1;

    while (1) {
        printf("Insert a number to (save) or 0 to Calculate: ");
        scanf("%d", &number);

        if (number == 0) {
            break;
        }

        if (number % 2 == 0) {
            even_sum += number;
        } else {
            odd_product *= number;
        }
    }
    if (odd_product == 1){
        printf("There isn't any odd number..\n");
    }else{
        printf("The odd product is : %d\n", odd_product);
    }

    if (even_sum == 0){
        printf("there isn't any even number..\n");
    }else {
        printf("The even sum is : %d\n", even_sum);
    }
}

int main() {
    calculate_numbers();
    return 0;
}

