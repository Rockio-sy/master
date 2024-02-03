#include <stdio.h>
#include <time.h>

#include "../inc/tree.h"
#include "../inc/hash.h"
#include "../inc/avl_tree.h"

int main(void)
{
    int arr[NUMS_COUNT];

    // NUMS COUNT will be subtracted to get the event!
    for (int i = 0; i < NUMS_COUNT; i++)
        arr[i] = NUMS_COUNT - i;
    printf("        ..HELLOOO!\n");
    printf("     ..\n");
    printf("   O\n");
    printf("  /|\\\n");
    printf("  _|_\n");
    printf("\n =====EXPRESS===== \n");
    printf("%d + (%d * (%d + (%d * (%d + %d) - (%d - %d)) + %d))\n\n",
    arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8]);

    // Create new tree
    node_t *root = create_tree(arr);

    // Print The Tree
    printf("\n\n=====BINARY TREE=====:\n");
    print_tree(root, 0);

    printf("\n\n=====Постфиксни обход (Bypass)====:\n");

    postfix_bypass(root, 1);
    printf("\n");

    int tree_arr[MAX_ARR_LEN];
    int ind = 0;
    printf("\n\n====Инфиксни обход (Infix bypass)====:\n");
    infix_bypass(root, tree_arr, &ind);
    printf("\n");

    node_t *ddp_tree = create(ddp_tree, 9);
    read_to_tree(&ddp_tree, tree_arr);

    printf("\n\n====DDP====:\n");
    print_tree(ddp_tree, 0);

    node_t *avl_tree = NULL;
    read_to_avl_tree(&avl_tree, tree_arr, 1);

    printf("\n\n=====AVL-TREE=====:\n");
    print_tree(avl_tree, 0);

    printf("RESULT BY TREE: %d\n\n", root->value);

    // قياسات دب إلى أبعد قمة
    int temp = 0;
    clock_t begin = clock();

    while (temp++ < 1000000)
        get_node_by_value(ddp_tree, 4);

    clock_t end = clock();

    printf("TIME =: %f\n\n", (double)(end - begin) / 1000000);

    temp = 0;
    begin = clock();

    while (temp++ < 1000000)
        get_node_by_value(avl_tree, 4);

    end = clock();

    printf("Time for search by tree ==: %f\n\n", (double)(end - begin) / 1000000);

    set_t *ht = NULL;
    int size = 0;
    init_array(&ht, &size);
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len; i++)
        insert(&ht, i * HASH_KEY, arr[i], size);

    print_ht(ht, size);

    int key = 0;
    printf("Insert key to Search: ");
    if (scanf("%d", &key) != 1)
    {
        printf("Invalid input.\n");
        return SCANF_ERR;
    }

    temp = 0, ind = key % size;
    begin = clock();

    while (temp++ < 1000000)
        ht[ind].data = ht[ind].data;
        temp++;

    end = clock();

    if (key != ht[ind].key)
    {
        printf("Not such a key.\n");
        return KEY_ERR;
    }
    printf("Found: %5d | %d\n\n", ht[ind].key, ht[ind].data);
    printf("Time for HasTable: %f\n\n", (double)(end - begin) / 1000000);

    return EXIT_SUCCESS;
}
