n = int(input("Dimensions: "))
m = []
for i in range(n):
    row = []
    for j in range(n):
        ele = int(input(f"Insert the {j + 1} element in the {i + 1} row :"))
        row.append(ele)
    m.append(row)
for i in range(n):
    for j in range(n):
        print(f"{m[i][j]}", end=" ")
    print()


mini = []

for i in range(n):
    for j in range(n):
        if i > j and i + j < n:
            mini.append(m[i][j])
print(min(mini))