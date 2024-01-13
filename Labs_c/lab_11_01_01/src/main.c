#include <stdio.h>
#include <string.h>
#include "my_snprintf.h"

#define SIZE 201

int main(void)
{
    setbuf(stdout, NULL);
    int rc = 0;
    char buff_1[SIZE] = { '\0' };
    char buff_2[SIZE] = { '\0' };
    char format[SIZE] = "Hi! %c Hello %s my %i %d friend %o";

    int result_1 = 0, result_2 = 0, num = -1212434;
    result_1 = my_snprintf(buff_1, SIZE, format, 'h', "hello", num, num, num);
    result_2 = snprintf(buff_2, SIZE, format, 'h', "hello", num, num, num);

    if (result_1 == result_2 && !strcmp(buff_1, buff_2))
        rc = 0;
    else
        rc = 1;

    return rc;
}