# Tarek Chawich IU7-21-B
# Find the root for a function with graphics..
import numpy as np
from tkinter import *
from matplotlib import pyplot as plt
from tkinter import ttk
from scipy.optimize import bisect
from math import *


def f(x):
    return eval(enter_f.get())


def f1(x):
    return eval(enter_f1.get())


def f2(x):
    return eval(enter_f2.get())


def table(value):
    newWindow = Toplevel(window)
    ac = ["Numbers", "x1", "x2", "x", "y", "Time", "Error", "Reason"]
    data_list = ["№ Roots", "[xi", "xi+1]", "x'", "f(x')", "Quantity iterations", "faults", "Reasons"]
    tv = ttk.Treeview(newWindow, columns=ac, show='headings',
                      height=7, padding=(10, 5, 20, 30))
    for i in range(len(data_list)):
        tv.column(ac[i], width=70, anchor='e')
        tv.heading(ac[i], text=data_list[i])
    tv.pack()
    for i in range(len(value)):
        tv.insert('', 'end', values=value[i])


def combined(eps, a, b, N_max):
    a1, b1 = a, b
    n = 1
    error, value = errors(3)
    while abs(a - b) > (2 * eps):
        if f(a) * f2(a) < 0:
            a = a - f(a) * ((a - b) / (f(a) - f(b)))
        elif f(a) * f2(a) > 0:
            a = a - (f(a) / f1(a))
        if f(b) * f2(b) < 0:
            b = b - f(b) * (b - a) / f(b) - f(a)
        elif f(b) * f2(b) > 0:
            b = b - (f(b) / f1(b))
        n += 1
        if n <= N_max:
            error, value = errors(0)
        else:
            error, value = errors(1)
    x = (a + b) / 2
    if x > b1 or x < a1:
        error, value = errors(3)
        return x, 0, error, value
    # print(a, b, x)
    return x, n, error, value


def errors(number_error):
    if number_error == 0:
        return number_error, "Success" # Успех
    if number_error == 1:
        return number_error, "Exceeded" # Превышен
    if number_error == 2:
        return number_error, "Consumption" # Расход
    if number_error == 3:
        return number_error, "Another" # Другие


def get_matplotlib():
    try:
        a = float(enter_a.get())
        b = float(enter_b.get())
        eps = float(enter_eps.get())
        h = int(enter_h.get())
        N_max = int(enter_N_max.get())
        # f = eval(enter_f.get())
        # f1 = eval(enter_f1.get())
        # f2 = eval(enter_f2.get())
    except:
        window_error = Toplevel(window)
        window_error.geometry("200x50")
        window_error.title("Error")
        error_label = Label(window_error, text="Invalid input data")
        error_label.pack()
    else:
        n = 1
        x_i = a
        x_i2 = x_i + h
        x3 = np.linspace(a, b, 3000)
        y = []
        for i in range(len(x3)):
            y.append(f(x3[i]))
        fig, ax = plt.subplots()
        plt.title('graphics function  y = f(x)')
        plt.xlabel('x', fontsize=12)
        plt.ylabel('y', fontsize=12)
        ax.plot(x3, y)
        ax.set_xlim(a, b)
        data_list = []
        x1 = a - 1
        while x_i < x_i2 <= b:
            if abs(x_i) < 1.02696e-10:
                x_i = 0
            if abs(x_i2) < 1.02696e-10:
                x_i2 = 0
            if f(x_i) * f(x_i2) <= 0:
                x_t, rootRes = bisect(f, x_i, x_i2, rtol=eps, maxiter=N_max, full_output=True)
                plt.plot(x_t, f(x_t), marker="X", color="red")
                x, t, error, val = combined(eps, x_i, x_i2, N_max)
                if error != 0:
                    data_list.append([n, round(x_i, 6), round(x_i2, 6), "-", "-", "-", error, val])
                    # data_list.append([n, round(x_i, 6), round(x_i2, 6), round(x, 6), round(f(x)), t, error, val])
                else:
                    if abs(x1 - x) > 0.001:
                        # data_list.append([n, round(x_i, 6), round(x_i2, 6), "-", "-", "-", error, val])
                        data_list.append([n, round(x_i, 6), round(x_i2, 6), round(x, 6), round(f(x), 6), t, error, val])
                x1 = x
            # else:
            #     error, value = errors(2)
            #     point = "-"
            #     data_list.append([n, round(x_i, 6), round(x_i2, 6), point, point, point, error, value])
            if f1(x_i) * f1(x_i2) <= 0:
                x_t, rootRes = bisect(f1, x_i, x_i2, rtol=eps, maxiter=N_max, full_output=True)
                plt.plot(x_t, f(x_t), marker="+", color="green")
            if f2(x_i) * f2(x_i2) <= 0:
                x_t, rootRes = bisect(f2, x_i, x_i2, rtol=eps, maxiter=N_max, full_output=True)
                plt.plot(x_t, f(x_t), marker="*", color="blue")
            if x_i2 < b < x_i2 + h:
                x_i = x_i2
                x_i2 = x_i2 + abs(b - x_i2)
            else:
                x_i = x_i2
                x_i2 = x_i2 + h
            n += 1
        table(data_list)
        plt.legend(("Functions", "Roots", "extremum", "inflection points"))
        plt.show()


window = Tk()
window.title("Roots finder")
text_a = Label(window, text="a: ")
enter_a = Entry(window)
text_b = Label(window, text="b: ")
enter_b = Entry(window)
text_eps = Label(window, text="eps: ")
enter_eps = Entry(window)
text_h = Label(window, text="h: ")
enter_h = Entry(window)
text_N_max = Label(window, text="N_max: ")
enter_N_max = Entry(window)
enter_f = Entry(window)
enter_f1 = Entry(window)
enter_f2 = Entry(window)
text_a.grid(column=0, row=0)
enter_a.grid(columnspan=2, column=1, row=0)
text_eps.grid(column=4, row=0)
enter_eps.grid(column=5, row=0, columnspan=2)
text_b.grid(column=0, row=1)
enter_b.grid(columnspan=2, column=1, row=1)
text_h.grid(column=4, row=1)
enter_h.grid(column=5, columnspan=2, row=1)
text_N_max.grid(column=0, row=2)
enter_N_max.grid(column=1, columnspan=2, row=2)
enter_f.grid(column=0, row=3)
enter_f1.grid(column=1, row=3)
enter_f2.grid(column=2, row=3)
button_point = Button(window, text="get_matplotlib", command=get_matplotlib)
button_point.grid(column=4, row=2)
window.mainloop()

