# Tarek shawesh
#IU7-11B
import os

head = f"|{'-' * 59}|{'-'*25}|{'-'*24}|{'-'*15}|"\
    f"\n|{'product name':^59}|{'Quantity':^25}|{'Price for one':^24}|" \
       f" {'Order':^14}|\n|{'-' * 59}|{'-'*25}|{'-'*24}|{'-'*15}|"
f = " "
bot = f"{f:^58}|{f:^25}|{f:^24}|{f:^15}|\n"
names = []
quans = []
pris = []
orders = []
'''                                         Create the file if doesn't exist                                         '''


def creat_file(file):
    try:
        file = input("Insert the new name with out form:")
        if len(file) == 0:
            print("try again")
    except:
        print("try again")
    with open(file, "a"):
        print(f"The currently file is {file}.txt")
    return file


'''                                          printing the database                                                   '''


def data_b(file):
    with open(file, "w") as lw:
        lw.write(head)
        lw.close()
    with open(file, "r")as lr:
        for line in lr:
            print(line, end='')
    return " \n"


'''                                         additional productions                                                   '''


def add_prod(file):
    p_q = " "
    names = []
    quans = []
    pris = []
    orders = []
    while True:
        if p_q.isdigit() == False:
            p_q = str(input("\nHow many productions you want to  insert: "))
        else:
            p_q = int(p_q)
            break
    for i in range(p_q):
        print(i)
        while True:
            name = input(f"Insert the {i+1}th product name : ").strip()
            if len(name) == 0:
                print("Insert again")
            else:
                names.append(name)
                break
        while True:
            try:
                pric = input(f"Insert the {i+1}th product price: ")
                if len(pric) == 0:
                    print("Insert again")
                else:
                    pris.append(pric)
                    break
            except:
                print("There was an error pleas try again.")
        while True:
            try:
                quan = input("How many pieces? ")
                if len(quan) == 0:
                    print("Insert again")
                else:
                    quans.append(quan)
                    break
            except:
                print("There was an error please try again.")
        orders.append(str(i+1))
    with open(file, "a") as f:
        for i in range(p_q):
            f.write(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|{orders[i]:^15}|\n")
            f.write(f"|{'-' * 59}|{'-'*25}|{'-'*24}|{'-'*15}|")
        f.close()
    q = input("All information has been added, Do you want to see? (y/n):")
    if q.lower() == "y":
        print()
        with open(file, "r") as fr:
            for line in fr:
                print(fr.read(), end="")
    else:
        pass
    return pris, orders, quans, names


'''                                          remove productions                                                      '''


def remove(file):
    with open(file, "r") as fr2:
        legh = 0
        for line in fr2:
            legh += len(line)
        if legh != 0 :
            while True:
                try:
                    r_i = input("\nInsert which one do you want to remove\n 0 ==> exit:")
                    if len(r_i) == 0:
                        print("Try again")
                    else:
                        r_i = int(r_i)
                        break
                except:
                    print("There is a problem, Try again please.")
            if r_i > len(names):
                print(" There isn't prod with this number,Try again")
            else:
                for i in range(len(pris)):
                    with open(file, "w") as fw2:
                        fw2.write(head)
                        for i in range(len(names)):
                            if i == (r_i - 1):
                                print(f"{r_i}th row had deleted".center(50, "="))
                            else:
                                fw2.write(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|{orders[i]:^15}|\n")
                                fw2.write(f"|{'-' * 59}|{'-' * 25}|{'-' * 24}|{'-' * 15}|")
                        file = fw2
                    break
            with open(file, 'r') as fr3:
                for line in fr3:
                    print(fr3.read())
        else:
            print("This file is empty, Insert some products then remove")
    return file


'''                                         find productions                                                         '''


def find(file):

    with open(file, "r") as fs:
        legh = 0
        for line in fs:
            legh += 1
        if legh >= 3:
            while True:
                try:
                    print('=' * 21)
                    print(
                     "| 1 ===> price    |\n| 2 ===> order    |\n| 3 ===> quantity |\n| 4 ===> name     |\n|5 ===>"
                     " exit     |")
                    print('=' * 21)
                    guss = str(input(" In which type you want search?\n 0 ==> exit "))
                    if guss == 0:
                        break
                    if len(guss) == 0 or guss.isalpha() == True:
                       print("Try again")
                    elif guss.isdigit() == True:
                        guss = int(guss)
                        if guss <= 4:
                            break
                        else:
                            print("Try again")
                except :
                    print("There is some problems, Try again pleas ")
            while True:
                if guss == 1:
                    gss = input("Insert the prod properties: ")
                    if gss in pris:
                        for i in range(len(pris)):
                            if pris[i] == gss:
                                print(head)
                                print(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|"
                                      f"{orders[i]:^15}|\n")
                        break

                    else:
                        print("Not such as prod, Please Try to write again")
                elif guss == 2:
                    gss = input("Insert the prod properties: ")
                    if gss in orders:
                        for i in range(len(orders)):
                            if orders[i] == gss:
                                print(head)
                                print(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|"
                                      f"{orders[i]:^15}|\n")
                        break
                    else:
                        print("Not such as prod, Please Try to write again")
                elif guss == 3:
                    gss = input("Insert the prod properties: ")
                    if gss in quans:
                        for i in range(len(quans)):
                            if quans[i] == gss:
                                print(head)
                                print(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|"
                                      f"{orders[i]:^15}|\n")
                        break
                    else:
                        print("Not such as prod, Please Try to write again")
                elif guss == 4:
                    gss = input("Insert the prod properties: ")
                    if gss in names:
                        for i in range(len(orders)):
                            if names[i] == gss:
                                print(head)
                                print(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|"
                                      f"{orders[i]:^15}|\n")
                        break
                    else:
                        print("Not such as prod, Please Try to write again")
                else:
                    break
        else:
            print("This file is empty.")
    return " "


'''                                     find productions in tow ways                                                 '''


def find_plus(file):

    with open(file, "r") as ff2:
        leng = 0
        for line in ff2:
            leng += 1
        if leng > 3:
            while True:
                try:
                    print('=' * 21)
                    print(
                        "| 1 ===> price    |\n| 2 ===> order    |\n| 3 ===> quantity |\n| 4 ===> name     |\n|5 ===>"
                        " exit     |")
                    print('=' * 21)
                    guss1 = str(input(" In which first type you want search?\n 0 ==> exit "))

                    '''                            select the  first search type                                     '''

                    if guss1 == 0:
                        break
                    if len(guss1) == 0 or guss1.isalpha() == True:
                        print("Try again\nInsert number please!!!")
                    elif guss1.isdigit() == True:
                        guss1 = int(guss1)
                        if guss1 <= 4:
                            pass
                        else:
                            print("Try again")
                    guss2 = str(input(" In which second type you want search?\n 0 ==> exit "))

                    '''                           select the  second search type                                     '''

                    if guss2 == 0 :
                        break
                    if len(guss2) == 0 or guss2.isalpha() == True :
                        print("Try again\nInsert number please!!!")
                    elif guss2.isdigit() == True:
                        guss2 = int(guss2)
                        if guss2 <= 4:
                            break
                        else:
                            print("Try again")
                except:
                    print("There is some problems, Try again pleas ")
            while True:
                if guss1 == 1:
                    gss = input("Insert the first prod properties: ")
                    if gss in pris:
                        for i in range(len(pris)):
                            if pris[i] == gss:
                                print(head)
                                print(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|"
                                      f"{orders[i]:^15}|\n")
                        break

                    else:
                        print("Not such as prod, Please Try to write again")
                elif guss1 == 2:
                    gss = input("Insert the first prod properties: ")
                    if gss in orders:
                        for i in range(len(orders)):
                            if orders[i] == gss:
                                print(head)
                                print(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|"
                                      f"{orders[i]:^15}|\n")
                        break

                    else:
                        print("Not such as prod, Please Try to write again")
                elif guss1 == 3:
                    gss = input("Insert the first prod properties: ")
                    if gss in quans:
                        for i in range(len(quans)):
                            if quans[i] == gss:
                                print(head)
                                print(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|"
                                      f"{orders[i]:^15}|\n")
                        break

                    else:
                        print("Not such as prod, Please Try to write again")
                elif guss1 == 4:
                    gss = input("Insert the first prod properties: ")
                    if gss in names:
                        for i in range(len(orders)):
                            if names[i] == gss:
                                print(head)
                                print(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|"
                                      f"{orders[i]:^15}|\n")
                        break

                    else:
                        print("Not such as prod, Please Try to write again")
                else:
                    break
            while True:
                if guss2 == 1:
                    gss = input("Insert the second  prod properties: ")
                    if gss in pris:
                        for i in range(len(pris)):
                            if pris[i] == gss:
                                print(head)
                                print(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|"
                                      f"{orders[i]:^15}|\n")
                        break

                    else:
                        print("Not such as prod, Please Try to write again")
                elif guss2 == 2:
                    gss = input("Insert the second  prod properties: ")
                    if gss in orders:
                        for i in range(len(orders)):
                            if orders[i] == gss:
                                print(head)
                                print(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|"
                                      f"{orders[i]:^15}|\n")
                        break
                    else:
                        print("Not such as prod, Please Try to write again")
                elif guss2 == 3:
                    gss = input("Insert the second  prod properties: ")
                    if gss in quans:
                        for i in range(len(quans)):
                            if quans[i] == gss:
                                print(head)
                                print(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|"
                                      f"{orders[i]:^15}|\n")
                        break
                    else:
                        print("Not such as prod, Please Try to write again")
                elif guss2 == 4:
                    gss = input("Insert the second  prod properties: ")
                    if gss in names:
                        for i in range(len(orders)):
                            if names[i] == gss:
                                print(head)
                                print(f"\n|{names[i]:^59}|{quans[i]:^25}|{pris[i]:^24}|"
                                      f"{orders[i]:^15}|\n")
                        break
                    else:
                        print("Not such as prod, Please Try to write again")
                else:
                    break
    return " "


'''                                                 Menu                                                             '''
file_name = "test"

while True:
    if file_name == "test":
        ques = input("Do you want to create a file? \n/// press(n) to skip or any key to continue: ")
        if ques.lower() == "n":
            pass
        else:
            file_name = creat_file(file_name)
            print(f"current file is {file_name}.txt")
    print()
    try:
        print(
            f"|{'-' * 27}|\n| 1 ===> Create new file    |\n| 2 ===> Add elements       |\n| 3 ===> Show database      |"
            f"\n| 4 ===> Remove elements    |\n| 5 ===> Search by one      |\n| 6 ===> search by tow      |"
            f"\n| 7 ===> exit               |\n|{'-' * 27}|")
        o = str(input("Insert which order you want: "))
        if o.isdigit():
            o = int(o)
            if o > 6 or o < 1:
                print("")
    except ValueError:
        print("Try again,\nInsert number between 1 - 6.")
    if o == 1:
        file_name = creat_file(file_name)
    if o == 3:
        if os.path.exists(file_name):
            print(f"Data base in {file_name}".center(30, "="))
            data_b(file_name)
        else:
            sk = input(f"there isn't file installed on  your computer so we need to create..(y/n)")
            if sk.lower() == "y":
                file_name = creat_file(file_name)
                data_b(file_name)
            else:
                pass
    elif o == 2:
        if os.path.exists(file_name):
            pris, orders, quans, names = add_prod(file_name)
        else:
            sk = input(f"there isn't {file_name} installed on  your computer so we need to create..(y/n)")
            if sk.lower() == "y":
                file_name = creat_file(file_name)
                pris, orders, quans, names = add_prod(file_name)
            else:
                pass
    elif o == 4:
        if os.path.exists(file_name):
            with open(file_name, "r") as ft:
                leng = 0
                for line in ft:
                    leng += 1
                if leng >= 4:
                    file_name = remove(file_name)
                else:
                    print("this file is empty")
        else:
            sk = input(f"there isn't {file_name} installed on  your computer so we need to create..(y/n)")
            if sk.lower() == "y":
                file_name = creat_file(file_name)
                file_name = remove(file_name)
            else:
                pass

    elif o == 5:
        if os.path.exists(file_name):
            with open(file_name, "r") as fre:
                lenh = 0
                for line in fre:
                    lenh += 1
                if lenh >= 4 :
                    find(file_name)
                else:
                    print("This file is empty")
        else:
            sk = input(f"there isn't {file_name} installed on  your computer so we need to create..(y/n)")
            if sk.lower() == "y":
                file_name = creat_file(file_name)
                find(file_name)
            else:
                pass
    elif o == 6:
        if os.path.exists(file_name):
            with open(file_name, "r") as fre:
                lenh = 0
                for line in fre:
                    lenh += 1
                if lenh >= 4:
                    find_plus(file_name)
                else:
                    print("This file is empty")
        else:
            sk = input(f"there isn't {file_name} installed on  your computer so we need to create..(y/n)")
            if sk.lower() == "y":
                file_name = creat_file(file_name)
                find_plus(file_name)
            else:
                pass
    elif o == 7:
        break
    else:
        print("Try again,\nInsert number between 1 - 6.")