#include "check_my_snprintf.h"

#define SIZE 101

int my_strlen(const char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int cmp_two_str(const char *a, const char *b)
{
    int rc = 0;
    int i = 0;
    if (my_strlen(a) != my_strlen(b))
        rc = 1;
    else
    {
        while (a[i] != '\0' && !rc)
        {
            if (a[i] != b[i])
                rc = 1;
            i++;
        }
    }
    
    return rc;
}

int test_snprintf_char(void)
{
    int pos_cnt = 0, test_pos = 4;

    int res1 = 0, res2 = 0;
    char str1[SIZE] = { '\0' };
    char str2[SIZE] = { '\0' };

    res1 = my_snprintf(str1, 0, "%c", 'A');
    res2 = snprintf(str2, 0, "%c", 'A');

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 10, "%c%c%c", 'A', 'B', 'C');
    res2 = snprintf(str2, 10, "%c%c%c", 'A', 'B', 'C');

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 10, "%c: hi %c: hello %c: hallo", 'A', 'B', 'C');
    res2 = snprintf(str2, 10, "%c: hi %c: hello %c: hallo", 'A', 'B', 'C');

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 100, "%c: hi %c: hello %c: hallo", 'A', 'B', 'C');
    res2 = snprintf(str2, 100, "%c: hi %c: hello %c: hallo", 'A', 'B', 'C');

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    printf("%s: %d of %d - %s\n", __func__, test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

int test_snprintf_string(void)
{
    int pos_cnt = 0, test_pos = 4;

    int res1 = 0, res2 = 0;
    char str1[SIZE] = { '\0' };
    char str2[SIZE] = { '\0' };

    res1 = my_snprintf(str1, 0, "%s", "Hello");
    res2 = snprintf(str2, 0, "%s", "Hello");

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 40, "%s%s%s", "Hello", " ", "my friend!");
    res2 = snprintf(str2, 40, "%s%s%s", "Hello", " ", "my friend!");

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 10, "%s: hi %s: hello %s: hallo", "A", "B", "C");
    res2 = snprintf(str2, 10, "%s: hi %s: hello %s: hallo", "A", "B", "C");

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 100, "%s: hi %s: hello %s: hallo", "A", "B", "C");
    res2 = snprintf(str2, 100, "%s: hi %s: hello %s: hallo", "A", "B", "C");

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    printf("%s: %d of %d - %s\n", __func__, test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

int test_snprintf_number_d(void)
{
    int pos_cnt = 0, test_pos = 4;

    int res1 = 0, res2 = 0;
    char str1[SIZE] = { '\0' };
    char str2[SIZE] = { '\0' };

    res1 = my_snprintf(str1, 0, "%d", 12323);
    res2 = snprintf(str2, 0, "%d", 12323);

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 40, "%d %d %d", 123, -123, 0);
    res2 = snprintf(str2, 40, "%d %d %d", 123, -123, 0);

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 10, "%d: hi %d: hello %d: hallo", 1, 2, 3);
    res2 = snprintf(str2, 10, "%d: hi %d: hello %d: hallo", 1, 2, 3);

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 100, "%d: hi %d: hello %d: hallo", 1, 2, 3);
    res2 = snprintf(str2, 100, "%d: hi %d: hello %d: hallo", 1, 2, 3);

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    printf("%s: %d of %d - %s\n", __func__, test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

int test_snprintf_number_i(void)
{
    int pos_cnt = 0, test_pos = 4;

    int res1 = 0, res2 = 0;
    char str1[SIZE] = { '\0' };
    char str2[SIZE] = { '\0' };

    res1 = my_snprintf(str1, 0, "%i", 12323);
    res2 = snprintf(str2, 0, "%i", 12323);

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 40, "%i %i %i", 123, -123, 0);
    res2 = snprintf(str2, 40, "%i %i %i", 123, -123, 0);

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 10, "%i: hi %i: hello %i: hallo", 1, 2, 3);
    res2 = snprintf(str2, 10, "%i: hi %i: hello %i: hallo", 1, 2, 3);

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 100, "%i: hi %i: hello %i: hallo", 1, 2, 3);
    res2 = snprintf(str2, 100, "%i: hi %i: hello %i: hallo", 1, 2, 3);

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    printf("%s: %d of %d - %s\n", __func__, test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

int test_snprintf_octal_number(void)
{
    int pos_cnt = 0, test_pos = 4;

    int res1 = 0, res2 = 0;
    char str1[SIZE] = { '\0' };
    char str2[SIZE] = { '\0' };

    res1 = my_snprintf(str1, 0, "%o", 12323);
    res2 = snprintf(str2, 0, "%o", 12323);

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 40, "%o %o %o", 123, -123, 0);
    res2 = snprintf(str2, 40, "%o %o %o", 123, -123, 0);

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 10, "%o: hi %o: hello %o: hallo", 12121, -212341, 34232);
    res2 = snprintf(str2, 10, "%o: hi %o: hello %o: hallo", 12121, -212341, 34232);

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    res1 = my_snprintf(str1, 100, "%o: hi %o: hello %o: hallo", 12121, -212341, 34232);
    res2 = snprintf(str2, 100, "%o: hi %o: hello %o: hallo", 12121, -212341, 34232);

    if (res1 != res2 || cmp_two_str(str1, str2) != 0)
        pos_cnt++;

    printf("%s: %d of %d - %s\n", __func__, test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}
