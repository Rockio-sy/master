from tkinter import Entry, Label, Button, Tk, messagebox, END
import ctypes

lib = ctypes.CDLL('./lib/lib_array_func.dll')

_fill_array = lib.fill_array_prime
_fill_array.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_fill_array.restype = None

_add_elem_after_even = lib.add_elem_after_even
_add_elem_after_even.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int,
    ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int)
_add_elem_after_even.restype = ctypes.c_int

def fill_array(size):

    array = (ctypes.c_int * size)()
    _fill_array(array, size)

    return list(array)

def add_elem_after_even(array, size, new_size, number):
    array = (ctypes.c_int * size)(*array)
    new_array = (ctypes.c_int * new_size)()

## 1 способ
    count = 0
    for i in range(0, size):
        if (array[i] % 2 == 0):
            count += 1
            
    if (count > 0):
         new_array = (ctypes.c_int * (count + new_size))(*new_array)
    _add_elem_after_even(array, size, new_array, count + new_size, number)    
## 2 способ
##    count = _add_elem_after_even(array, size, new_array, new_size, number)
    
##    if (count > new_size):
##        new_array = (ctypes.c_int * count)(*new_array)
##        _add_elem_after_even(array, size, new_array, count, number)
    
    return list(new_array)

def arr_of_prime_numb():

    try:
        number = int(entry_field_1.get())

    except:
        messagebox.showerror("Ошибка ввода", "Кол-во элементов массива - целое число!")
        return

    if (number < 1):
        messagebox.showerror("Ошибка ввода", "Кол-во элементов массива должно быть больше 0!")
        return

    array = fill_array(number)
    str_array = ' '.join(str(number) for number in array)

    output_field_1.delete(0, END)
    output_field_1.insert(0, str_array)

def insert_numb_into_arr():

    try:
        number = int(entry_field_3.get())

    except:
        messagebox.showerror("Ошибка ввода", "Ошибка при воде вставляемого в массив числа!")
        return

    str_array = entry_field_2.get()

    try:
        array = [int(i) for i in str_array.split()]

    except:
        messagebox.showerror("Ошибка ввода", "В введённом массиве присутствуют посторонние символы!")


    new_array = add_elem_after_even(array, len(array), len(array), number)

    str_array = ' '.join(str(number) for number in new_array)

    output_field_2.delete(0, END)
    output_field_2.insert(0, str_array)


window = Tk()
window['bg'] = 'light gray'
window.title('Lab_12_03_02')
window.geometry("460x430")

txt_input_1 = Label(window, text = 'Кол-во элементов массива:', bg = 'light gray',
    font = ('Courier New', 16))
txt_input_1.place(x = 20, y = 15, width = 350, height = 30)

entry_field_1 = Entry(window, width = 5, font = ('Courier New', 16))
entry_field_1.place(x = 350, y = 15, width = 70, height = 30)
entry_field_1.focus()    

btn_fill_array_1 = Button(window, text = 'Вывести массив из\n N простых чисел',
    font = ('Courier New', 16), activebackground = '#555555', command = arr_of_prime_numb)

btn_fill_array_1.place(x = 60, y = 60, width = 270, height = 45)

output_field_1 = Entry(window, width = 5, font = ('Courier New', 16))
output_field_1.place(x = 20, y = 120, width = 360, height = 30)

txt_input_2 = Label(window, text = 'Заполните массив', bg = 'light gray',
    font = ('Courier New', 16))
txt_input_2.place(x = 20, y = 170, width = 400, height = 30)

entry_field_2 = Entry(window, width = 35, font = ('Courier New', 16))
entry_field_2.place(x = 20, y = 205, width = 360, height = 30)

txt_input_3 = Label(window, text = 'Вставляемое в массив число:', bg = 'light gray',
    font = ('Courier New', 16))
txt_input_3.place(x = 20, y = 250, width = 360, height = 30)

entry_field_3 = Entry(window, width = 5, font = ('Courier New', 16))
entry_field_3.place(x = 370, y = 250, width = 70, height = 30)

btn_add_elem = Button(window, text = 'Добавить после каждого чётного\nэлемента указанное число',
    font = ('Courier New', 16), activebackground = '#555555', command = insert_numb_into_arr)

btn_add_elem.place(x = 20, y = 290, width = 400, height = 45)

txt_output = Label(window, text = 'Полученный массив:', bg = 'light gray',
    font = ('Courier New', 16))
txt_output.place(x = 20, y = 345, width = 360, height = 30)

output_field_2 = Entry(window, width = 5, font = ('Courier New', 16))
output_field_2.place(x = 20, y = 375, width = 360, height = 30)

window.mainloop()
