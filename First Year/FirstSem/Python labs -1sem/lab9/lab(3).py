# Шавиш Тарек ИУ7-11Б
# Подсчитать в каждой строке матрицы D количество элементов, превышающих
# суммы элементов соответствующих строк матрицы Z. Разместить эти
# количества в массиве G, умножить матрицу D на максимальный элемент
# массива G. Напечатать матрицу Z, матрицу D до и после преобразования, а
# также массив G.

n1 = int(input('HOW MANY ROWS (строк) IN MATRIX D: '))
m1 = int(input('HOW MANY COLUMNS (столбц) MATRIX D: '))
D = []
for i in range(n1):
    D.append([])
    for j in range(m1):
        D[i].append(int(input(f'INSERT {j+1}TH ELEMENT in {i+1}TH ROW: ')))
print("LIST D".center(30, "="))
for i in range(n1):
    for j in range(m1):
        print(f"{D[i][j]:3g}", end="")
    print()

Z = []
n2 = int(input('HOW MANY ROWS (строк) IN MATRIX Z: '))
m2 = int(input('HOW MANY COLUMNS (столбц) MATRIX Z: '))
for i in range(n2):
    Z.append([])
    for j in range(m2):
        Z[i].append(int(input(f'INSERT {j+1}TH ELEMENT in {i+1}TH ROW: ')))
print("LIST Z".center(30, "="))
for i in range(n2):
    for j in range(m2):
        print(f"{Z[i][j]:3g}", end="")
    print()

G = []
sums = []  # Массив сумм строк матрицы Z
for i in range(n2):
    s = 0  # Сумма строки матрицы Z
    for j in range(m2):
        s += Z[i][j]
    sums.append(s)
if n1 <= n2:  # Определяем количество элементов матрицы D > суммы соответствующей строки матрицы Z
    for i in range(n1):
        for j in range(m1):
            if D[i][j] > sums[i]:
                G.append(D[i][j])
else:
    for i in range(n2):
        k = 0
        for j in range(m1):
            if D[i][j] > sums[i]:
                k += 1
                G.append(D[i][j])
print("LIST G: ", *G)

for i in range(n1):  # Умножение матрицы D на макс. элемент массива G
    for j in range(m1):
        D[i][j] *= max(G)
print("MATRIX D AFTER MULTIPLICATIONS\n")
for i in range(n1):
    for j in range(m1):
        print(f"{D[i][j]:3g}", end="  ")
    print()