#include <stdio.h>
#include <stdlib.h>

#include "../inc/hash.h"
#include "../inc/defines.h"

int is_prime(int n)
{
    if (n == 1 || n == 0)
        return 0;

    for (int i = 2; i < n / 2; i++)
        if (n % 2 == 0)
            return 0;

    return 1;
}

int get_prime(int n)
{
    if (n % 2 == 0)
        n++;

    while (!is_prime(n))
    {
        printf("%d\n", n);
        n += 2;
    }

    return n;
}

void init_array(set_t **array, int *size)
{
    *size = get_prime(MAX_ARR_LEN);
    *array = malloc((*size) * sizeof(set_t));

    for (int i = 0; i < *size; i++)
    {
        (*array)[i].key = 0;
        (*array)[i].data = 0;
        (*array)[i].next = NULL;
    }
}

int hash_func(int key, int size)
{
    size = size;
    return (key % 10);
}

void insert(set_t **arr, int key, int data, int size)
{
    int ind = hash_func(key, size);

    if ((*arr)[ind].data == 0)
    {
        (*arr)[ind].key = key;
        (*arr)[ind].data = data;
    }
    else if ((*arr)[ind].data)
    {
        set_t *temp = arr[ind];

        while (temp->next != NULL)
            temp = temp->next;

        set_t *new = malloc(sizeof(set_t));

        new->key = key;
        new->data = data;
        new->next = NULL;

        temp->next = new;
    }
    else if ((*arr)[ind].key == key)
        (*arr)[ind].data = data;
    else
        printf("Error collision !\n"); //تصادم
}

void print_ht(set_t *arr, int size)
{
    printf("(KEY  |  VALUE) HASH TABLE :\n");

    for (int i = 0; i < size; i++)
    {
        set_t *temp = &arr[i];

        printf("%6d |", arr[i].key);

        while (temp->next != NULL)
        {
            printf("%6d -> ", temp->data);
            temp = temp->next;
        }

        printf("%6d\n", arr[i].data);
    }

    printf("\n");
}
