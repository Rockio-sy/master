''' Ковалев Илья ИУ7-11Б
    лаб7 - защита
    вставить строку, не нарушая сортировку'''

inp_list = input('\nВведите список с длинами по возрастанию (через пробел): ').split()
inp_elem = input('Введите элемент для вставки: ')
length = len(inp_elem)

ind = 0
while ind < len(inp_list) and length >= len(inp_list[ind]):
    ind += 1
inp_list.append(' ')
for i in range(len(inp_list) - 1, ind, -1):
    inp_list[i] = inp_list[i - 1]
inp_list[ind] = inp_elem

print('\nПолученный список:')
for elem in inp_list:
    print(f'\t{elem}')
