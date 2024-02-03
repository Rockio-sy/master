# Tarek Chawich ИУ7-11Б
# Найти столбец, имеющий разница между модулями суммы отрицательных и положительных элементов минимальна.


#                                                     сгенерировать матрицу


rows = int(input("How many ROWS you want: "))
columns = int(input("How many columns you want: "))
matrix = []
for i in range(rows):
    matrix.append([])
    for j in range(columns):
        matrix[i].append(int(input(f"Insert the number in {i+1}th row, and  in {j+1}th column:")))  # ввести матрицу
for i in range(len(matrix)):
    for j in range(len(matrix[i])):
        print(" ", matrix[i][j], end="")
    print()


'''                                                         ответь на вопрос                                      '''


print("After Find")
negativ = 0                     # положительная сумма
positive = 0                    # отрицательная сумма
for i in range(rows):
    for j in range(columns):
        if matrix[j][i] < 0:
            negativ += abs(matrix[j][0])
        if matrix[j][i] > 0:
            positive += abs(matrix[j][0])

minim = abs(negativ - positive)  # Максимальная разница
i = j = 0
column = 0  # Минимальная разница столбца

while j < columns:
    sum_positive = 0  # сумма отрицательных элементов
    sum_negative = 0  # сумма положительных элементов
    while i < rows:
        if matrix[i][j] < 0:
            sum_negative += abs(matrix[i][j])
        if matrix[i][j] > 0:
            sum_positive += abs(matrix[i][j])
        i += 1
    if abs(sum_negative - sum_positive) <= minim:
        minim = abs(sum_negative - sum_positive)
        column = j
    i = 0
    j += 1
print("The minimum difference is : ", minim)     # Минимальная разница составляет
print("Minimum column difference: ", column+1)    # Минимальная разница столбца
