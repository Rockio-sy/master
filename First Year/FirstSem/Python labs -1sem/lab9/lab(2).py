# Шавиш Тарек ИУ7-11Б
# Повернуть квадратную целочисленную матрицу на 90 градусов по часовой стрелке, затем на 90 градусов против часовой
# стрелки. Вывести исходную,,промежуточную и итоговую матрицы. Дополнительных матриц и массивов не,вводить.
# Транспонирование не применять.


rows = int(input("Insert the dimensions of the matrix: "))      # Вставьте размеры матрицы:
matrix = []
for i in range(rows):
    row = []
    for j in range(rows):
        element = int(input(f"Insert the {j+1}th in {i+1}th row: "))
        row.append(element)
    matrix.append(row)


'''                                                 оригинальный                                                     '''


print("\n ''''    THE ORIGINAL    ''''        \n")

for i in range(rows):
    for j in range(rows):
        print(f"{matrix[i][j]:^5g}", end='')
    print()

'''                                                    Первый поворот                                                '''
# поверните значение, приравняв его к числу в нужном месте по строке и столбцу
print("'''      FIRST ROTATE     '''")
for ro in range(rows // 2):
    for el in range(ro, rows-ro-1):
        fir_num = matrix[ro][el]
        matrix[ro][el] = matrix[rows-el-1][ro]
        matrix[rows-el-1][ro] = matrix[rows-ro-1][rows-el-1]
        matrix[rows-ro-1][rows-el-1] = matrix[el][rows-ro-1]
        matrix[el][rows-ro-1] = fir_num
        print(ro,el)
for i in range(rows):
    for j in range(rows):
        print(f"{matrix[i][j]:^5g}", end=" ")
    print()

'''                                                 второй поворот                                                   '''

print("'''   SECOND ROTATE    '''")
# поверните значение, приравняв его к числу в нужном месте по строке и столбцу
for ro in range(rows//2):
    for el in range(ro, rows-ro-1):
        fir_el1 = matrix[ro][el]
        matrix[ro][el] = matrix[el][rows - ro - 1]
        matrix[el][rows - ro - 1] = matrix[rows - ro - 1][rows - el - 1]
        matrix[rows - ro - 1][rows - el - 1] = matrix[rows - el - 1][ro]
        matrix[rows - el - 1][ro] = fir_el1
for i in range(rows):
    for j in range(rows):
        print(f"{matrix[i][j]:^5g}", end=" ")
    print()
print("WE GOT THE FIRST MATRIX")                        # МЫ ПОЛУЧИЛИ ПЕРВУЮ МАТРИЦУ
# END


# rows = int(input("Insert the dimensions of the matrix: "))      # Вставьте размеры матрицы:
# matrix = []
# for i in range(rows):
#    row = []
#    for j in range(rows):
#        element = int(input(f"Insert the {j+1}th in {i+1}th row: "))
#        row.append(element)
#    matrix.append(row)
#
#
'''                                                 оригинальный                                                     '''
#
#
# print("\n ''''    THE ORIGINAL    ''''        \n")
#
# for i in range(rows):
#    for j in range(rows):
#        print(f"{matrix[i][j]:^5g}", end='')
#    print()
#
'''                                                     Первый поворот                                               '''
#
# print("\n''''    FIRST ROTATE    ''''        \n")
#
# for i in range(len(matrix)):
#    for j in range(len(matrix[i])-1, -1, -1):       # Повернуть от конца к началу
#        print(f"{matrix[j][i]:^5g}", end=" ")
#    print()
'''                                                     второй поворот                                               '''
#
#
# print("\n''''    SECOND ROTATE    ''''        \n")
# for i in range(rows):
#    for j in range(rows):
#        print(f"{matrix[j][i]:^5g}", end='')
#        # вращать с изменением значения какого индекса мы хотим напечатать в каком новом индексе
#    print()
# END
