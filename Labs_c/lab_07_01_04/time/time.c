#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>
#include <string.h>
#include "sort.h"

#define LOW_SIZE 10
#define BIG_SIZE 1000
#define STEP 10
#define I_STEP 100
#define EPS 1e-9

void make_table(void)
{
    printf("|--------|--------|--------------|--------|\n");
    printf("| %6s | %6s | %12s | %6s |\n", "I", "Размер", "MYSORT", "QSORT");
    printf("|--------|--------|--------------|--------|\n");
}

void make_data(int i, size_t size, int64_t time_1, int64_t time_2)
{
    printf("| %6d | %6zu | %12" PRId64 " | %6" PRId64 " |\n", i, size, time_1, time_2);
}

void random_array(int *arr, size_t n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
}

void time_sorted_arrays()
{
    struct timeval tv_start, tv_stop;
    int64_t time_m, time_q, elapsed_m = 0, elapsed_q = 0;
    printf("Сравнение mysort и qsort на отсортированных массивах.\n");
    make_table();

    int arr_m[BIG_SIZE];
    int arr_q[BIG_SIZE];

    for (int size = LOW_SIZE; size < BIG_SIZE; size *= STEP)
    {
        for (int j = 0; j < size; j++)
        {
            arr_m[j] = j;
            arr_q[j] = j;
        }
        for (int i = 0; i < I_STEP; i++)
        {
            gettimeofday(&tv_start, NULL);
            mysort(arr_m, size, sizeof(int), cmp_int);
            gettimeofday(&tv_stop, NULL);
            time_m = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
            elapsed_m += time_m;

            gettimeofday(&tv_start, NULL);
            qsort(arr_q, size, sizeof(int), cmp_int);
            gettimeofday(&tv_stop, NULL);

            time_q = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
            elapsed_q += time_q;
        }
        elapsed_m /= (I_STEP - 2);
        elapsed_q /= (I_STEP - 2);
        make_data(I_STEP, size, elapsed_m, elapsed_q);
    }
}

void time_unsorted_arrays()
{
    struct timeval tv_start, tv_stop;
    int64_t time_m, time_q, elapsed_m = 0, elapsed_q = 0;
    printf("\nСравнение mysort и qsort на неотсортированных массивах.\n");
    make_table();

    int arr_m[BIG_SIZE];
    int arr_q[BIG_SIZE];

    for (int size = LOW_SIZE; size < BIG_SIZE; size *= STEP)
    {
        random_array(arr_m, size);
        random_array(arr_q, size);
        for (int i = 0; i < I_STEP; i++)
        {
            gettimeofday(&tv_start, NULL);
            mysort(arr_m, size, sizeof(int), cmp_int);
            gettimeofday(&tv_stop, NULL);
            time_m = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
            elapsed_m += time_m;

            gettimeofday(&tv_start, NULL);
            qsort(arr_q, size, sizeof(int), cmp_int);
            gettimeofday(&tv_stop, NULL);


            time_q = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL + (tv_stop.tv_usec - tv_start.tv_usec);
            elapsed_q += time_q;
        }
        elapsed_m /= (I_STEP - 2);
        elapsed_q /= (I_STEP - 2);
        make_data(I_STEP, size, elapsed_m, elapsed_q);
    }
}

int main()
{
    time_sorted_arrays();
    time_unsorted_arrays();
    return EXIT_SUCCESS;
}