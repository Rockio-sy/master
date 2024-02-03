# TAREK #chawich ИУ7-11Б
# Удалить все элементы целочисленного списка , Ноль

n = int(input("Insert how many numbers:"))

numbers = []


for i in range(n):
    elem = int(input(f"Insert your {i+1}th element"))
    numbers.append(elem)

count = 0

for i in range(len(numbers)):
    if numbers[i] == 0:
        count += 1
    else:
        numbers[i-count] = numbers[i]

for i in range(count):
    numbers.pop()
print(*numbers)
