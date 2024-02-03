#include <stdio.h>

#include "../inc/tree.h"

int depth(node_t *node)
{
    return node ? node->depth : 0;
}

void fix_depth(node_t *node)
{
    int dl = depth(node->left);
    int dr = depth(node->right);
    node->depth = (dl > dr ? dl : dr) + 1;
}

int depth_diff(node_t *node)
{
    return depth(node->right) - depth(node->left);
}

node_t *rotate_right(node_t *node)
{
    node_t *temp = node->left;
    node->left = temp->right;
    temp->right = node;

    fix_depth(node);
    fix_depth(temp);

    return temp;
}

node_t *rotate_left(node_t *node)
{
    node_t *temp = node->right;
    node->right = temp->left;
    temp->left = node;

    fix_depth(node);
    fix_depth(temp);

    return temp;
}

node_t *balance(node_t *node)
{
    fix_depth(node);

    if (depth_diff(node) == 2)
    {
        if (depth_diff(node->right) < 0)
            node->right = rotate_right(node->right);

        return rotate_left(node);
    }
    else if (depth_diff(node) == -2)
    {
        if (depth_diff(node->left) > 0)
            node->left = rotate_left(node->left);

        return rotate_right(node);
    }

    return node;
}

node_t *insert_avl_tree(node_t *tree, node_t *node, int to_balance)
{
    if (tree == NULL)
        return node;

    if (node->value == tree->value)
        return tree;
    else if (node->value < tree->value)
    {
        tree->left = insert_avl_tree(tree->left, node, to_balance);
        tree->left->parent = tree;
    }
    else
    {
        tree->right = insert_avl_tree(tree->right, node, to_balance);
        tree->right->parent = tree;
    }

    if (to_balance)
        tree = balance(tree);

    return tree;
}

void read_to_avl_tree(node_t **tree, int *arr, int to_balance)
{
    for (int i = 0; i < MAX_ARR_LEN; i++)
    {
        node_t *node = create_node(1, NULL, NULL, NULL, arr[i], ' ');
        *tree = insert_avl_tree(*tree, node, to_balance);
    }
}

node_t *get_node_by_value(node_t *root, int value)
{
    while (root)
    {
        if (CMP_GT(root->value, value))
        {
            root = root->left;
            continue;
        }
        else if (CMP_LT(root->value, value))
        {
            root = root->right;
            continue;
        }
        else
            return root;
    }

    return NULL;
}
