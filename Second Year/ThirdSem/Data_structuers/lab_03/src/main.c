/*
Разреженная (содержащая много нулей) матрица хранится в форме 3-х объектов:
 - вектор A содержит значения ненулевых элементов;
 - вектор IA содержит номера строк для элементов вектора A;
 - вектор JA, в элементе Nk которого находится номер компонент
в A и IA, с которых начинается описание столбца Nk матрицы A.
1. Смоделировать операцию сложения двух матриц, хранящихся в этой форме,
с получением результата в той же форме.
2. Произвести операцию сложения, применяя стандартный алгоритм работы с
матрицами.
3. Сравнить время выполнения операций и объем памяти при использовании
этих 2-х алгоритмов при различном проценте заполнения матриц.
*/

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#include "sparse_matrix.h"
#include "array.h"
#include "matrix.h"

#define FILE_OPEN_ERROR -1

int main(void)
{
    sparse_matrix_t sparse_matrix_1, sparse_matrix_2;
    sparse_matrix_t sparse_matrix_res;
    matrix_t matrix_1, matrix_2;
    matrix_t matrix_res;

    sparse_matrix_t *sparse_matrix = &sparse_matrix_1;

    int choice;
    int rc;
    for (int i = 1; i <= 2; i++)
    {
        printf("Выберите способ ввода матрицы №%d\n", i);
        printf("1. Чтение с клавиатуры.\n");
        printf("2. Чтение из файла.\n");

        if (scanf("%d", &choice) != 1)
        {
            if (i == 2)
                sparse_matrix_free(&sparse_matrix_1);
            return INCORRECT_INPUT;
        }

        switch (choice)
        {
            case 1: // Чтение с клавиатуры
                rc = sparse_matrix_input(sparse_matrix);

                if (rc == INCORRECT_INPUT)
                {
                    printf("Некорректный ввод.\n");
                    if (i == 2)
                        sparse_matrix_free(&sparse_matrix_1);
                    return rc;
                }

                if (rc == ALLOC_ERROR)
                {
                    printf("Ошибка выделения памяти.\n");
                    if (i == 2)
                        sparse_matrix_free(&sparse_matrix_1);
                    return rc;
                }

                if (rc == EXISTING_ELEMENT_ERROR)
                {
                    printf("Ошибка: введён уже введённый элемент.\n");
                    if (i == 2)
                        sparse_matrix_free(&sparse_matrix_1);
                    return rc;
                }
                printf("Успешно!\n");
                break;

            case 2: // Чтение из файла
                printf("Введите путь к файлу:\n");
                char filename[PATH_MAX];
                if (fgets(filename, sizeof(filename), stdin) == NULL)
                    ;
                if (fgets(filename, sizeof(filename), stdin) == NULL)
                {
                    printf("Ошибка ввода.\n");
                    if (i == 2)
                        sparse_matrix_free(&sparse_matrix_1);
                    return INCORRECT_INPUT;
                }
                if (filename[strlen(filename) - 1] == '\n')
                    filename[strlen(filename) - 1] = '\0';
                
                FILE *f = fopen(filename, "r");
                if (f == NULL)
                {
                    printf("Ошибка открытия файла.\n");
                    if (i == 2)
                        sparse_matrix_free(&sparse_matrix_1);
                    return FILE_OPEN_ERROR;
                }

                rc = sparse_matrix_fscan(sparse_matrix, f);

                if (rc == INVALID_FILE)
                {
                    printf("Файл повреждён или пуст.\n");
                    if (i == 2)
                        sparse_matrix_free(&sparse_matrix_1);
                    fclose(f);
                    return rc;
                }

                if (rc == ALLOC_ERROR)
                {
                    printf("Ошибка выделения памяти.\n");
                    if (i == 2)
                        sparse_matrix_free(&sparse_matrix_1);
                    fclose(f);
                    return rc;
                }
                
                if (rc == EXISTING_ELEMENT_ERROR)
                {
                    printf("Ошибка: в файле несколько раз указан один и тот же элемент.\n");
                    if (i == 2)
                        sparse_matrix_free(&sparse_matrix_1);
                    fclose(f);
                    return rc;
                }

                fclose(f);

                printf("Успешно!\n");

                #ifdef DEBUG
                sparse_matrix_output(sparse_matrix);
                #endif
                
                break;

            default:
                printf("Неверный выбор.\n");
                if (i == 2)
                    sparse_matrix_free(&sparse_matrix_1);
                return INCORRECT_INPUT;
        }

    sparse_matrix = &sparse_matrix_2; // Чтение второй матрицы
    }

    printf("Выберите действие:\n");
    printf("1. Сложить матрицы и вывести в виде CSC.\n");
    printf("2. Сложить матрицы и вывести в виде CSC и в виде матрицы.\n");
    printf("3. Вывести время сложения матрицы в виде CSC и в виде матрицы.\n");
    printf("4. Вывести количество памяти, занимаемое матрицами и их суммой.\n");

    if (scanf("%d", &choice) != 1)
    {
        printf("Некорректный ввод.\n");
        return INCORRECT_INPUT;
    }

    switch (choice)
    {
        case 1:
            rc = sparse_matrices_add(&sparse_matrix_res, &sparse_matrix_1, &sparse_matrix_2);

            if (rc == DIFFERENT_SIZE)
            {
                sparse_matrix_free(&sparse_matrix_1);
                sparse_matrix_free(&sparse_matrix_2);
                printf("Ошибка: размерности матриц не совпадают.\n");
                return rc;
            }

            if (rc == ALLOC_ERROR)
            {
                printf("Ошибка выделения памяти.\n");
                sparse_matrix_free(&sparse_matrix_1);
                sparse_matrix_free(&sparse_matrix_2);
                return rc;
            }

            printf("Результат сложения:\n");
            sparse_matrix_output(&sparse_matrix_res);

            break;

        case 2:
            rc = sparse_matrices_add(&sparse_matrix_res, &sparse_matrix_1, &sparse_matrix_2);

            if (rc == DIFFERENT_SIZE)
            {
                sparse_matrix_free(&sparse_matrix_1);
                sparse_matrix_free(&sparse_matrix_2);
                printf("Ошибка: размерности матриц не совпадают.\n");
                return rc;
            }

            if (rc == ALLOC_ERROR)
            {
                printf("Ошибка выделения памяти.\n");
                sparse_matrix_free(&sparse_matrix_1);
                sparse_matrix_free(&sparse_matrix_2);
                return rc;
            }

            rc = sparse_matrix_to_matrix(&matrix_res, &sparse_matrix_res);

            if (rc == ALLOC_ERROR)
            {
                printf("Ошибка выделения памяти.\n");
                sparse_matrix_free(&sparse_matrix_1);
                sparse_matrix_free(&sparse_matrix_2);
                sparse_matrix_free(&sparse_matrix_res);
                return rc;
            }

            printf("Результат сложения:\n");
            sparse_matrix_output(&sparse_matrix_res);
            printf("\n");
            matrix_output(&matrix_res);

            matrix_free(&matrix_res);

            break;

        case 3:;
            microsecond_t time_cur;
            microsecond_t time_total_sparse = 0;
            microsecond_t time_total_std = 0;

            int count;
            printf("Введите количество измерений: \n");
            if (scanf("%d", &count) != 1)
            {
                sparse_matrix_free(&sparse_matrix_1);
                sparse_matrix_free(&sparse_matrix_2);
                printf("Некорректный ввод.\n");
                return rc;
            }
            
            for (int i = 0; i < count; i++)
            {
                rc = time_sparse_matrices_add(&time_cur, &sparse_matrix_res, &sparse_matrix_1, &sparse_matrix_2);
                time_total_sparse += time_cur;

                if (rc == DIFFERENT_SIZE)
                {
                    sparse_matrix_free(&sparse_matrix_1);
                    sparse_matrix_free(&sparse_matrix_2);
                    printf("Ошибка: размерности матриц не совпадают.\n");
                    return rc;
                }

                if (rc == ALLOC_ERROR)
                {
                    printf("Ошибка выделения памяти.\n");
                    sparse_matrix_free(&sparse_matrix_1);
                    sparse_matrix_free(&sparse_matrix_2);
                    return rc;
                }

                rc = sparse_matrix_to_matrix(&matrix_1, &sparse_matrix_1);
                if (rc == ALLOC_ERROR)
                {
                    printf("Ошибка выделения памяти.\n");
                    sparse_matrix_free(&sparse_matrix_1);
                    sparse_matrix_free(&sparse_matrix_2);
                    sparse_matrix_free(&sparse_matrix_res);
                    return rc;
                }

                rc = sparse_matrix_to_matrix(&matrix_2, &sparse_matrix_2);
                if (rc == ALLOC_ERROR)
                {
                    printf("Ошибка выделения памяти.\n");
                    sparse_matrix_free(&sparse_matrix_1);
                    sparse_matrix_free(&sparse_matrix_2);
                    sparse_matrix_free(&sparse_matrix_res);
                    matrix_free(&matrix_1);
                    return rc;
                }

                rc = time_matrices_add(&time_cur, &matrix_res, &matrix_1, &matrix_2);
                time_total_std += time_cur;
                if (rc == DIFFERENT_SIZE)
                {
                    printf("Ошибка: размерности матриц не совпадают.\n");
                    sparse_matrix_free(&sparse_matrix_1);
                    sparse_matrix_free(&sparse_matrix_2);
                    sparse_matrix_free(&sparse_matrix_res);
                    matrix_free(&matrix_1);
                    matrix_free(&matrix_2);
                    return rc;
                }

                if (rc == ALLOC_ERROR)
                {
                    printf("Ошибка выделения памяти.\n");
                    sparse_matrix_free(&sparse_matrix_1);
                    sparse_matrix_free(&sparse_matrix_2);
                    sparse_matrix_free(&sparse_matrix_res);
                    matrix_free(&matrix_1);
                    matrix_free(&matrix_2);
                    return rc;
                }
            }

            printf("Время сложения разреженных матриц: %"MSC" мкс.\n", time_total_sparse / count);
            printf("Время сложения стандартных матриц: %"MSC" мкс.\n", time_total_std / count);

            matrix_free(&matrix_1);
            matrix_free(&matrix_2);
            matrix_free(&matrix_res);

            break;

        case 4:
            rc = sparse_matrices_add(&sparse_matrix_res, &sparse_matrix_1, &sparse_matrix_2);

            if (rc == DIFFERENT_SIZE)
            {
                sparse_matrix_free(&sparse_matrix_1);
                sparse_matrix_free(&sparse_matrix_2);
                printf("Ошибка: размерности матриц не совпадают.\n");
                return rc;
            }

            if (rc == ALLOC_ERROR)
            {
                printf("Ошибка выделения памяти.\n");
                sparse_matrix_free(&sparse_matrix_1);
                sparse_matrix_free(&sparse_matrix_2);
                return rc;
            }
            
            rc = sparse_matrix_to_matrix(&matrix_1, &sparse_matrix_1);
            if (rc == ALLOC_ERROR)
            {
                printf("Ошибка выделения памяти.\n");
                sparse_matrix_free(&sparse_matrix_1);
                sparse_matrix_free(&sparse_matrix_2);
                sparse_matrix_free(&sparse_matrix_res);
                return rc;
            }

            rc = sparse_matrix_to_matrix(&matrix_2, &sparse_matrix_2);
            if (rc == ALLOC_ERROR)
            {
                printf("Ошибка выделения памяти.\n");
                sparse_matrix_free(&sparse_matrix_1);
                sparse_matrix_free(&sparse_matrix_2);
                sparse_matrix_free(&sparse_matrix_res);
                matrix_free(&matrix_1);
                return rc;
            }

            rc = matrices_add(&matrix_res, &matrix_1, &matrix_2);
            if (rc == DIFFERENT_SIZE)
            {
                printf("Ошибка: размерности матриц не совпадают.\n");
                sparse_matrix_free(&sparse_matrix_1);
                sparse_matrix_free(&sparse_matrix_2);
                sparse_matrix_free(&sparse_matrix_res);
                matrix_free(&matrix_1);
                matrix_free(&matrix_2);
                return rc;
            }

            if (rc == ALLOC_ERROR)
            {
                printf("Ошибка выделения памяти.\n");
                sparse_matrix_free(&sparse_matrix_1);
                sparse_matrix_free(&sparse_matrix_2);
                sparse_matrix_free(&sparse_matrix_res);
                matrix_free(&matrix_1);
                matrix_free(&matrix_2);
                return rc;
            }

            printf("Память, занимаемая 1-й матрицей в разреженном виде: %zu байт.\n", sparse_matrix_size(&sparse_matrix_1));;
            printf("Память, занимаемая 2-й матрицей в разреженном виде: %zu байт.\n", sparse_matrix_size(&sparse_matrix_2));
            printf("Память, занимаемая суммой матриц в разреженном виде: %zu байт.\n", sparse_matrix_size(&sparse_matrix_res));
            printf("Память, занимаемая 1-й и 2-й матрицей и их суммой в стандартном виде: %zu байт.\n", matrix_size(&matrix_res));

            matrix_free(&matrix_1);
            matrix_free(&matrix_2);
            matrix_free(&matrix_res);

            break;

        default:
            printf("Некорректный выбор.\n");
            sparse_matrix_free(&sparse_matrix_1);
            sparse_matrix_free(&sparse_matrix_2);
            return INCORRECT_INPUT;
    }

    sparse_matrix_free(&sparse_matrix_1);
    sparse_matrix_free(&sparse_matrix_2);
    sparse_matrix_free(&sparse_matrix_res);

    return EXIT_SUCCESS;
}
