# Шавиш Тарек ИУ7-11Б
# Дана матрица символов. Заменить в ней все гласные английские буквы на
# точки. Напечатать матрицу до и после преобразования.

rows = int(input("HOW MANY ROWS(строка) YOU WANT: "))      # создать матрицу:
columns = int(input("HOW MANY COLUMNS(столбец) YOU WANT"))
matrix = []
list_c = ['a', 'u', 'o', 'i', 'y', 'e']
for i in range(rows):
    row = []
    for j in range(columns):
        element = str(input(f"Insert the  {j+1}th element in {i+1}th row: "))
        row.append(element)
    matrix.append(row)

print("THE ORIGINAL MATRIX: \n")

for i in range(rows):
    for j in range(columns):
        print(f"{matrix[i][j]:^3}", end='')
    print()

print("'''         AFTER CHANGE       '''")
# создаем цикл, затем смотрим, есть ли письмо из заблокированных фильтров
# если да, то мы проверяем

for i in range(rows):
    for j in range(columns):
        if matrix[i][j] in list_c:
            matrix[i][j] = '.'
        print(f"{matrix[i][j]:^3}", end='')
    print()
