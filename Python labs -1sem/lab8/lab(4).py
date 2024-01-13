matrix = []     # MATRIX
rows = int(input("insert how many ROWS you want: "))     #
columns = int(input("Insert how many columns you want: "))      #
if rows != columns:
    print("NOT SQUARE")
else:
    for i in range(rows):
        row = []
        for j in range(columns):
            element = int(input(f"Insert your value in {i+1}th row and {j+1}th columns: "))
            row.append(element)
        matrix.append(row)

    for arr in matrix:
        for elem in arr:
            print(f"{elem:^4g}", end="")
        print("")
    max_sum = 0     # максимальная сумма
    min_sum = 0     # минимальная сумма
    indmax_ = 0     # максимальный индекс столбецa
    indmin_ = 0     # минимальный индекс столбца
    for i in range(rows):
        sum_ = 0
        for j in range(columns):
            sum_ += matrix[j][i]
        if sum_ > max_sum:
            max_sum = sum_
            indmax_ = i
        if sum_ < min_sum:
            min_sum = sum_
            indmin_ = i
        print(sum_, f" Is the  sum for {i+1} column ")      # узнать, сколько будет сумма
    print(f"The minmum column in index {indmin_} and yhe maximum in index {indmax_}")
    # минимальный столбец в индексе {indmin_} и максимальный в индексе {indmax_}")
    for i in range(rows):
        for j in range(columns):
            matrix[i][indmin_], matrix[i][indmax_] = matrix[i][indmax_], matrix[i][indmin_]
            # поменять местами мин и макс в матрице
    for i in range(rows):
        for j in range(columns):
            print(matrix[i][j], end=" ")
        print("")
