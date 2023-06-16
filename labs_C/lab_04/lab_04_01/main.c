#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define N 4
#define MAX_LEN_WORD 12

/*
The strpbrk function looks for the first occurrence of a string,
pointed to by argument str1, one of the characters
included in the string pointed to by the str2 argument
*/
char *my_strpbrk(char *str1, char *str2)
{
    size_t i = 0;

    while (str1[i] != '\0')
    {
        size_t j = 0;
        while (str2[j] != '\0')
        {
            if (str1[i] == str2[j])
                return &str1[i];
            j++;
        }
        i++;
    }

    return NULL;
}

/*
The strspn function determines the maximum length of the initial section of a string,
pointed to by the str1 argument, containing only the characters of the string,
pointed to by the str2 argument.
If the first character of str1 is not in str2,
then the returned length is 0
*/
size_t my_strspn(char *str1, char *str2)
{
    size_t n = 0;
    size_t i = 0;

    while (str1[i] != '\0')
    {
        size_t j = 0;
        while (str2[j] != '\0' && str1[i] != str2[j])
        {
            j++;
        }

        if (str1[i] != str2[j])
        {
            return n;
        }
        n++;
        i++;
    }

    return n;
}

/*
The strcspn function determines the maximum length of the initial section of a string,
pointed to by the str1 argument, which does not contain any of the characters in the string,
pointed to by the str2 argument
*/
size_t my_strcspn(char *str1, char *str2)
{
    size_t n = 0;
    size_t i = 0;

    while (str1[i] != '\0')
    {
        size_t j = 0;
        while (str2[j] != '\0')
        {
            if (str1[i] == str2[j])
                return n;
            j++;
        }
        n++;
        i++;
    }

    return n;
}

/*
The strcspn function determines the maximum length of the initial section of a string,
pointed to by the str1 argument, which does not contain any of the characters in the string,
pointed to by the str2 argument
*/
char *my_strchr(char *str, int ch)
{
    size_t i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ch)
            return &str[i];
        i++;
    }

    if (ch == '\0')
        return &str[i];

    return NULL;
}

/*
The strrchr function looks for the last occurrence of a character,
whose code is specified in the ch argument, in the line
pointed to by the str argument
*/
char *my_strrchr(char *str, int ch)
{
    size_t i = 0;
    char *p = NULL;

    while (str[i] != '\0')
    {
        if (str[i] == ch)
            p = &str[i];
        i++;
    }

    if (ch == '\0')
        return &str[i];

    return p;
}

int main(void)
{
    char arr_str1[N][MAX_LEN_WORD] = { "01234567869", "test", "", "Hello world" };
    char arr_str2[N][MAX_LEN_WORD] = { "9876", "hi", "", "Hel" };
    int arr_ch[N] = { '\0', 't', 't', 'H' };
    int count_error = 0;

    for (size_t i = 0; i < N; i++)
    {
        if (my_strpbrk(arr_str1[i], arr_str2[i]) != strpbrk(arr_str1[i], arr_str2[i]))
            count_error++;

        if (my_strspn(arr_str1[i], arr_str2[i]) != strspn(arr_str1[i], arr_str2[i]))
            count_error++;

        if (my_strcspn(arr_str1[i], arr_str2[i]) != strcspn(arr_str1[i], arr_str2[i]))
            count_error++;

        if (my_strchr(arr_str1[i], arr_ch[i]) != strchr(arr_str1[i], arr_ch[i]))
            count_error++;

        if (my_strrchr(arr_str1[i], arr_ch[i]) != strrchr(arr_str1[i], arr_ch[i]))
            count_error++;
    }
    
    printf("Count of errors: %d\n", count_error);

    return EXIT_SUCCESS;
}
