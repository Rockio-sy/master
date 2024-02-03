#include <stdio.h>
#include <inttypes.h>

#include "print.h"
#include "timer.h"

extern int __stack_type;

void print_maze(const maze_t maze)
{
    putchar('\n');

    for (int i = 0; i < maze.y; i++)
    {
        for (int j = 0; j < maze.x; j++)
        {
            switch (maze.matrix[i][j])
            {
                case 'X':
                    printf("\033[31m%c\033[0m", maze.matrix[i][j]);
                    break;
                case '?':
                    printf("\033[32m%c\033[0m", maze.matrix[i][j]);
                    break;
                default:
                    printf("%c", maze.matrix[i][j]);
            }
        }

        putchar('\n');
    }
}

void print_compare(const int stack_size)
{
    extern int64_t total_time;

    printf("\nWayfinding time: %"PRId64 " ticks \n", total_time);
    printf("The amount of memory occupied when implementing a stack using an array: %lu\n",
        stack_size * (__stack_type ? sizeof(array_element_t) : sizeof(list_element_t)));
}

void print_stack(const stack_list_t list, const stack_array_t array, FILE *f,
    list_element_t **address_array, const int size)
{
    fprintf(f, "%s\n", "Stack:\n");

    if (__stack_type)
    {
        for (int i = array.size - 1; i >= 0; i--)
        {
            fprintf(f, "%p\n", (array.ptr + i));
        }
    }
    else
    {
        list_element_t *temp = list.ptr;

        while (temp != NULL)
        {
            fprintf(f, "%p\n", temp);
            temp = temp->next_elem;
        }

        fprintf(f, "%s", "\nList of addresses that have been vacated: \n");
        for (int i = 0; i < size; i++)
        {
            fprintf(f, "%p\n", address_array[i]);
        }
    }

    fprintf(f, "%s", "\n\n");
}

static void print_struct(const int i, const int j, const int dir)
{
    printf("Stack item: %d\n", i);
}

void print_sample_stack(const stack_list_t list, const stack_array_t array, FILE *f,
    int64_t *array_time, int64_t *list_time)
{
    int64_t start_time;
    list_element_t *temp = list.ptr;

    if (!array.size)
    {
        fprintf(f, "%s", "\nStack's empty\n");
        return;
    }

    fprintf(f, "Current stack size: %d\n", array.size);
    //fprintf(f, "%s", "\nСтек, реализованный массивом: \n\n");

    start_time = tick();
    /*
    for (int i = array.size - 1; i >= 0; i--)
    {
        fprintf(f, "Адрес: %p\n", (array.ptr + i));
        print_struct(temp->i, temp->j, temp->direction);
        temp = temp->next_elem;
    }
    */

    *array_time += tick() - start_time;

    fprintf(f, "%s", "\nStack implemented by a list: \n");

    temp = list.ptr;

    start_time = tick();
    while (temp != NULL)
    {
        fprintf(f, "\nAddress: %p\n", temp);
        print_struct(temp->i, temp->j, temp->direction);
        temp = temp->next_elem;
    }

    *list_time += tick() - start_time;
}

void print_results(int64_t array_time, int64_t list_time)
{
    printf("\nstack processing time, implemented using the array: %"PRId64 "\n", array_time);
    printf("Processing time of the stack implemented with the list:  %"PRId64 "\n", list_time);
}

void print_memory_results(const int size)
{
    if (!size)
    {
        printf("Memory occupied by array: %lu\nMemory occupied by the list:  %lu\n",
            size * sizeof(int), 2 * size * sizeof(int));
        return;
    }

    printf("Memory occupied by array: %lu\nMemory occupied by the list:  %lu\n",
        size * sizeof(int), 2 * size * sizeof(int) + size * sizeof(list_element_t *));
}
