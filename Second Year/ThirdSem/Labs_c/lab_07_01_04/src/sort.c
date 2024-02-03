#include "sort.h"

void swap(void *el1, void *el2, size_t size)
{
    char buff[size];
    
    memcpy(buff, el1, size);
    memcpy(el1, el2, size);
    memcpy(el2, buff, size);
}

// buble_sort модификация сортировки пузырьком 3 (шейкер с флажком
int cmp_int(const void *p, const void *q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}

void mysort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *))
{
    char *base_end = (char *) base + size * (n - 1);
    char *base_beg = (char *) base;
    char *swap_r = base_end, *swap_l = base_beg, *last_swap_right = base_end, *last_swap_left = base_beg;

    for (char *pi = base_beg; pi < base_end; pi += size)
        if (((pi - base_beg) / size) % 2 != 0)
        {
            for (char *pj = base_beg; pj < last_swap_right; pj += size)
                if (cmp(pj, pj + size) > 0)
                {
                    swap(pj, pj + size, size);
                    swap_r = pj;
                }
            last_swap_right = swap_r;
        }
        else
        {
            for (char *pj = base_end; pj > last_swap_left; pj -= size)
                if (cmp(pj, pj - size) < 0)
                {
                    swap(pj, pj - size, size);
                    swap_l = pj;
                }
            last_swap_left = swap_l;
        }
}



