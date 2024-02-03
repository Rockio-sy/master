#include <stdlib.h>
#include <string.h>
#include "my_file.h"

#define TRUE 1

int main(void)
{
    student st[STUDENT_MAX];
    size_t size = 0;

    while (TRUE)
    {
        if (process(st, &size) == EXIT)
            break;
    }
    return EXIT_SUCCESS;
}