# Tarek #Chawich ИУ7_11Б
# Поиск элемента в списке строк, с наибольшим числом подряд идущих цифр .
n = int(input("How many strings you want in the list? "))
#                                                       Сколько элементов вам нужно в списке
a = []
digits = ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9')
#                                                       Список чисел, которые нужно найти в серии
for i in range(n):
    element = input(f"Insert your {i+1} strings: ")
    a.append(element)
#                                                       Настройка меню от пользователя
max_len = 0                  # Наибольшее количество повторений во всех элементах
ele = None               # Требуемый элемент
for i in a:
    maximum = 0             # Наибольшее количество повторений в одном элементе
    count = 0               # Сколько раз число встречается в одном элементе
    for j in i:
        if j in digits:     # Если вы найдете элемент, добавьте 1 к количеству раз
            count += 1
        else:
            count = 0
        if count > maximum:         # Если количество раз в одном элементе больше, чем наибольшее количество итераций в одном элементе
            maximum = count
    if maximum == max_len:
        ele = None
    elif maximum > max_len:          # Если количество раз больше, чем наибольшее количество итераций между разрывами ни одного элемента
        max_len = maximum
        ele = i
if ele:
    print(f"{ele} is the element")
else:
    print("there isn't element with most consecutive OR there is tow numbers")    # есть ли два числа или нет
# END
