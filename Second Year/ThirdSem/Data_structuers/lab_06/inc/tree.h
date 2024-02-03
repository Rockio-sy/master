#ifndef __TREE__H__
#define __TREE__H__

#include "defines.h"

typedef struct node node_t;

struct node {
    int depth;      // глубина вершины
    node_t *left;   // левый "ребёнок"
    node_t *right;  // правый "ребёнок"
    node_t *parent; // узел-родитель
    int value;      // значение в узле
    char option;    // операция узла
};

void print_tree(node_t *root, int place);

node_t *create_tree(int arr[NUMS_COUNT]);

void prefix_bypass(node_t *root);

void postfix_bypass(node_t *root, int mode);

void infix_bypass(node_t *root);

node_t *create_node(int depth, node_t *parent, node_t *left, node_t *right, int value, char option);

#endif
