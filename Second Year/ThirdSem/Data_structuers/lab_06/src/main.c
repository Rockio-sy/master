#include <stdio.h>
#include <time.h>

#include "/home/rockio/sec_year/Data_structuers/lab_06/inc/tree.h"
#include "/home/rockio/sec_year/Data_structuers/lab_06/inc/stack.h"
#include "/home/rockio/sec_year/Data_structuers/lab_06/inc/defines.h"

int main(void)
{
    printf("-------------------------------------------------\n");
    printf("           Binary Search\n");
    printf("-------------------------------------------------\n\n");

    int arr[NUMS_COUNT];

    printf("Enter %d integer values for A, B, C ... I: ", NUMS_COUNT);
    for (int i = 0; i < NUMS_COUNT; i++)
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Error! Integer value required.\n");
            return SCANF_ERR;
        }

    printf("\n\nGiven expression:\n");
    printf("%d + (%d * (%d + (%d * (%d + %d) - (%d - %d)) + %d))\n\n",
    arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8]);

    node_t *root = create_tree(arr);

    printf("\n\nGenerated binary tree:\n");
    print_tree(root, 0);

    printf("Prefix traversal:\n");
    prefix_bypass(root);

    printf("\n\nInfix traversal:\n");
    infix_bypass(root);

    printf("\n\nPostfix traversal:\n");
    postfix_bypass(root, 1);
    printf("\n\n");

    int temp = 0;
    clock_t begin = clock();

    while (temp++ < 1000000)
        postfix_bypass(root, 0);

    clock_t end = clock();

    printf("Result of the expression (using the tree): %d\n\n", root->value);
    printf("Time to evaluate the expression using the tree: %f\n\n", (double)(end - begin) / 1000000);

    temp = 0;
    int res = 0, rc=0;
    begin = clock();

    // while (temp++ < 1000000)
    res = stack_res(arr);

    end = clock();

    printf("Result of the expression (using the stack): %d\n\n", res);
    // printf("Time to evaluate the expression using the stack: %f\n\n", (double)(end - begin) / 1000000);

    int n, val;
    printf("How many vertices do you want to add to a new empty tree of integers?\n");

    if ((rc = scanf("%d", &n) != 1))
    {
        printf("Error! Integer value required.\n");
        return SCANF_ERR;
    }

    if (n > 0)
    {
        printf("Enter the value of the root vertex: ");
        if ((scanf("%d", &val) != 1))
        {
            printf("Error! Integer value required.\n");
            return SCANF_ERR;
        }

        begin = clock();

        root = create_node(0, NULL, NULL, NULL, val, ' ');

        node_t *old_node = root;
        temp = 1;
        while (temp++ < n)
        {
            printf("Enter the value of the %d-th vertex: ", temp);
            if (scanf("%d", &val) != 1)
            {
                printf("Error! Integer value required.\n");
                return SCANF_ERR;
            }

            node_t *new_node = create_node(0, old_node, NULL, NULL, val, ' ');
            old_node->left = new_node;
            old_node = new_node;
        }

        printf("\n\nGenerated tree:\n");
        print_tree(root, 0);
    }

    int m;
    printf("\n\nHow many vertices do you want to keep from the tree of integers?\nInput: ");

    if ((rc = scanf("%d", &m) != 1))
    {
        printf("Error! Integer value required.\n");
        return SCANF_ERR;
    }

    if (m > n)
    {
        printf("Error! Cannot keep more nodes than there are.\n");
        return WRONG_DELETE;
    }

    if (m > 0)
    {
        node_t *old_node = root;
        node_t *new_node = root;
        m--;

        temp = 0;
        while (temp++ < m)
        {
            new_node = old_node->left;
            old_node = new_node;
        }

        new_node->left = NULL;

        print_tree(root, 0);
    }

    return EXIT_SUCCESS;
}

