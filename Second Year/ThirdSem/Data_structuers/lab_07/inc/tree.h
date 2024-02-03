#ifndef __TREE__H__
#define __TREE__H__

#include "defines.h"

typedef struct node node_t;

struct node {
    int depth;      //العمق
    node_t *left;   //الطرف الايسر
    node_t *right;  // الطرف الايمن
    node_t *parent; // العائلة الاولى
    int value;      //القيمة
    char option;    // الخيار المطلوب
};

void print_tree(node_t *root, int place);

node_t *create_tree(int arr[NUMS_COUNT]);

void prefix_bypass(node_t *root);

void postfix_bypass(node_t *root, int mode);

void infix_bypass(node_t *root, int *arr, int *ind);

node_t *create_node(int depth, node_t *parent, node_t *left, node_t *right, int value, char option);

void read_to_tree(node_t **tree, int *arr);

node_t *create(node_t *root, int key);

#endif
