#include "check_prime.h"

int check_simple_num(int num)
{
    int res = SIMPLE;
    if (num < 2)
        res = NO_SIMPLE;

    for (int i = 2; i < num && res; i++)
    {
        if (num % i == 0)
            res = NO_SIMPLE;
    }

    return res;
}

int get_simple_num(int num)
{
    int count = 0;
    int check = 0;
    while (count++ < INT_MAX && !check)
        check = check_simple_num(++num);

    return num;
}