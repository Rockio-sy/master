#Tarek chawich
#Защита 4
#x ** 2 -25
x0 = float(input("Insert the first value: "))
h = float(input("Insert  the step: "))
xn = float(input("Insert the final value: "))

x = x0
y=0
for i in range(1):
    y = x ** 2 - 25
    first_value = y
y_max = y_min = y
x = x0
while x < xn:
    y = x**2 - 25
    if y_max < y:
        y_max = y

    if y_min > y:
        y_min = y

    x += h

else:
    x = xn
    y = x ** 2 - 25
    if y_max < y:
        y_max = y
    if y_min > y:
        y_min = y

eps = 1e-2
x = x0
x1 = x0
if y_min > eps:
    while x < xn:
        y = x**2 - 25
        print(f"{x:>7.1f} ", end="")
        x += h
        x1 += h
        flag = flag1 = True
        for i in range(79):
            if flag and i * (y_max - y_min) / 78 >= y - y_min:
                print("*", end="")
                flag = False
                if flag1 and i * (y_max - y_min) / 78 >= abs(y_min):
                    flag1 = False
            elif flag1 and i * (y_max - y_min) / 78 >= abs(y_min):
                print(" ", end="")
                flag1 = False
            elif not flag1 and not flag:
                break
            else:
                print(" ", end="")
        print(" ")
    else:
        x = xn
        y = x ** 2 - 25
        print(f"{x:>7.1f}", end="")

        flag = flag1 = True
        for i in range(79):
            if flag and i * (y_max - y_min) / 78 >= y - y_min:
                print("*", end="")
                flag = False
                if flag1 and i * (y_max - y_min) / 78 >= abs(y_min):
                    flag1 = False
            elif flag1 and i * (y_max - y_min) / 78 >= abs(y_min):
                print(" ", end="")
                flag1 = False
            elif not flag1 and not flag:
                break
            else:
                print(" ", end="")
        print(" ")


else:
    while x < xn:
        y = x ** 2 - 25
        print(f"{x:>7.1f} ", end="")
        x += h
        x1 += h
        # else:
        #  print(f"{an:>7.1f}")

        flag = flag1 = True
        for i in range(79):
            if flag and i * (y_max - y_min) / 78 >= y - y_min:
                print("*", end="")
                flag = False
                if flag1 and i * (y_max - y_min) / 78 >= abs(y_min):
                    flag1 = False
            elif flag1 and i * (y_max - y_min) / 78 >= abs(y_min):
                print("|", end="")
                flag1 = False
            elif not flag1 and not flag:
                break
            else:
                print(" ", end="")
        print(" ")

    else:
        x = xn
        y = x ** 2 - 25

        print(f"{x:>7.1f}", end="")

        flag = flag1 = True
        for i in range(80):
            if flag and i * (y_max - y_min) / 80 >= y - y_min:
                print("*", end="")
                flag = False
                if flag1 and i * (y_max - y_min) / 80 >= abs(y_min):
                    flag1 = False
            elif flag1 and i * (y_max - y_min) / 80 >= abs(y_min):
                print("|", end="")
                flag1 = False
            elif not flag1 and not flag:
                break
            else:
                print(" ", end="")
        print(" ")
