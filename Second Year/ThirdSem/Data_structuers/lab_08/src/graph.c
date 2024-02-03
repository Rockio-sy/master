#include "graph.h"
#include <stdio.h>

int read_graph(graph_t *table)
{
    printf("\nВведите количество вершин: ");
    
    if (scanf("%d", &table->size) != 1)
    {
        printf("\nОшибка чтения");
        return ERROR_READING;
    }
    else if (table->size <= 0)
    {
        printf("\nНедлпустимое значение");
        return ERROR_READING;
    }
    int buf;
    for (int i = 0; i < table->size; i++)
    {
        table->matrix[i][i] = 0;
        for (int j = i + 1; j < table->size; j++)
        {
            printf("\nВведите расстояние %d <-> %d: ", i + 1, j + 1);
            if (scanf("%d", &buf) != 1)
            {
                printf("\nОшибка чтения");
                return ERROR_READING;
            }
            table->matrix[i][j] = buf;
            table->matrix[j][i] = buf;
        }
    }
    return OK;
}

int read_graph_by_file(graph_t *table, char *file_name)
{
    FILE *f;
    f = fopen(file_name, "r");
    if (f == NULL)
    {
        printf("\nОшибка открытия файла");
        return ERROR_READING;
    }
    if (fscanf(f, "%d", &table->size) != 1)
    {
        printf("\nОшибка чтения");
        return ERROR_READING;
    }
    else if (table->size <= 0)
    {
        printf("\nНедлпустимое значение");
        return ERROR_READING;
    }
    int buf = 0;
    int buf_i = 0;
    int buf_j = 0;
    for (int i = 0; i < table->size; i++)
    {
        for (int j = 0; j < table->size; j++)
            table->matrix[i][j] = 0;
    }
    while (!feof(f))
    {
        if (fscanf(f, "%d - %d = %d", &buf_i, &buf_j, &buf) != 3)
        {
            printf("\nОшибка чтения");
            return ERROR_READING;
        }
        if (buf_i > table->size || buf_i <= 0 || buf_j <= 0 || buf_j > table->size)
        {
            printf("\nНеверные данные в файле");
            return ERROR_READING;
        }
        table->matrix[buf_i - 1][buf_j - 1] = buf;
        table->matrix[buf_j - 1][buf_i - 1] = buf;
    }
    return OK;
}

int print_graph(graph_t table, char *file_name, task_t min)
{
    if (table.size == 0)
    {
        printf("\nГраф не загружен");
        return ERROR_READING;
    }
    FILE *f;
    f = fopen(file_name, "w");
    if (f == NULL)
        return ERROR_READING;
    int flag = 0;
    if (min.versh != 0)
        flag = 1;
    //printf("|%d|", min.versh);
    fprintf(f, "graph g {\n");

    for (int i = 0; i < table.size; i++)
    {
        for (int j = i + 1; j < table.size; j++)
        {
            if (table.matrix[i][j] != 0)
                fprintf(f, "%d -- %d [weight = %d];\n", i + 1, j + 1, table.matrix[i][j]);
        }
    }
    for (int i = 0; i < table.size; i++)
        if (flag && min.versh == i + 1)
            fprintf(f,"%d [color=red, style=filled];\n", i + 1);
        else
            fprintf(f, "%d [color=blue, style=filled];\n", i + 1);
    fprintf(f, "}\n");

    fclose(f);
    return OK;
}

int dextra_alg(graph_t *table, dextra_t *argv , int versh)
{
    for (int i = 0; i < table->size; i++)
    {
        argv->min_len[i] = 10000;
        argv->ver[i] = versh;
    }

    int beg_ind = versh - 1;
    argv->min_len[beg_ind] = 0;
    int minindex = 10000;
    int min = 10000;
    int temp;
    do
    {
        minindex = 10000;
        min = 10000;

        for (int i = 0; i < table->size; i++)
            if ((argv->ver[i] == versh) && argv->min_len[i] < min)
            {
                min = argv->min_len[i];
                minindex = i;
            }
        
        if (minindex != 10000)
        {
            for (int i = 0; i < table->size; i++)
            {
                if (table->matrix[minindex][i] > 0)
                {
                    temp = min + table->matrix[minindex][i];
                    if (temp < argv->min_len[i])
                        argv->min_len[i] = temp;
                }
            }
            argv->ver[minindex] = 0;
        }
    }
    while (minindex < 10000);

    printf("\nРасстрояния до вершин от вершины %d \n", versh);
    for (int i = 0; i < table->size; i++)
        printf("%d ", argv->min_len[i]);
    return OK;
}

int count_min(dextra_t arr, task_t *task, int size, int versh)
{
    int buf = 0;
    for (int i = 0; i < size; i++)
        buf += arr.min_len[i];
    if (buf < task->min)
    {
        task->min = buf;
        task->versh = versh;
    }
    return OK;
}