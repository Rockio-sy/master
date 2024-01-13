# Шавиш Тарек ИУ7-11Б
# LAB 9(6)
# Сформировать матрицу C путём построчного перемножения матриц A и B
# одинаковой размерности (элементы в i-й строке матрицы A умножаются на
# соответствующие элементы в i-й строке матрицы B), потом сложить все
# элементы в столбцах матрицы C и записать их в массив V. Напечатать матрицы
# A, B, C и массив V

from math import inf
n = int(input('Insert how many rows(строке): '))
m = int(input('Insert how many columns (столбцов) : '))
A = []

for i in range(n):
    A.append([])
    for j in range(m):
        A[i].append(float(input(f'Insert {j+1}th element  in {i+1}th row: ')))
print("\nNOW INSERT LIST B\n".center(50, "="))


B = []
for i in range(n):
    B.append([])
    for j in range(m):
        B[i].append(float(input(f'Insert {j+1}th element  in {i+1}th row: ')))

print("MATRIX A")
for i in range(n):
    for j in range(m):
        print(f"{A[i][j]: 3g}", end="")
    print()

print("MATRIX B")
for i in range(n):
    for j in range(m):
        print(f"{B[i][j]: 3g}", end="")
    print()

C = []
for i in range(n):  # Получение матрицы C путем умножения соответствующих элементов из матриц A и B
    C.append([])
    for j in range(m):
        C[i].append(A[i][j]*B[i][j])
print("MATRIX C")
for i in range(n):
    for j in range(m):
        print(f"{C[i][j]: 3g}", end="")
    print()

V = [0]*m
for i in range(n):  # Прибавляем элемент в элемент массива V, который является суммой столбца матрицы C
    for j in range(m):
        V[j] += C[i][j]
print(f"List V has {len(V)} elements =={V}")

"""
print("THE MATRIX A")                                # CОЗДАНИЕ МАТРИЦЫ А


rows_a = int(input("\nHOW MANY ROWS(строка) YOU WANT IN MATRIX A: "))       # Вставьте размеры матрицы A:
columns_a = int(input("\nHOW MANY COLUMNS(столбец) YOU WANT IN MATRIX A: "))
matrix_a = []
for i in range(rows_a):
    row = []
    for j in range(columns_a):
        element = float(input(f"INSERT THE {j+1}th element in {i+1} ROW: "))
        row.append(element)
    matrix_a.append(row)
for i in range(rows_a):
    for j in range(columns_a):
        print(f"{matrix_a[i][j]:^4g}", end="")
    print()


'''                                                  СОЗДАНИЕ МАТРИЦЫ B                                            '''


rows_b = rows_a
columns_b = columns_a
matrix_b = []
print("\nNOW INSERT THE ELEMENTS OF MATRIX B\n")
for i in range(rows_b):
    row = []
    for j in range(columns_b):
        element = float(input(f"INSERT THE {j+1}th element in {i+1} ROW: "))
        row.append(element)
    matrix_b.append(row)


'''                                              СОЗДАНИЕ МАТРИЦЫ C ,массив v                                       '''


matrix_c = []
v_e = 0
v = []
for i in range(rows_a):
    row = []
    for j in range(columns_a):
        element = matrix_a[i][j] * matrix_b[i][j]
        row.append(element)
    matrix_c.append(row)
print(matrix_c)
o = 0
while o != len(matrix_c):
    for j in range(2):
        el = matrix_c[j][o]
        print(el)
    o+=1
print("MATRIX A IS :")
for i in range(rows_a):
    for j in range(columns_a):
        print(f"{matrix_a[i][j]:^4g}", end="")
    print()
print("MATRIX B IS :")
for i in range(rows_b):
    for j in range(columns_b):
        print(f"{matrix_b[i][j]:^4g}", end="")
    print()

print("MATRIX C IS :")
for i in range(rows_b):
    for j in range(columns_b):
        print(f"{matrix_c[i][j]:^4g}", end="")
    print()
print(f"ARRAY V IS :{v}")
"""