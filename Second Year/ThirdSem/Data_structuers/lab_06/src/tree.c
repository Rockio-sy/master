#include <stdio.h>
#include <stdlib.h>
#include "/home/rockio/sec_year/Data_structuers/lab_06/inc/tree.h"
#include "/home/rockio/sec_year/Data_structuers/lab_06/inc/stack.h"
#include "/home/rockio/sec_year/Data_structuers/lab_06/inc/defines.h"

void node_init(node_t *node, int depth, node_t *parent, node_t *left, node_t *right, int value, char option)
{
    node->depth = depth;
    node->parent = parent;
    node->left = left;
    node->right = right;
    node->value = value;
    node->option = option;
}

node_t *create_node(int depth, node_t *parent, node_t *left, node_t *right, int value, char option)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
        printf("Ошибка выделения памяти для узла дерева!\n");

    node_init(new_node, depth, parent, left, right, value, option);

    return new_node;
}

node_t *create_tree(int arr[NUMS_COUNT])
{
    node_t *plus1 = create_node(0, NULL, NULL, NULL, 0, '+');
    node_t *a = create_node(1, plus1, NULL, NULL, arr[0], ' ');
    node_t *multi1 = create_node(1, plus1, NULL, NULL, 0, '*');
    plus1->left = a;
    plus1->right = multi1;

    // printf("plus1: %p / %p\n\n", plus1->left, plus1->right);

    node_t *b = create_node(2, multi1, NULL, NULL, arr[1], ' ');
    node_t *plus2 = create_node(2, multi1, NULL, NULL, 0, '+');
    multi1->left = b;
    multi1->right = plus2;

    // printf("multi1: %p / %p\n\n", multi1->left, multi1->right);

    node_t *minus1 = create_node(3, plus2, NULL, NULL, 0, '-');
    node_t *multi2 = create_node(3, plus2, NULL, NULL, 0, '*');
    plus2->left = minus1;
    plus2->right = multi2;

    // printf("plus2: %p / %p\n\n", plus2->left, plus2->right);
    // printf("multi2 value / option = %d / %c\n\n", plus2->right->value, plus2->right->option);


    node_t *plus3 = create_node(4, minus1, NULL, NULL, 0, '+');
    node_t *minus2 = create_node(4, minus1, NULL, NULL, 0, '-');
    minus1->left = plus3;
    minus1->right = minus2;

    // printf("minus1: %p / %p\n\n", minus1->left, minus1->right);


    node_t *d = create_node(4, multi2, NULL, NULL, arr[3], ' ');
    node_t *plus4 = create_node(4, multi2, NULL, NULL, 0, '+');
    multi2->left = d;
    multi2->right = plus4;

    // printf("multi2: %p / %p\n\n", multi2->left, multi2->right);

    node_t *c = create_node(5, plus3, NULL, NULL, arr[2], ' ');
    node_t *i = create_node(5, plus3, NULL, NULL, arr[8], ' ');
    plus3->left = c;
    plus3->right = i;

    node_t *e = create_node(5, plus4, NULL, NULL, arr[4], ' ');
    node_t *f = create_node(5, plus4, NULL, NULL, arr[5], ' ');
    plus4->left = e;
    plus4->right = f;

    node_t *g = create_node(5, minus2, NULL, NULL, arr[6], ' ');
    node_t *h = create_node(5, minus2, NULL, NULL, arr[7], ' ');
    minus2->left = g;
    minus2->right = h;

    return plus1;
}

void print_tree(node_t *root, int place)
{
    int add_space = 6;

    place += add_space;

    if (root == NULL)
        return;

    // printf("pointer = %p\n", root);
    // printf("value / option = %d / %c\n\n", root->value, root->option);

    if (root->right != NULL)
        print_tree(root->right, place);

    for (int i = add_space; i < place; i++)
        printf(" ");

    if (root->option != ' ')
        printf("{ %c }\n", root->option);
    else
        printf("{ %d }\n", root->value);

    if (root->left != NULL)
        print_tree(root->left, place);
}

void prefix_bypass(node_t *root)
{
    if (root != NULL)
    {
        if (root->option != ' ')
            printf("%c ", root->option);
        else
            printf("%d ", root->value);

        prefix_bypass(root->left);
        prefix_bypass(root->right);
    }
}

void postfix_bypass(node_t *root, int mode)
{
    if (root != NULL)
    {
        postfix_bypass(root->left, mode);
        postfix_bypass(root->right, mode);

        if (root->option == '+')
            root->value = root->left->value + root->right->value;

        else if (root->option == '-')
            root->value = root->left->value - root->right->value;
        else if (root->option == '*')
            root->value = root->left->value * root->right->value;
        else if (mode)
            printf("%d ", root->value);

        if (root->option != ' ' && mode)
            printf("%c ", root->option);
    }
}

void infix_bypass(node_t *root)
{
    if (root != NULL)
    {
        infix_bypass(root->left);

        if (root->option != ' ')
            printf("%c ", root->option);
        else
            printf("%d ", root->value);

        infix_bypass(root->right);
    }
}
