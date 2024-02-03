# TAREK CHAWICH IU7
# LAB 12
# умножение и деление
# 6. Наиболее часто встречающееся слово в каждом предложении
text = ["Настенная сплит-система — самый популярный и универсальный тип кондиционеров. Она включает в себя внутренний,",
        "блоккоторый крепится на стене в помещении, и внешний, монтируемый на фасаде здания. Они могут находиться на  ",
        "расстоянии до 20 метров. Между 15.5 / 5 блоками циркулирует не воздух, а фреон. В режиме охлаждения  забирает",
        "из"," помещения и выводит его наружу.В мульти-сплит-системах 3 * 4 внутренних блоков может быть несколько,      ",
        "но при этом все они соединяются лишь с одним наружным.   Такие системы                                       ",
        "подходят для кондиционирования сразу нескольких комнат или же одного большого зала при размещении внутренних ",
        "блоков в различных его частях."]

'''                                           Выровнять текст по левому краю                                '''


def align_r(lista):
    for i in lista:
        print(i)
    return " "


'''                                           Выровнять текст по правому краю                                '''


def align_l(lista):
    length = max([len(i) for i in lista])
    for line in range(len(lista)):
        print(" " * (length - len(lista[line])), lista[line])

    return " "


'''                                           Выровнять текст по ширине.                                      '''


def align_c(lista):
    length = max([len(line) for line in lista])
    new_txt = []
    for line in lista:
        words = line.split()
        spaces = length
        for word in words:
            spaces -= len(word)
        space_len, rest = spaces // (len(words) ), spaces % (len(words) )
        part1 = (' '*space_len).join(words[:-(rest+1)])
        part2 = (' '*(space_len + 1)).join(words[-(rest+1):])
        new_txt.append((' '*space_len).join([part1, part2]))
    for i in new_txt:
        print(i)
    return" "


'''                                           Удаление всех вхождений заданного слова.                        '''


def delete_word(lista):
    user_w = str(input("Insert your word to delete: "))
    lc = []             # места слов в тексте
    i = 0               # Прилавок
    for line in lista:
        words = line.split()
        for word in words:
            i += 1
            if word == user_w:
                words.remove(word)
                word_place = i
                lc.append(word_place)
        print(*words)
    for i in lc:
        print("="*25, f"We removed {i}th word.", "="*25)
    return " "


'''                                          Замена одного слова другим во всём тексте                        '''


def replace_word(lista):
    user_w = str(input("Insert your word to replace: "))            # Слово, которое нужно заменить
    user_n = str(input("Insert your word to insert : "))            # новое слово
    n_lines = []
    for line in lista:
        words = line.split()
        n_words = []
        for word in words:
            n_word = word
            if word == user_w:
                n_word = user_n
            n_words.append(n_word)
        n_lines.append(n_words)
    for i in n_lines:
        print(*i, end="\n")
    return " "


'''                                          Вычисление операций сложения и вычитания внутри текста            '''


def calculation(lista):
    res = []        # Результирующий
    count = 0       # Прилавок
    for line in lista:
        pics = line.split()
        for sign in range(len(pics)):       # sign == ЗНАК
            if pics[sign] == '*' or pics[sign] == '/' or pics[sign] == "//":
                count += 1
                num1, num2 = float(pics[sign - 1]), float(pics[sign + 1])

                if pics[sign] == "*":       # num1 , num2 ПЕРВОЕ И ВТОРОЕ ЧИСЛО
                    num_1, num_2 = num1, num2
                    tim = num1 * num2
                    res.append(tim)
                    pics[sign - 1] = pics[sign + 1] = ""
                    pics[sign] = f"{tim:3g}"
                elif pics[sign] == "/" or pics[sign] == "//":
                    num_1, num_2 = num1, num2
                    diva = num1 // num2
                    pics[sign - 1] = pics[sign + 1] = ""
                    pics[sign] = f"{diva:3g}"
                else:
                    print("Error not founded.. maybe you inserted a valid number.\n Please try again")
                    print(f"The text has {count} calculations.")
        print(*pics)
    return " "


'''                Найти (вывести на экран) и затем удалить Наиболее часто встречающееся слово в каждом предложении..'''


def most_word(lista):
    max_counter = 0         # прилавок
    word = ''       # текущее слово
    fin_word = ''       # Последнее слово
    for line in lista:
        words = line.split()
        count = 0
        for i in range(len(words)):
            max_counter = 0
            for j in range(i + 1, len(words)):
                if words[i] == words[j]:
                    count += 1
                    word = words[i]
        if count >= max_counter:
            max_counter = count
            fin_word = word
    del_wo = word
    lc = []
    i = 0
    for line in lista:
        words = line.split()
        for word in words:
            i += 1
            if word == del_wo:
                words.remove(word)
                word_place = i
                lc.append(word_place)
        print(*words)
    print("THE MOST FAMOUS WORD".center(100, "="))
    print(f"((((({fin_word}))))) ")
    return " "


print("THE MENU".center(108, '='))
print(" 1: (Выровнять текст по левому краю.),\n "
      "2: (Выровнять текст по правому краю.)\n",
      "3: (Выровнять текст по ширине.),\n",
      "4: (Удаление всех вхождений заданного слова.),\n",
      "5: (Замена одного слова другим во всём тексте.),\n",
      "6: (Вычисление операций сложения и вычитания внутри текста.),\n",
      "7: (Найти (вывести на экран) и затем удалить (6). Наиболее часто встречающееся слово в каждом "
      "предложении.')"
      )
print("|".center(108, "="))
n = 0
while n != 1:
    Q = int(input("Insert wich task you want: "))
    if Q == 1:
        print(align_r(text))
    elif Q == 2:
        print(align_l(text))
    elif Q == 3:
        print(align_c(text))
    elif Q == 4:
        print(delete_word(text))
    elif Q == 5:
        print(replace_word(text))
    elif Q == 6:
        print("If you want to Insert new equation it should be like formula\n          A * B ")
        print(calculation(text))
    elif Q == 7:
        print(most_word(text))
    else:
        break

'''for i in range(len(text)):
    print(f"{text[i]:>150}")
for i in range(len(text)):
    print(f"{text[i]:<150}")
print()
for i in range(len(text)):
    print(f"{text[i]:^150}")
    '''
