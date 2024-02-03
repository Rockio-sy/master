#include "menu.h"
#include "struct.h"
#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int error_code;
    setbuf(stdout, NULL);
    int comand;
    graph_t table_graph;
    table_graph.size = 0;
    int flag = 1;
    task_t task_min;
    task_min.min = 10000;
    task_min.versh = 0;
    while(flag)
    {
        print_menu_info();
        error_code = read_comand(&comand);
        if (error_code)
            return error_code;
        if (comand == 1)
        {
            error_code = read_graph(&table_graph);
        }
        else if (comand == 2)
        {
            char temp[30];
            printf("\nВведите имя файла: ");
            scanf("%s", temp); 
            error_code = read_graph_by_file(&table_graph, temp);
        }
        else if (comand == 3)
        {
            print_graph(table_graph, "graph.dot", task_min);
            system("dot -Tpng graph.dot -o graph.png");
            system("start graph.png");
        }
        else if (comand == 4)
        {
            dextra_t task;

            for (int i = 0; i < table_graph.size; i++)
            {
                error_code = dextra_alg(&table_graph, &task, i + 1);
                count_min(task, &task_min, table_graph.size, i + 1);
            }
            printf("\n\nВершина с минимальной суммой путей до других вершин:\n");
            printf("Вершина - %d, сумма путей - %d \n", task_min.versh, task_min.min);
        }
        else if (comand == 0)
        {
            flag = 0;
        }
        if (error_code)
            return error_code;
    }
    return OK;
}