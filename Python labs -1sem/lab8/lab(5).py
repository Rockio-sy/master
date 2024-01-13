# Тарек шавиш ИУ7-11Б
# найти наибольшее значение вверх по главной диагонали, и минимальное значение под боковой диагональю
matrix = []     # matrikx
rows = int(input("insert how many ROWS you want: "))   
columns = int(input("Insert how many columns you want: "))     
if rows != columns:
    print("NOT SQUARE")
else:
    for i in range(rows):
        row = []
        for j in range(columns):
            element = int(input(f"Insert your value in {i+1}th row and {j+1} columns: "))
            row.append(element)
        matrix.append(row)
    print("Orginal Matrix: ")
    for arr in matrix:
        for elem in arr:
            print(f"{elem:^4g}", end="")
        print("")
    maxi_ = 0       # найти максимум
    for i in range(rows):
        number = matrix[i][i+1:]
        for j in number:
            if j > maxi_:
                maxi_ = j
    print(f"The maximum value is {maxi_}")

    mini_ = maxi_       # найти минимум
    for i in range(rows):
        number = matrix[i][:i]
        for j in number:
            if j < mini_:
                mini_ = j
    print(f"The minimum value is {mini_}")
