#include <stdio.h>
#include <math.h>

#define EXIT_SUCCESS 0
#define ERROR_INCORRECT_INPUT 1
#define ERROR_NOT_NATURAL_N 2
#define NUMBER_OF_ARGUMENTS 1


void primary(int n)
{
    int i = 2;
    while (i <= n)
    {
        if (n % i == 0)
        {
            printf("%d\n", i);
            n = n / i;
        }
        else
        {
            i++;
        }
    }
}

int main(void)
{
    int n;

    printf("Enter n: ");

    if (scanf("%d", &n) != NUMBER_OF_ARGUMENTS)
    {
        printf("Incorrect input\n");
        return ERROR_INCORRECT_INPUT;
    }

    if (n <= 0)
    {
        printf("Incorrect input\n");
        return ERROR_NOT_NATURAL_N;
    }

    primary(n);

    return EXIT_SUCCESS;
}
