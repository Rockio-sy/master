#include "swap.h"

void swap_double_el(double *d_1, double *d_2)
{
    double buff = *d_1;
    *d_1 = *d_2;
    *d_2 = buff;
}
void swap_column(double *column_1, double *column_2, int size_column)
{
    for (int i = 0; i < size_column; i++)
        swap_double_el(&column_1[i], &column_2[i]);
}