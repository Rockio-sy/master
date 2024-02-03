#include "check_list_operations.h"

void print_result_tests(char *name_func, int test_neg, int neg_failed, int test_pos, int pos_failed);

int tests_comparator(void)
{
    int pos_cnt = 0, test_pos = 3;

    {
        int a = 56;
        int b = 68;
        int res = 0;

        res = comparator(&a, &b);
        if (res != a - b)
            pos_cnt++;
    }

    {
        int a = 56;
        int b = 68;
        int res = 0;

        res = comparator(&b, &a);
        if (res != b - a)
            pos_cnt++;
    }

    {
        int a = 56;
        int b = 56;
        int res = 0;

        res = comparator(&a, &b);
        if (res != a - b)
            pos_cnt++;
    }

    print_result_tests((char *) __func__, 0, 0, test_pos, pos_cnt);

    return pos_cnt;
}

int tests_find(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 3, test_pos = 5;

    {
        node_t *data = NULL, *find_node = NULL;
        int find_el = 5;

        find_node = find(data, &find_el, comparator);
        if (find_node != NULL || data != NULL)
            neg_cnt++;
    }

    {
        node_t *data = NULL, *find_node = NULL;
        int el = 10;
        data = node_create(&el);

        find_node = find(data, NULL, comparator);
        if (find_node != NULL)
            neg_cnt++;

        free_list(&data);
    }

    {
        node_t *data = NULL, *find_node = NULL;
        int el = 10;
        int find_el = 5;
        data = node_create(&el);

        find_node = find(data, &find_el, NULL);
        if (find_node != NULL)
            neg_cnt++;

        free_list(&data);
    }

    {
        node_t *data = NULL, *find_node = NULL;

        int find_el = 50, element = 50;

        data = node_create(&element);

        find_node = find(data, &find_el, comparator);
        if (find_node == NULL || *(int *) find_node->data != element)
            pos_cnt++;

        free_list(&data);
    }

    {
        node_t *data = NULL, *find_node = NULL;
        int array[10] = {10, 5, 9, 8, 7, 0, 1, 2, 11, 98};
        int find_el = 100, n = 10;

        for (int i = 0; i < n; i++)
            list_push(&data, array + i);

        find_node = find(data, &find_el, comparator);
        if (find_node != NULL)
            pos_cnt++;

        find_el = 10;

        find_node = find(data, &find_el, comparator);
        if (find_node == NULL || *(int *) find_node->data != *array)
            pos_cnt++;

        find_el = 1;

        find_node = find(data, &find_el, comparator);
        if (find_node == NULL || *(int *) find_node->data != *(array + 6))
            pos_cnt++;

        find_el = 98;

        find_node = find(data, &find_el, comparator);
        if (find_node == NULL || *(int *) find_node->data != *(array + 9))
            pos_cnt++;

        free_list(&data);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_pop_front(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 3, test_pos = 2;

    {
        int *data = NULL;
        data = pop_front(NULL);
        if (data != NULL)
            neg_cnt++;
    }

    {
        int *data = NULL;
        node_t *head = NULL;
        data = pop_front(&head);
        if (data != NULL)
            neg_cnt++;
    }

    {
        int *data = NULL;
        node_t *head = malloc(sizeof(node_t));
        head->data = NULL;
        head->next = NULL;
        data = pop_front(&head);
        if (data != NULL)
            neg_cnt++;

        free(head);
        head = NULL;
    }

    {
        int *data = NULL;
        node_t *head = NULL;

        int element = 10;

        head = node_create(&element);

        data = pop_front(&head);
        if (head != NULL || *data != element)
            pos_cnt++;

        free_list(&head);
    }

    {
        int *data = NULL;
        node_t *head = NULL;

        int elements[5] = {1, 2, 3, 4, 5};
        int n = 5, rc = EXIT_SUCCESS;

        for (int i = 0; i < n && !rc; i ++)
            rc = list_push(&head, elements + i);

        if (rc == EXIT_SUCCESS)
        {
            data = pop_front(&head);
            if (head == NULL || *data != *elements)
                pos_cnt++;
        }
        else
            pos_cnt++;

        free_list(&head);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_pop_back(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 3, test_pos = 2;

    {
        int *data = NULL;
        data = pop_back(NULL);
        if (data != NULL)
            neg_cnt++;
    }

    {
        int *data = NULL;
        node_t *head = NULL;
        data = pop_back(&head);
        if (data != NULL)
            neg_cnt++;
    }

    {
        int *data = NULL;
        node_t *head = malloc(sizeof(node_t));
        head->data = NULL;
        head->next = NULL;
        data = pop_back(&head);
        if (data != NULL)
            neg_cnt++;

        free(head);
        head = NULL;
    }

    {
        int *data = NULL;
        node_t *head = NULL;

        int element = 10;

        head = node_create(&element);

        data = pop_back(&head);
        if (head != NULL || *data != element)
            pos_cnt++;

        free_list(&head);
    }

    {
        int *data = NULL;
        node_t *head = NULL;

        int elements[5] = {1, 2, 3, 4, 5};
        int n = 5, rc = EXIT_SUCCESS;

        for (int i = 0; i < n && !rc; i ++)
            rc = list_push(&head, elements + i);

        if (rc == EXIT_SUCCESS)
        {
            data = pop_back(&head);
            if (head == NULL || *data != *(elements + n - 1))
                pos_cnt++;
        }
        else
            pos_cnt++;

        free_list(&head);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_insert(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 3, test_pos = 3;

    {
        int el = 20;
        node_t *insert_el = node_create(&el);
        node_t **data = NULL;
        insert(data, insert_el, NULL);
        if (data != NULL)
            neg_cnt++;

        free_list(&insert_el);
    }

    {
        node_t *data = NULL;
        insert(&data, NULL, data);
        if (data != NULL)
            neg_cnt++;
    }

    {
        int el = 20;
        int el2 = 10;
        node_t *data = NULL;
        node_t *before = node_create(&el);
        node_t *insert_el = node_create(&el2);
        insert(&data, insert_el, before);
        if (data != NULL)
            neg_cnt++;

        free_list(&before);
        free_list(&insert_el);
    }

    {
        int el = 20, el2 = 30, el3 = 40, el4 = 50;
        node_t *data = NULL;
        node_t *insert_el = node_create(&el);

        insert(&data, insert_el, data);
        if (data == NULL || *(int *) data->data != el)
            pos_cnt++;

        insert_el = node_create(&el2);
        insert(&data, insert_el, data);
        if (data == NULL || *(int *) data->data != el2)
            pos_cnt++;

        insert_el = node_create(&el3);
        insert(&data, insert_el, NULL);
        if (data == NULL || *(int *) data->data != el2)
            pos_cnt++;

        insert_el = node_create(&el4);
        insert(&data, insert_el, data->next->next);
        if (data == NULL || *(int *) data->data != el2)
            pos_cnt++;

        free_list(&data);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_append(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 3, test_pos = 2;

    {
        node_t **head_a = NULL, *head_b = NULL;

        append(head_a, &head_b);
        if (head_a != NULL || head_b != NULL)
            neg_cnt++;
    }

    {
        node_t **head_a = NULL, *head_b = NULL;

        append(&head_b, head_a);
        if (head_a != NULL || head_b != NULL)
            neg_cnt++;
    }

    {
        node_t *head_a = NULL, *head_b = NULL;

        append(&head_a, &head_b);
        if (head_a != NULL || head_b != NULL)
            neg_cnt++;
    }

    {
        node_t *head_a = NULL, *head_b = NULL;

        int el = 10;

        head_b = node_create(&el);

        append(&head_a, &head_b);
        if (head_a == NULL || head_b != NULL || *(int *)head_a->data != el)
            pos_cnt++;
        free_list(&head_a);
    }

    {
        node_t *head_a = NULL, *head_b = NULL;
        int elemets[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int n = 10;
        int rc = EXIT_SUCCESS;
        for (int i = 0; i < n && !rc; i++)
        {
            if (i < n / 2)
                list_push(&head_a, elemets + i);
            else
                list_push(&head_b, elemets + i);
        }

        append(&head_a, &head_b);
        if (head_a == NULL || head_b != NULL)
            pos_cnt++;
        else
        {
            int check = 0;
            node_t *check_head = head_a;
            for (int i = 0; i < n && !check; i++, check_head = check_head->next)
                if (*(int *) check_head->data != *(elemets + i))
                {
                    pos_cnt++;
                    check = 1;
                }
        }
        free_list(&head_a);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}

int tests_sort(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 2, test_pos = 2;

    {
        node_t *head = NULL;
        head =sort(head, comparator);
        if (head != NULL)
            neg_cnt++;
    }

    {
        int el = 10;
        node_t *head = node_create(&el);
        head =sort(head, NULL);
        if (head == NULL || *(int *)head->data != el)
            neg_cnt++;

        free_list(&head);
    }

    {
        int elements[10] = {1, 5, 0, -1, 10, 9, -2, 11, 90, -90};
        int el_sort[10] = {-90, -2, -1, 0, 1, 5, 9, 10, 11, 90};
        int n = 10, rc = EXIT_SUCCESS;
        node_t *head = NULL;

        for (int i = 0; i < n && !rc; i++)
            rc = list_push(&head, elements + i);

        if (rc != EXIT_SUCCESS)
            pos_cnt++;
        else
        {
            head = sort(head, comparator);
            if (head == NULL)
                pos_cnt++;
            else
            {
                int check = 0;
                node_t *check_head = head;
                for (int i = 0; i < n && !check; i++, check_head = check_head->next)
                    if (*(int *) check_head->data != *(el_sort + i))
                    {
                        pos_cnt++;
                        check = 1;
                    }
            }
        }

        free_list(&head);
    }

    {
        int elements[10] = {1, 2, 3, 4, 5, 9, 10, 11, 90, 90};
        int n = 10, rc = EXIT_SUCCESS;
        node_t *head = NULL;

        for (int i = 0; i < n && !rc; i++)
            rc = list_push(&head, elements + i);

        if (rc != EXIT_SUCCESS)
            pos_cnt++;
        else
        {
            head = sort(head, comparator);
            if (head == NULL)
                pos_cnt++;
            else
            {
                int check = 0;
                node_t *check_head = head;
                for (int i = 0; i < n && !check; i++, check_head = check_head->next)
                    if (*(int *) check_head->data != *(elements + i))
                    {
                        pos_cnt++;
                        check = 1;
                    }
            }
        }

        free_list(&head);
    }

    print_result_tests((char *) __func__, test_neg, neg_cnt, test_pos, pos_cnt);

    return neg_cnt + pos_cnt;
}