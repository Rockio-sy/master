#include "array_func.h"

static int check_prime(int number)
{
    int flag = 0, m = number / 2;
    
    for (int i = 2; i <= m && !flag; i++)
        if (number % i == 0)
            flag = 1;

    return flag ? 0 : 1;
}

void fill_array_prime(int *array, int size)
{
    for (int i = 0, number = 2; i < size;)
    {
        if (check_prime(number))
            array[i++] = number;
        number++;
    }
}

int add_elem_after_even(int *array, int size, int *new_arr, int new_size, int number)
{
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (index < new_size)
            new_arr[index] = array[i];
        index++;
        if (array[i] % 2 == 0)
        {
            if (index < new_size)
                new_arr[index] = number;
            index++;
        }
    }
    
    return index;
}
