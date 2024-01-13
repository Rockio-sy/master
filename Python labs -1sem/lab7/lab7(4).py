# Tarek #Chawich ИУ7-11Б
# Замена всех строчных согласных английских букв на заглавные
a = str(input("Insert your sentence: "))
# написать предложение
list_ = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z']
# запрещенные буквы
b = [x if x not in list_ else x.upper() for x in a]
# Настроить новое меню
for i in b:
    print(i, end="")
    # END


# a = list(map(str,input("Insert your sentence: ")))     # второй метод
# list = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z']
# for i in list:
#    if i in a:
#        ind = a.index(i)
#        a.remove(i)
#        n = i.upper()
#        a.insert(ind, n)
# s = "".join(a)
# print(s)
