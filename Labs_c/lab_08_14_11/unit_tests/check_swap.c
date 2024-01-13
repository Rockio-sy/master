#include "check_swap.h"

int tests_swap_double_el(void)
{
    int pos_cnt = 0, test_pos = 2;
    {
        double el1 = 10.3;
        double el2 = 30.5;

        swap_double_el(&el1, &el2);
        if (fabs(el1 - 30.5) > EPS || fabs(el2 - 10.3) > EPS)
            pos_cnt++;

        el1 = 10;
        el2 = 30;

        swap_double_el(&el1, &el2);
        if (fabs(el1 - 30) > EPS || fabs(el2 - 10) > EPS)
            pos_cnt++;
    }

    printf("===%s:",  __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS\n");

    return pos_cnt;
}

int tests_swap_column(void)
{
    int pos_cnt = 0, test_pos = 2;
    {
        double c_1[5], c_2[5];
        int n = 5;
        for (int i = 0; i < n; i++)
        {
            c_1[i] = 25.13;
            c_2[i] = 67.89;
        }

        swap_column(c_1, c_2, n);
        for (int i = 0; i < n && pos_cnt == 0; i++)
        {
            if (fabs(c_1[i] - 67.89) > EPS || fabs(c_2[i] - 25.13) > EPS)
                pos_cnt++;
        }
    }

    {
        double c_1[5], c_2[5];
        int n = 5;
        for (int i = 0; i < n; i++)
        {
            c_1[i] = 25;
            c_2[i] = 67;
        }

        swap_column(c_1, c_2, n);
        for (int i = 0; i < n && pos_cnt == 0; i++)
        {
            if (fabs(c_1[i] - 67) > EPS || fabs(c_2[i] - 25) > EPS)
                pos_cnt++;
        }
    }

    printf("===%s:",  __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS\n");

    return pos_cnt;
}