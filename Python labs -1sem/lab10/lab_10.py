# TAREK CHAWICH
# ИУ7И-16Б
# лаб-10(интеграл)
import math as m
eps_ = 10e-8
# Function
def f(x):
    y = x ** 2
    return y
# Primitive function ("Первообразная функция ")
def F(x):
    y = x ** 3 / 3
    return y

def method_trapezoid(n, f):
    start = a
    end = b
    h = (end - start) / n
    s = 0       #f(start) + f(end)
    x = a
    for i in range(n):
        s += (f(x) + f(x + h)) / 2 * h 
        x += h
    return s
def method_parabola(n, f):
    if n % 2 == 0:
        start = a
        stop = b
        h = (stop - start) / n
        s = f(start) + f(stop)
        for i in range(1, n):
            s += (3 - (- 1) ** i) * f(start + i * h)
        s *= h / 3
        return s
    else:
        return m.nan
try:
    a = float(input("Please enter the initial point: "))
    b = float(input("Please enter the ending point: "))
    n1 = int(input("Please enter the number of split segments in the first case: "))
    n2 = int(input("Please enter the number of split segments in the second case: "))
    eps = float(input("Please enter the accuracy: "))
    if n1 <= 0 or n2 <= 0 :    
        print("Invalid input")
    else:
        I = F(b) - F(a)
        count = 1
        print("_" * 46)
        print('|' + ' ' * 14 + '|' + ' ' * 6 + 'N1' + ' ' * 6 + '|' + ' ' * 6
            + 'N2' + ' ' * 6 + '|')
        print('_' * 46)
        print(f"|   Method 1    {method_trapezoid(n1, f):^14.6g}|{method_trapezoid(n2, f):^14.6g}|")
        print("_" * 46)
        print(f"|   Method 2    {method_parabola(n1, f):^14.6g}|{method_parabola(n2, f):^14.6g}|")
        print("_" * 46)
        print(f"Absolute error of the first method of splitting by n1 {abs(method_trapezoid(n1, f) - I):^12.6g}")
        print(f"Relative error of the first method of splitting by n1 {abs(method_trapezoid(n1,f) - I) / abs(I):^12.6g}")
        if n1 % 2 == 0:
            print(f"Absulute error of the second method of splitting by n1 {abs(method_parabola(n1, f) - I):^12.6g}")
            print(f"Relative error of the second method of splitting by n1 {abs(method_parabola(n1, f) - I) / abs(I):^12.6g}")
        else:
            print("It is impossible to calculate errors using parabola method for n2")
        print(f"Absolute error of the first method of splitting by n2 {abs(method_trapezoid(n2, f) - I):^12.6g}")
        print(f"Relative error of the first method of splitting by n2 {abs(method_trapezoid(n2, f) - I) / abs(I):^12.6g}")
        if n2 % 2 == 0:
            print(f"Absulute error of the second method of splitting by by n2 {abs(method_parabola(n2, f) - I):^12.6g}")
            print(f"Relative error of the second method of splitting by n2 {abs(method_parabola(n2, f) - I) / abs(I):^12.6g}")
        else:
            print("It is impossible to calculate errors using parabola method for n2")
        if n1 % 2 == 0:
            if abs(I - method_parabola(n1, f)) > abs(I - method_trapezoid(n1, f)):
                while abs(method_parabola(count, f) - method_parabola(count * 2, f)) > eps:
                    count += 1
                print(f"Method trapezoid is the effective.\n{count} partitioning"
                    f" segments are needed to calculate the integral by the parabola method by accuracy {eps:.6g}")
            else:
                while abs(method_trapezoid(count, f) - method_trapezoid(count * 2, f)) > eps:
                    count += 1
                print(f"Method parabola is the most effective.\n{count} partitioning"
                    f" segments are needed to calculate the integral by the parabola method by accuracy {eps:.6g}")
        elif n2 % 2 == 0:
            if abs(I - method_parabola(n2, f)) > abs(I - method_trapezoid(n2, f)):
                while abs(method_parabola(count, f) - method_parabola(count * 2, f)) > eps:
                    count *= 2
                print(f"Method trapezoid is the most effective.\n{count} partitioning"
                    f" segments are needed to calculate the integral by the parabola method by the accuracy {eps:.6g}")
            else:
                while abs(method_trapezoid(count, f) - method_trapezoid(count * 2, f)) > eps:
                    count *= 2
                print(f"Method parabola is the most effective.\n {count} partitioning"
                    f" segments are needed to calculate the integral by the trapezoid method by the accuracy of {eps:.6g}")
        else:
            while abs(method_trapezoid(count, f) - method_trapezoid(count * 2, f)) > eps:
                count *= 2
            print(f"It is impossible to use the parabola method.\n{count} partioning "
                f" segments are needed to caculate the integral by the trapezoid method by the accuracy of {eps:.6g}")
except ValueError as e:
    print("Input must be numbers")
except Exception as e:
    print("Some unknown error occured. Check the input data")