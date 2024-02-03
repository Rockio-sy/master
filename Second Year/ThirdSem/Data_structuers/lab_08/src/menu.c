#include "menu.h"
#include <stdio.h>

void print_menu_info()
{
    printf("\n\nДанная программа позволяет найти самый короткий путь в графе. Граф представляется в виде целочесиленных значений.\n"
           "0 - Выход из программы\n"
           "1 - Ввести граф вручную\n"
           "2 - Ввести граф из файла\n"
           "3 - Вывести граф\n"
           "4 - Вывести вершину с наименьшей суммой путей до всех остальных вершин\n"
            );

    printf("Выберите пункт : ");
}

int read_comand(int *comand)
{
    printf("\nВведите команду: ");

    if (scanf("%d", comand) != 1)
        return ERROR_READING;
    
    if (*comand < 0 || *comand > 4)
    {
        printf("\nОшибка чтения команды");
        return ERROR_READING;
    }
    return OK;
}