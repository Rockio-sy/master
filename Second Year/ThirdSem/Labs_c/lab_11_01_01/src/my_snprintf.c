#include "../inc/my_snprintf.h"

size_t get_rank(long long num)
{
    size_t result = 0;
    if (num != 0)
    {
        while (num != 0)
        {
            result++;
            num /= 10;
        }
    }

    return result;
}

long long conventing_to_number_system(int number, int system)
{
    long long conv = 0;
    if (number != 0)
    {
        int i = 0, tmp;
        while (number != 0)
        {
            tmp = 1;
            for (size_t k = 0; k < i; k++)
                tmp *= 10;
            conv += (number % system) * tmp;
            number /= system;
            i++;
        }
    }
    if (conv < 0)
        conv = MAX_OC_NUM + conv;

    return conv;
}

void add_char_in_str(char *str, char c, int *count, size_t n)
{
    if (*count < n - 1 && str && n > 0)
        *(str + *count) = c;
    (*count)++;
}

void add_str_in_str(char *str, const char *add_str, int *count, size_t n)
{
    if (!add_str)
        add_str = "(null)";
    for (size_t j = 0; *(add_str + j) != '\0'; j++)
        add_char_in_str(str, *(add_str + j), count, n);
}

void add_num_in_str(char *str, long long num, int *count, size_t n)
{
    if (num == 0)
        add_char_in_str(str, '0', count, n);
    else
    {
        size_t rank = get_rank(num);
        if (num < 0)
            add_char_in_str(str, '-', count, n);

        for (size_t j = 0; j < rank; j++)
        {
            long long tmp = 1;
            for (size_t k = 0; k < rank - j - 1; k++)
                tmp *= 10;

            if (num < 0)
                add_char_in_str(str, (char) ('0' - num / tmp), count, n);
            else
                add_char_in_str(str, (char) ('0' + num / tmp), count, n);

            num %= tmp;
        }
    }
}

int my_snprintf(char *restrict str, size_t n, const char *restrict format, ...)
{
    va_list args;
    int count = 0;
    size_t i;

    va_start(args, format);
    if (*format != '\0')
    {
        for (i = 0; *(format + i) != '\0'; i++)
        {
            if (*(format + i) == '%')
            {
                i++;
                if (*(format + i) == 'c')
                {
                    char sym = (char) va_arg(args, int);
                    add_char_in_str(str, sym, &count, n);
                }
                else if (*(format + i) == 's')
                {
                    char *tmp = va_arg(args, char *);
                    add_str_in_str(str, tmp, &count, n);
                }
                else if (*(format + i) == 'd' || *(format + i) == 'i')
                {
                    int num = va_arg(args, int);
                    add_num_in_str(str, num, &count, n);
                }
                else if (*(format + i) == 'o')
                {
                    int num = va_arg(args, int);
                    long long res = conventing_to_number_system(num, 8);
                    add_num_in_str(str, res, &count, n);
                }
            }
            else
                add_char_in_str(str, *(format + i), &count, n);
        }
    }
    va_end(args);

    if (str && n > 0)
    {
        if (count < n - 1)
            *(str + count) = '\0';
        else
            *(str + n - 1) = '\0';
    }

    return count;
}
