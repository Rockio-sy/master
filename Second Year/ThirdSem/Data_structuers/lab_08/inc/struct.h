#ifndef MY_STRUCT
#define MY_STRUCT

#define MAX_SIZE 500

typedef struct 
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;
} graph_t;

typedef struct
{
    int min_len[MAX_SIZE];
    int ver[MAX_SIZE];
} dextra_t;

typedef struct
{
    int min;
    int versh;
} task_t;

#endif