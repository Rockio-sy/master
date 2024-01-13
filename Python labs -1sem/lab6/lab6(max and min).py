# защита
n = 0
while n <= 2:
    n = int(input("Insert the list size: "))
lista = [0]*n
for i in range(len(lista)):
    lista[i] = int(input(f"Insert the {i+1}th element: "))
print(lista)
max = lista[0]
min = lista[0]
ind_min = 0
ind_max = 0
for i in range(len(lista)):
    if lista[i] > max:
        max = lista[i]
        ind_max = i
    if lista[i] < min:
        min = lista[i]
        ind_min = i
lista[ind_max], lista[ind_min] = lista[ind_min], lista[ind_max]
print(lista)
print(max,min)