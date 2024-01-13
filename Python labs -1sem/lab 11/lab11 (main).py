""""" import time
import random

n_u = str(input("сколько элементов вам надо в списке, [user_list]: "))  # сколько элементов вам надо в списке
l_us = []
while not n_u:
    n_u = str(input("сколько элементов вам надо в списке, [user_list]: "))
else:
    l_us = []
n_u = int(n_u)
for i in range(n_u):
    element = str(input(f"Insert your {i + 1}th element:"))  # Ввод элементов
    while not element:
        element = str(input(f"Insert your {i + 1}th element:"))  # Ввод элементов
    element = float(element)
    l_us.append(element)


print(f"List before sort: {l_us} \n")
for i in range(1, n_u):
    j = i - 1
    while l_us[j] > l_us[j + 1] and j >= 0:
        l_us[j], l_us[j + 1] = l_us[j + 1], l_us[j]
        j -= 1
print(f"List after sort: {l_us}")


def random_sort(lis: list, n, r_k, time_r):
    tic = time.perf_counter()
    j = 0
    for i in range(n):
        if lis[j] > lis[i]:  # Если число больше предыдущего числа, то добавить 0
            lis.append(0)
            lis[i + 1] = element  # Поменять местами
            r_k += 1
        else:  # Если нет,то  только поменять местами
            lis.append(0)
            lis[i + 1] = lis[i]
            lis[i] = element
            r_k += 1
        j += 1
    toc = time.perf_counter()
    time_r = toc
    lis.pop()
    return r_k, time_r


def Ascending_order(lis: list, n_, k_a, time_a):  # Сортировать в возрастающем порядке
    tic = time.perf_counter()
    for i in range(1, n_):
        j = i - 1
        while lis[j] > lis[j + 1] and j >= 0:
            lis[j], lis[j + 1] = lis[j + 1], lis[j]
            j -= 1
            k_a += 1
    toc = time.perf_counter()
    time_a = (toc - tic)
    time_a += time_a
    return k_a, time_a


def descending_order(lis: list, n, d_k, time_d):  # Сортировать в убывающем порядке
    tic = time.perf_counter()
    for i in range(1, n):
        j = i - 1
        while lis[j] < lis[j + 1] and j >= 0:
            lis[j], lis[j + 1] = lis[j + 1], lis[j]
            j -= 1
            d_k += 1
    toc = time.perf_counter()
    time_d = (toc - tic)
    time_d += time_d
    return d_k, time_d


n1 = int(input("How many elements you want in the first list | сколько элементов вам надо в  первом списке: "))
lis1 = []
for i in range(n1):
    element = random.randint(1, 9)
    lis1.append(element)
a_k1 = d_k1 = r_k1 = time_a1 = time_d1 = time_r1 = 0

n2 = int(input("How many elements you want in the second list |  сколько элементов вам надо в  втором списке : "))
lis2 = []
for i in range(n1):
    element = random.randint(1, 9)
    lis2.append(element)
a_k2 = d_k2 = r_k2 = time_a2 = time_d2 = time_r2 = 0

n3 = int(input("How many elements you want in the third list  | сколько элементов вам надо в  третом списке : "))
lis3 = []
for i in range(n1):
    element = random.randint(1, 9)
    lis3.append(element)
a_k3 = time_r3 = time_d3 = d_k3 = r_k3 = time_a3 = 0

list_a1 = list(Ascending_order(lis1, n1, a_k1, time_a1))
list_d1 = list(descending_order(lis1, n1, d_k1, time_d1))
list_r1 = list(random_sort(lis1, n1, r_k2, time_r1))
list_a2 = list(Ascending_order(lis2, n2, a_k2, time_a2))
list_d2 = list(descending_order(lis2, n2, d_k2, time_d2))
list_r2 = list(random_sort(lis2, n2, r_k2, time_r2))
list_a3 = list(Ascending_order(lis3, n3, a_k3, time_a3))
list_d3 = list(descending_order(lis3, n3, d_k3, time_d3))
list_r3 = list(random_sort(lis3, n3, r_k3, time_r3))
# lis_k = [list_a1[3], list_d1[3], list_r1[3], list_a2[3], list_d2[3], list_r2[3], list_a3[3], list_d3[3], list_r3[3]]
# ln_k = len(max(list()))
print("_" * 169)
print(" " * 48, "N1", " " * 45, "N2", " " * 44, "N3")
print("_" * 169)
print("|Случайный порядок     |",
      "|",
      f'{f"{list_r1[1]:>20.7g}":^10}s',
      f"|{list_r1[0]:>20d}K",
      "|",
      "|",
      f'{f"{list_r2[1]:>20.7g}":^10}s',
      f"|{list_r2[0]:>20d}K|",
      "|", f'{f"{list_r3[1]:>20.7g}":^10}s',
      f"|{list_r3[0]:>20d}K|")
print("")
print(f"|Возрастающий порядок  |", "|", f'{f"{list_a1[1]:>20.7g}":^10}s', f"|{list_a1[0]:>20d}K", "|", "|",
      f'{f"{list_a2[1]:>20.7g}":^10}s', f"|{list_a2[0]:>20d}K|", "|", f'{f"{list_a3[1]:>20.7g}":^10}s',
      f"|{list_a3[0]:>20d}K|")
print("")
print(f"|Убывающий порядок     |", "|", f'{f"{list_d1[1]:>20.7g}":^10}s', f"|{list_r1[0]:>20d}K", "|", "|",
      f'{f"{list_d2[1]:>20.7g}":^10}s', f"|{list_d2[0]:>20d}K|", "|", f'{f"{list_d3[1]:>20.7g}":^10}s',
      f"|{list_d3[0]:>20d}K|")
print("-" * 169)
"""""
# Tarek #Chawech IU7 11-B
# LAB 11
# Метод простых вставок

import time
import random


while True:
    try:
        n_u = int(input("Insert how many elements in the List: "))
        if not (n_u > 0):
            raise ValueError
    except ValueError:
        print("Insert and POSITIVE INTEGER.\n Try again")
    else:
        break
l_us = []
for i in range(n_u):
    element = str(input(f"Insert your {i + 1}th element:"))  # Ввод элементов
    while not element:
        element = str(input(f"Insert your {i + 1}th element:"))  # Ввод элементов
    element = float(element)
    l_us.append(element)
print(f"List before sort: {l_us} \n")
for i in range(1, n_u):
    j = i - 1
    while l_us[j] > l_us[j + 1] and j >= 0:
        l_us[j], l_us[j + 1] = l_us[j + 1], l_us[j]
        j -= 1
print(f"List after sort: {l_us}")


def insertion_sort(lis):
    #    В этой функции мы смотрим на текущий элемент, а затем на элемент, который ему предшествует.
    #     Если больше или меньше (по делу) и проводим процесс уравнивания поменяться местами.......до конца
    k_a = 0
    k_d = 0
    for i in range(1, len(lis)):
        j = i - 1
        while lis[j] > lis[j + 1] and j >= 0:
            lis[j], lis[j + 1] = lis[j + 1], lis[j]
            j -= 1
            k_a += 1
    for i in range(1, len(lis)):
        j = i - 1
        while lis[j] < lis[j + 1] and j >= 0:
            lis[j], lis[j + 1] = lis[j + 1], lis[j]
            j -= 1
            k_d += 1
    return k_a, k_d


def time_found(lis):
    """                           функция расчета времени               """
    t_1 = time.perf_counter()
    k_a, k_d = insertion_sort(lis)
    t_2 = time.perf_counter()
    t1 = t_2 - t_1
    t2 = t1/2
    return t1, t2, k_a, k_d


while True:                     # Убедитесь, что введенные цифры верны
    try:
        n1 = int(input("Insert the N1 value: "))
        n2 = int(input("Insert the N2 value: "))
        n3 = int(input("Insert the N3 value: "))
        if not(n1 > 0 and n2 > 0 and n3 > 0):
            raise ValueError
    except ValueError:
        print("<<<<< The value should be  POSITIVE INTEGER >>>>>")
    else:
        break
#                                               Настроить списки
lis1 = [random.randint(1, 900) for i in range(n1)]
lis2 = [random.randint(1, 900) for i in range(n2)]
lis3 = [random.randint(1, 900) for i in range(n3)]

#                        разворачиваем отсортированные массивы,  чтобы получить отсортированные в обратном порядке
lis1_rev = lis1[::-1]
lis2_rev = lis2[::-1]
lis3_rev = lis3[::-1]

#                                                      реализовать
t1_2, t1_3, k1_a, k1_d = time_found(lis1)
t2_2, t2_3, k2_a, k2_d = time_found(lis2)
t3_2, t3_3, k3_a, k3_d = time_found(lis3)
t1_1, _, _, k1_r = time_found(lis1_rev)
t2_1, _, _, k2_r = time_found(lis2_rev)
t3_1, _, _, k3_r = time_found(lis3_rev)

#                                                      Распечатать таблицу
print()
print('_' * 126)
print(f'|{" " * 34}|{" " * 10}N1 = {n1:<5.5g}{" " * 9}|{" " * 10}N2 = {n2:<5.5g}{" " * 9}|'
      f'{" " * 10}N3 = {n3:<5.5g}{" " * 9}|')
print('|' + '-' * 34 + '|' + ('-' * 29 + '|') * 3)
print(f'|{" " * 34}|     TIME     |      K       |     TIME     |      K       |'
      f'     TIME     |      K       |')
print('|' + '-' * 34 + '|' + ('-' * 14 + '|') * 6)
print(f'|       Упорядоченный список       | {t1_1:12.7g} | {k1_r:12.9g} |'
      f' {t2_1:12.7g} | {k2_r:12.9g} | {t3_1:12.7g} | {k3_r:12.9g} |')
print('|' + '-' * 34 + '|' + ('-' * 14 + '|') * 6)
print(f'|        Случайный список          | {t1_2:12.7g} | {k1_a:12.9g} |'
      f' {t2_2:12.7g} | {k2_a:12.9g} | {t3_2:12.7g} | {k3_a:12.9g} |')
print('|' + '-' * 34 + '|' + ('-' * 14 + '|') * 6)
print(f'| Упорядоченный в обратном порядке | {t1_3:12.7g} | {k1_d:12.9g} |'
      f' {t2_3:12.7g} | {k2_d:12.9g} | {t3_3:12.7g} | {k3_d:12.9g} |')
print('-' * 126)

'''def method_1(n, lista, k):
    if n >= lista[k]:
        return k + 1
    le = 0
    ri = i
    while ri - le > 1:
        mid = (le + ri) // 2
        if a[mid] > n:
            ri = mid
        elif lista[mid] < n:
            le = mid
        else:
            return mid + 1
    if n <= lista[le]:
        return le
    return ri'''

