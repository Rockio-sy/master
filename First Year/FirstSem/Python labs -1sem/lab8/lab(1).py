# Tarek Chawich ИУ7-11Б
# Найти строку, имеющую определённое свойствo ,Наибольшее среднее арифметическое.
matrix = []   # Mатриц
row = int(input("insert how many ROWS you want: "))  # Сколько строк
columns = int(input("Insert how many columns you want: "))  # Сколько столбцов
if row <= 0 or columns <= 0:
    print("Please repeat.")     # если строки или столбцы равны 0 (STOP)

for i in range(row):
    a = []
    for j in range(columns):
        element = int(input(f"Insert your value in {i+1}th row and {j+1} columns: "))
        a.append(element)
    matrix.append(a)
for ro in matrix:       # Генерировать матрицу
    for ele in ro:
        print(f'{ele:>5g}', end=' ')
    print('')
max_ = 0    # max_ = 0
number_of_row = 0       # Узнать в каком ряду
for i in range(len(matrix)):
    for j in matrix[i]:
        mid = sum(matrix[i])//len(matrix[i])
        if mid >= max_:
            max_ = mid
            number_of_row = i+1
print(f"{max_} is the greater mid,for the {number_of_row} row")
# END
