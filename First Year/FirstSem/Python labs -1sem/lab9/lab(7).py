# Шавиш Тарек ИУ7-11Б
# Ввести трехмерную массив, вывести из него i-й срез по второму индексу

z = int(input('INSERT THE MATRIX DIMENSION: '))       # Введите количество матриц

n = int(input('HOW MANY ROWS: '))     # Введите количество строк матриц

m = int(input('HOW MANY COLUMNS: '))  # Введите количетсво столбцов матриц

matrix = []
for z in range(z):
    matrix.append([])
    for i in range(n):
        matrix[z].append([])
        for j in range(m):
            matrix[z][i].append(int(input(f'INSERT {j + 1}TH ELEMENT IN {i + 1}TH ROW IN {z + 1}TH MATRIX: ')))
print()

k = int(input('ENTER SLICE NUMBER AT SECOND INDEX: '))     # номер среза по второму индексу
while k <= 0 or k >= m + 1:
    print('WRONG VALUE!')     # некорректное значение
    k = int(input('ENTER SLICE NUMBER AT SECOND INDEX: '))

#  ТАБЛИЦА
print(f'{k}TH MATRIX: ', end='\n')     # ТАБЛИЦА
col_p = []
for i in range(z + 1):
    col_p.append('|' + f'{i + 1}' + '|')

print('COLUMNS: ', *col_p)

for i in range(n):
    print(f'ROW NUMBER {i + 1}:', end='')
    for j in range(z + 1):
        print(f'{matrix[j][i][k - 1]:15d}', end=' ')
    print()
print('-' * 11 + '-' * (z + 1) * 17)
print()
