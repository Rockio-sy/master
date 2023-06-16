
'''
Разработать приложение с графическим интерфейсом для решения поставленной задачи.
Приложение позволяет пользователю задавать параметры фигур как с помощью клавиатуры,
вводя цифровые значения, так и задавая мышкой характеристики фигуры на поле графического
экрана. (Только для групп ИУ7-24, 25. Остальным только ввод с клавиатуры).
Также необходимо сделать графическую интерпретацию* полученного решения.

Заданы два множества точек. Найти такой треугольник с вершинами – точками
первого множества, внутри которого находится одинаковое количество точек из
первого и из второго множеств.
Дать графическое изображение результатов.
'''
from tkinter import *
import tkinter.messagebox as ms
from math import *

global arr_1
global arr_2
arr_1 = []
arr_2 = []


def block_1():
    if arr_1 != [] and len(arr_1) >= 3 and input_mx1["state"] == "normal":
        input_mx1.config(state="readonly")
        input_my1.config(state="readonly")
        btn_end_1["text"] = "Продолжить ввод множества"
    elif input_mx1["state"] == "readonly":
        input_mx1.config(state="normal")
        input_my1.config(state="normal")
        btn_end_1["text"] = "Закончить ввод множества"
    else:
        ms.showinfo(title="Info ввод множество красное", message="Нужно ввести хотя бы 3 координат точек!")


def block_2():
    if arr_2 != [] and len(arr_2) >= 3 and input_mx2["state"] == "normal":
        input_mx2.config(state="readonly")
        input_my2.config(state="readonly")
        btn_end_2["text"] = "Продолжить ввод множества"
    elif input_mx2["state"] == "readonly":
        input_mx2.config(state="normal")
        input_my2.config(state="normal")
        btn_end_2["text"] = "Закончить ввод множества"
    else:
        ms.showinfo(title="Info ввод множество синее", message="Нужно ввести хотя бы 3 координат точек!")


def find_triangles():
    if (arr_1 == [] or arr_2 == []):
        ms.showinfo(title="Info ввод множеств", message="Множетсва не введены!")

    print(arr_1)
    print(arr_2)
    flag = 0
    i = 0
    j = 1
    k = 2
    n = len(arr_1) - 1
    while ((i < n or j < n or k < n) and (i < j < k)):
        x1, y1 = arr_1[i][0], arr_1[i][1]
        x2, y2 = arr_1[j][0], arr_1[j][1]
        x3, y3 = arr_1[k][0], arr_1[k][1]

        ac = sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
        ab = sqrt((x2 - x3) ** 2 + (y2 - y3) ** 2)
        bc = sqrt((x3 - x1) ** 2 + (y3 - y1) ** 2)
        if (ac + ab > bc and ac + bc > ab and bc + ab > ac):
            print("Это треугольник с вершинами A(", x1, ";", y1, ") B(", x2, ";", y2, ") C(", x3, ";", y3, ")")
            count_m1 = 0
            count_m2 = 0
            i = 0
            while (i < len(arr_2)):
                x0, y0 = arr_2[i][0], arr_2[i][1]
                a = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0)
                b = (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0)
                c = (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0)
                if (a > 0 and b > 0 and c > 0) or (a < 0 and b < 0 and c < 0):
                    count_m2 += 1
                i += 1
            i = 0
            while (i < len(arr_1)):
                x0, y0 = arr_1[i][0], arr_1[i][1]
                a = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0)
                b = (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0)
                c = (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0)
                if (a > 0 and b > 0 and c > 0) or (a < 0 and b < 0 and c < 0):
                    count_m1 += 1
                i += 1
            if (count_m1 == count_m2):
                if (count_m1 == 0 and count_m2 == 0):
                    canvas.create_line(x1, y1, x2, y2, fill="black", width=2);
                    canvas.create_line(x2, y2, x3, y3, fill="black", width=2);
                    canvas.create_line(x3, y3, x1, y1, fill="black", width=2);
                    ms.showinfo(title="NONE", message="В треугольнике нет точек из двух множеств.")
                    print("В треугольнике нет точек из двух множеств.");
                else:
                    flag = 1
                    canvas.create_line(x1, y1, x2, y2, fill="green", width=2);
                    canvas.create_line(x2, y2, x3, y3, fill="green", width=2);
                    canvas.create_line(x3, y3, x1, y1, fill="green", width=2);
                    print("В треугольнике находится одинаковое количесвто точек из двух точек.")

            else:
                flag = 2
                canvas.create_line(x1, y1, x2, y2, fill="yellow", width=2);
                canvas.create_line(x2, y2, x3, y3, fill="yellow", width=2);
                canvas.create_line(x3, y3, x1, y1, fill="yellow", width=2);
                ms.showinfo(title="NONE", message="В треугольнике находится разное количесвто точек из двух точек.")
                print("В треугольнике находится разное количесвто точек из двух точек.")

        else:
            ms.showinfo(title="Результат негативенный",
                        message="Из точек первого множетсва не получилось образовать треугольник!")
            print("Из точек первого множетсва не получилось образовать треугольник!")

        if k < n:
            k += 1
        elif j < n:
            j += 1
        elif i < n:
            i += 1


def paint(event):
    x, y = (event.x), (event.y)
    if input_mx1['state'] != 'readonly':
        canvas.create_line(x, y, x + 1, y, fill='red', width=4)
        canvas.create_line(x, y + 1, x, y, fill='red', width=4)
        arr_1.append([x, y])
    elif input_mx2['state'] != 'readonly':
        canvas.create_line(x, y, x + 1, y, fill='blue', width=4)
        canvas.create_line(x, y + 1, x, y, fill='blue', width=4)
        arr_2.append([x, y])


def m_1():
    try:
        x = int(input_mx1.get())
        y = int(input_my1.get())
        if ((5 <= x <= 800) and (5 <= y <= 600)):
            if [x, y] not in arr_1:
                canvas.create_line(x, y, x + 1, y, fill='red', width=4)
                canvas.create_line(x, y + 1, x, y, fill='red', width=4)
                arr_1.append([x, y])
        else:
            ms.showwarning(title="Warning", message="Координты точки введены неверно! Выше или ниже предела!")
    except:
        ms.showwarning(title="Warning", message="Координты точки некорректны в первом множестве")


def m_2():
    try:
        x = int(input_mx2.get())
        y = int(input_my2.get())
        if ((5 <= x <= 800) and (5 <= y <= 600)):
            if [x, y] not in arr_2:
                canvas.create_line(x, y, x + 1, y, fill='blue', width=4)
                canvas.create_line(x, y + 1, x, y, fill='blue', width=4)
                arr_2.append([x, y])
        else:
            ms.showwarning(title="Warning", message="Координты точки введены неверно! Выше или ниже предела!")
    except:
        ms.showwarning(title="Warning", message="Координты точки некорректны во втором множестве")


def clear_canvas():
    canvas.delete("all")
    arr_1.clear()
    arr_2.clear()


window = Tk()
window.title("Решение планиметрических задач")

canvas = Canvas(window, width=800, height=600, bg='white')
lbl_m1 = Label(window, text="Ограничения ввода координат:\n\
 - от 5 до 800 по x\n\
 - от 5 до 600 по y\n\
 Ввести первое множество - КРАСНОЕ -:")
lbl_mx1 = Label(window, text="x =")
lbl_my1 = Label(window, text="y =")
btn_put_1 = Button(window, text="Отметить точку", command=m_1)
btn_end_1 = Button(window, text="Закончить ввод множества", command=block_1)

input_mx1 = Entry(window);
input_my1 = Entry(window);
input_mx2 = Entry(window);
input_my2 = Entry(window);

lbl_m2 = Label(window, text="Ввести второе множество - СИНИЕ -:")
lbl_mx2 = Label(window, text="x = ")
lbl_my2 = Label(window, text="y = ")
btn_put_2 = Button(window, text="Отметить точку", command=m_2)
btn_end_2 = Button(window, text="Закончить ввод множества", command=block_2)

lbl_task = Label(window, text="Задание -15-\n Заданы два множества точек.\n\
 Найти такой треугольник с вершинами – точкам первого множества,\n\
 внутри которого находится одинаковое количество точек из первого\n\
 и из второго множеств.\n\
Дать графическое изображение результатов.\n\
Черные треугольники - без точек из множества\n\
Желтый треугольник - с разным количеством точек из обоих множеств\n\
Зеденый треугольник - с одиннаковым количеством точек из обоих множеств")
btn_opr = Button(window, text="Найти треугольник", command=find_triangles)
btn_clear = Button(window, text="Очистить", command=clear_canvas)

canvas.grid(column=0, row=0, columnspan=4, rowspan=50)
canvas.bind("<Button-1>", paint)
lbl_m1.grid(column=5, row=0, columnspan=4)
lbl_mx1.grid(column=5, row=1)
input_mx1.grid(column=6, row=1)
lbl_my1.grid(column=7, row=1)
input_my1.grid(column=8, row=1)
btn_put_1.grid(column=5, row=2, columnspan=2)
btn_end_1.grid(column=7, row=2, columnspan=2)

lbl_m2.grid(column=5, row=3, columnspan=4)
lbl_mx2.grid(column=5, row=4)
input_mx2.grid(column=6, row=4)
lbl_my2.grid(column=7, row=4)
input_my2.grid(column=8, row=4)
btn_put_2.grid(column=5, row=5, columnspan=2)
btn_end_2.grid(column=7, row=5, columnspan=2)

lbl_task.grid(column=5, row=6, columnspan=4)
btn_opr.grid(column=6, row=7, columnspan=4)
btn_clear.grid(column=6, row=8, columnspan=4)
window.mainloop()