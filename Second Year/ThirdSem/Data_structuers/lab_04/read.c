#include <stdio.h>
#include <string.h>

#include "read.h"
#include "memory_operations.h"

#define READ_OK 1
#define MAX_SIZE 50
#define MAX_STACK 10000
#define N 50

#define OK 0
#define INVALID_INPUT 1
#define MEMORY_ERROR 2
#define INVALID_FILE 3
#define INVALID_X 4
#define INVALID_Y 5
#define INVALID_STACK_TYPE 6
#define STACK_EMPTY 7

static int read_maze(maze_t *maze, FILE *f, int *max_stack)
{
    for (int i = 0; i < maze->y; i++)
    {
        if (fgetc(f) == EOF)
        {

            return INVALID_INPUT;
        }

        for (int j = 0; j < maze->x; j++)
        {
            if ((maze->matrix[i][j] = fgetc(f)) == EOF)
            {
                return INVALID_INPUT;
            }

            if (maze->matrix[i][j] == ' ')
            {
                (*max_stack)++;
            }

            if (maze->matrix[i][j] == '0')
            {
                maze->i_enter = i;
                maze->j_enter = j;
            }
        }
    }

    return OK;
}

static int open_file(FILE **f, char *file_name)
{
    if ((*f = fopen(file_name, "r")) == NULL)
    {
        return INVALID_FILE;
    }

    return OK;
}

int read_file(maze_t *maze, FILE *f, int *max_stack)
{
    char file_name[N];
    maze->matrix = NULL;
    puts("\nThis program searches for an exit in a maze using a stack.\n"
         "The stack is implemented either using a list or an array.\n"
         "The maze is stored in a file.\n");

    puts("Enter the file name (including the path to the file): ");
    if (fscanf(stdin, "%30s", file_name) != READ_OK)
    {
        return INVALID_INPUT;
    }

    if (open_file(&f, file_name))
    {
        fprintf(stderr, "Error: Failed to open file.\n");
        return INVALID_FILE;
    }

    if (fscanf(f, "%d", &maze->x) != READ_OK)
    {
        return INVALID_INPUT;
    }

    if (maze->x > MAX_SIZE || maze->x < 1)
    {
        fprintf(stderr, "Error: the number of columns must be between 0 and 100\n");
        return INVALID_X;
    }

    if (fscanf(f, "%d", &maze->y) != READ_OK)
    {
        return INVALID_INPUT;
    }

    if (maze->y > MAX_SIZE || maze->y < 1)
    {
        fprintf(stderr, "Error: the number of rows must be between 0 and 100\n");
        return INVALID_X;
    }

    if (new_matrix(maze))
    {
        return MEMORY_ERROR;
    }

    if (read_maze(maze, f, max_stack))
    {
        fprintf(stderr, "Error reading from a file\n");
        return INVALID_INPUT;
    }

    fclose(f);

    return OK;
}

int read_stack_type(int *type)
{
    puts("\nEnter 1 if you want to use a stack implemented as an array,\n"
         "or enter 0 if you want to use a stack implemented as a list: ");

    if (scanf("%d", type) != READ_OK)
    {
        return INVALID_INPUT;
    }

    if (*type < 0 || *type > 1)
    {
        fprintf(stderr, "Error: Incorrect input.\n");
        return INVALID_STACK_TYPE;
    }

    return OK;
}

int read_action(int *action_type)
{
    puts("Enter 1 if you want to find a path in the labyrinth using a stack,\n"
         "or enter 0 if you want to manually work with the stack: ");

    if (scanf("%d", action_type) != READ_OK)
    {
        return INVALID_INPUT;
    }

    if (*action_type < 0 || *action_type > 1)
    {
        fprintf(stderr, "Error: Incorrect input.\n");
        return INVALID_INPUT;
    }

    return OK;
}

int read_stack_action(int *action)
{
    puts("\n1. Add elements to the stack.\n"
         "2. Remove elements from the stack.\n"
         "3. Add random elements to the stack.\n"
         "4. Display the current stack state.\n"
         "5. Exit the program.\n"
         "Select a menu item: ");

    if (scanf("%d", action) != READ_OK)
    {
        return INVALID_INPUT;
    }

    if (*action < 0 || *action > 4)
    {
        fprintf(stderr, "Error: incorrect entry.\n");
        return INVALID_INPUT;
    }

    return OK;
}

int read_add_info(int *count, int curr_stack)
{
    printf("Enter the number of items to be added (up to a maximum of %d): \n",
           MAX_STACK - curr_stack);

    if (scanf("%d", count) != READ_OK)
    {
        return INVALID_INPUT;
    }

    if (*count <= 0 || *count > MAX_STACK - curr_stack)
    {
        fprintf(stderr, "Error: incorrect input of the number of items to be added.\n");
        return INVALID_INPUT;
    }

    return OK;
}

int read_delete_info(int *count, int curr_stack)
{
    if (!curr_stack)
    {
        puts("\nСтек пуст.");
        return STACK_EMPTY;
    }

    printf("Enter the number of items to be deleted (up to a maximum of %d): \n", curr_stack);

    if (scanf("%d", count) != READ_OK)
    {
        return INVALID_INPUT;
    }

    if (*count <= 0 || *count > curr_stack)
    {
        fprintf(stderr, "Error: incorrect input of the number of items to be deleted.\n");
        return INVALID_INPUT;
    }

    return OK;
}

int read_struct(int *i)
{
    puts("Enter an element of the stack. Enter -1 if you want to end the input: ");
    if (scanf("%d", i) != READ_OK)
    {
        return INVALID_INPUT;
    }

    return OK;
}
