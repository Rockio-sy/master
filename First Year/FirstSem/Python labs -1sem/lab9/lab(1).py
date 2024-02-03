# Шавиш Тарек ИУ7-11Б
# Даны массивы D и F. Сформировать матрицу A по формуле {{{  ajk = sin(dj+fk)  }}}.
# Определить среднее арифметическое положительных чисел каждой строки
# матрицы и количество элементов, меньших среднего арифметического.
# Результаты записать соответственно в массивы AV и L. Напечатать матрицу A в
# виде матрицы и рядом столбцы AV и L.
import math

n = int(input('Enter the size of the array D: '))
d = []
for i in range(n):
    d.append(int(input(f'Insert  {i + 1:g}th element for list: ')))

m = int(input('Enter dimensions array F: '))
f = []
for i in range(m):
    f.append(int(input(f'Insert {i + 1:g}th element  for array: ')))

a = []
for i in range(len(d)):
    a.append([])
    for j in range(len(f)):
        a[i].append(math.sin(d[i] + f[j]))

av = []  # Пустой массив для записи ср арифм каждой строки
for i in range(len(d)):
    k = 0
    s = 0
    sr_arif = 'A'
    for j in range(len(f)):
        if a[i][j] > 0:
            k += 1  # Считаем количетсво и сумму положительных чисел
            s += a[i][j]
    if k != 0:
        sr_arif = s / k
        av.append(sr_arif)  # Ввод значения ср арифм положительных чисел
    else:
        av.append(None)  # Если в списке нет положит чисел, то добавляем None
l = []  # Пустой массив для записи количетства элементов строк меньших ср арифм
for i in range(len(d)):
    k = 0
    for j in range(len(f)):
        if av[i] != None:
            if a[i][j] < av[i]:  # Если в строке найден ср арифм положительных чисел,
                k += 1  # то считаем количество элементов меньших ср арифм
    if k != 0:
        l.append(k)
    else:
        l.append(None)

        #   ТАБЛИЦА   #
print('Input Matrix: ', end='\n')
colomns = []
lenght = len(f)
for i in range(lenght):
    colomns.append(' ' * 14 + f'{i + 1}')

print('Columns: ', *colomns, ' ' * 5 + 'Mid Arithmetic' + ' ' * 5 + 'How many elements lower than mid.')

for i in range(len(d)):
    print(f'Row No.{i + 1}:', end='')
    for j in range(lenght):
        print(f'{a[i][j]:15g}', end=' ')
    if av[i] == None:
        if l[i] == None:
            print(' ' * 11, av[i], ' ' * 24, l[i], end=' ')
        else:
            print(' ' * 11, av[i], ' ' * 22, l[i], end=' ')
    else:
        if l[i] == None:
            print(f'{av[i]:16g}' + ' ' * 25, l[i], end=' ')
        else:
            print(f'{av[i]:16g}' + ' ' * 28, l[i], end=' ')
    print()
print('-' * 11 + '-' * lenght * 17 + '-' * 57)
