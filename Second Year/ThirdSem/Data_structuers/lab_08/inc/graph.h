#ifndef GRAHP
#define GRAPH

#include "struct.h"
#include "errors.h"

int read_graph(graph_t *table);
int print_graph(graph_t table, char *file_name, task_t min);
int dextra_alg(graph_t *table, dextra_t *argv , int versh);
int count_min(dextra_t arr, task_t *task, int size, int versh);
int read_graph_by_file(graph_t *table, char *file_name);
#endif