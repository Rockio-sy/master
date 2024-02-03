#ifndef __AVL__TREE__H__
#define __AVL__TREE__H__

void read_to_avl_tree(node_t **tree, int *arr, int to_balance);

void print_avl_tree(node_t *tree);

node_t *get_node_by_value(node_t *root, int value);

#endif
