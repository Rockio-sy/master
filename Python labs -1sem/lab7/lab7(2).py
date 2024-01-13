# Tarek #Chawich ИУ7-11Б
# После каждого элемента целочисленного списка, Нечётные элементы, добавить его удвоенное значение.
n = int(input("Insert how many numbers you want:"))     # сколько чисел
list_ = []
for i in range(n):
    element = int(input(f"Inter the {i+1}th element: "))    # Введите число
    list_.append(element)
count = 0
for i in list_:
    if i % 2 == 1:
        count += 1
list_ = [0] * count + list_
i = 0
while count < len(list_):
    list_[i] = list_[count]
    i += 1
    count += 1
    if list_[count - 1] % 2 == 1:
        list_[i] = list_[count - 1] * 2
        i += 1
print(*list_)
