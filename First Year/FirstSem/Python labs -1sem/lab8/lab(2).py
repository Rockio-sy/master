# Tarek Chawich ИУ7-11Б
# Переставить местами строки с наибольшим и наименьшим количеством отрицательных элементов
matrix = []     # matrikx
row = int(input("insert how many ROWS you want: "))     #
columns = int(input("Insert how many columns you want: "))      #
min_ = 0    # минимум
max_ = -1   # максимум
rowmin = 0      # место минимума по строке
rowmax = 0      # место мakcимума по строке
clomax = 0      # место минимума по столбцу
clomin = 0      # место мakcимума по столбцу

'''                 генерировать матрицу                '''
for i in range(row):
    a = []
    for j in range(columns):
        element = int(input(f"Insert your value in {i+1}th row and {j+1} columns: "))
        if element < 0:
            if element < min_:
                min_ = element
                rowmax = i
                clomax = j
        if element < 0:
            if element > min_:
                if element < max_:
                    max_ = element
                    rowmin = i
                    clomin = j
                else:
                    max_ = element
                    rowmin = i
                    clomin = j
        a.append(element)
    matrix.append(a)
'''          изменение максимального значения              '''
print(" \n    Original matrix(оригинальный):")
for i in matrix:
    for j in i:
        print(f"  {j:^5g}", end=" ")
    print("")
for i in range(len(matrix)):
    for j in range(len(matrix[i])):
        matrix[rowmax][clomax] = max_

'''          изменение минимального значения               '''
for i in range(len(matrix)):
    for j in matrix[i]:
        matrix[rowmin][clomin] = min_
print("\n   Matrix after change(После изменения):")    # матрица после замены
for i in matrix:
    for j in i:
        print(f" {j:>5g}", end=" ")
    print("")
# END


# if matrix[i][j] == min:
# matrix[i].append(max)
# matrix[i][j] = matrix[i][-1]
# matrix[i].pop()
# print(matrix,'Is here')
# for i in range(len(matrix)):
#    for j in  range(len(matrix[i])):
#        if matrix[i][j] == min:
#           matrix[i].append(max)
#           matrix[i][j] = matrix[i][-1]
#           matrix[i].pop()
#           print(matrix)
