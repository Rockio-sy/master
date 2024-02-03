# Шавиш Тарек ИУ7-11Б
#LAB 9(4)
# Задана матрица D и массив I, содержащий номера строк, для которых
# необходимо определить максимальный элемент. Значения максимальных
# элементов запомнить в массиве R. Определить среднее арифметическое
# вычисленных максимальных значений. Напечатать матрицу D, массивы I и R,
# среднее арифметическое значение.
n = str(input('INSERT HOW MANY ROWS(строк) YOU WANT IN MATRIX D : '))
m = str(input('INSERT HOW MANY COLUMNS (столбцов) IN MATRIX  D: '))
n = int(n)
m = int(m)
D = []
for i in range(n):
    D.append([])
    for j in range(m):
        D[i].append(float(input(f'INSERT {j+1}TH ELEMENT  IN {i+1}TH ROW: ')))

print("MATRIX D")
for i in range(n):
    for j in range(m):
        print(f"{D[i][j]:3g}", end=" ")
    print()

L_I = []
n_i = int(input("HOW MANY ELEMENTS IN LIST I: "))
for i in range(n_i):
    elem = float(input(f"INSERT THE {i+1} OF LIST I: "))
    L_I.append(elem)
print("LIST I: ", *L_I)
R = []
for i in range(n):
    maxi = 0
    for j in range(m):
        if D[i][j] > maxi:
            maxi = D[i][j]
    R.append(maxi)
maxo = 0
for i in range(n_i):
    if L_I[i] > maxo:
        maxo = L_I[i]
R.append(maxo)
#                            Нахождение максимальных элементов строк матрицы R по заданному индексу строки
print("LIST R: ", *R)
s = 0  #                        Сумма элементов массива R
for i in range(len(R)):
    s += R[i]
print(f"Arithmetic mean of maximum values: {s/len(R):^3.5g}")