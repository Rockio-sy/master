# Tarek Chawich  ИУ7-11Б
# Выполнить транспонирование квадратной матрицы
matrix = []     # matrikx
rows = int(input("insert how many ROWS you want: "))
columns = int(input("Insert how many columns you want: "))
if rows!=columns:
    print("NOT SQUARE")
else:
    for i in range(rows):
        row = []
        for j in range(columns):
            element = int(input(f"Insert your value in {i+1}th row and {j+1} columns: "))
            row.append(element)
        matrix.append(row)

    for arr in matrix:
        for elem in arr:
            print(f"{elem:^4g}", end="")
        print("")

    print("After change:")

    for i in range(rows):
        for j in range(columns):
            print(f"{matrix[j][i]:^4g}", end="")
        print("")
