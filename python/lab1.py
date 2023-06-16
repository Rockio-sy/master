# TAREK CHAWICH
# ИУ7И-21Б
# Перевод вещественного числа из 10-й системы счисления в 7-ю и обратно.

from tkinter import *
from tkinter import ttk
from tkinter import messagebox


def main():
    window = Tk()
    window.geometry("390x375")
    style = ttk.Style(window)
    # is used in tkinter to customize the look and feel of widgets such as buttons,labels and frames.
    # It can be used to set colors, font styles, and other visual elements.
    style.configure('Die.TButton', background="gray44")  # Style_name and dictionary # Die.TButton means clickable
    style.configure('TButton', background="gray", )
    # TButton is used to create a button that can be clicked by the user.
    style.configure('e.TButton', background="brown")
    # e.TButton is a variant of TButton and is used to create a more aesthetically pleasing button widget.
    window.resizable(False, False)
    window.title("7th base calculator BY ROCKIO")

    def get_text(x):
        if entry_box.get() == '0':
            entry_box.delete(0, 'end')
            # It deletes the text in the entry widget, from the beginning (index 0) to the end ('end')
            entry_box.insert(0, str(x))
            # It inserts text into the text widget, from the beginning (index 0) to the end ('end').
        else:
            length=len(entry_box.get())
            entry_box.insert(length, str(x))
            # It inserts text into the text widget, from the given index to the end.
    numbers = '0123456789'
    sign = '+-'

    def isit_num(num):
        dot = 0
        for i in range(len(num)):
            digit = num[i]
            if digit not in numbers:
                if digit in sign and i == 0:
                    continue
                elif digit == '.' and dot == 0:
                    dot = 1
                else:
                    return False
            else:
                continue
        return True

    def clear_history():
        result_list.clear()
        status_bar.configure(text="History: " + "|".join(result_list))
    
    def enter_operator(x):
        length=len(entry_box.get())
        entry_box.insert(length, btn_operators[x]["text"])
    
    def fun_clear():
        entry_box.delete(0, 'end')
    
    def about():
        messagebox.showinfo("About", "7th Base Calculator by Tarek Chawich\n")
        # showinfo(title, message to be displayed)

    def help():
        messagebox.showinfo("Help", "1.  To do the mathematical operation just type and do it."
                                    " \n2. for to change from base 10 to base 7 click to change the number.\
            \n3. To change from 7 to 10 just add the number and click the button or use the menu"
                                    " option for doing operations.\n")

    def for_fun():
        messagebox.showinfo("Click", "Hahh, Nothing here it was a trick..")
        
    def delete_fun():
        length = len(entry_box.get())
        entry_box.delete(length - 1, 'end')
        if length == 1:
            entry_box.insert(0, "0")
    
    result_list = []


    """def decimal_to_seventh():
        A = entry_box.get()
        if not isit_num(A):
            messagebox.showerror("Error", "Input is not a number: ")
            entry_box.delete(0, END)
        else:
            if A[0] == '-':
                sign = -1
                A = A[1:]
            else:
                sign = 1
            result = 0
            chars = str(float(A)).split('.')
            # Split the number at the decimal point and store the left and right side as a list
            m = isit_num(chars[0])
            result = ''
            while m >= 7:
                result += str(m % 7)
                m //= 7
            result += str(m)
            result = result[::-1]
            div = ''
            n = float('0.' + chars[1])
            count = 0
            while count < 15:
                count += 1
                n *= 7
                div += str(int(n // 1))
                n %= 1
                if n == 0.0:
                    break
            final = float(str(result + '.' + div) * sign)
            entry_box.delete(0, "end")
            entry_box.insert(0, final)
            result_list.append(A)
        status_bar.configure(text="History: " + "|".join(result_list))"""

    def decimal_to_seventh():
        if "." in entry_box.get():
            decimal_number = float(entry_box.get())
        else:
            decimal_number = (int(entry_box.get()))
        """
        Convert a decimal number to the seventh system.

        Args:
            decimal_number (int): Decimal number to be converted.

        Returns:
            str: The converted number in the seventh system.
        """
        if decimal_number == "0":
            ntry_box.delete(0, "end")
            entry_box.insert(0, "0")
        elif decimal_number == float(decimal_number):
            def float_to_seventh():
                float_number = decimal_number
                """Converts float number to seventh (base-7) system"""
                integer_part = int(float_number)
                fractional_part = abs(float_number - integer_part)
                integer_part_seventh = decimal_to_seventh(integer_part)

                if fractional_part == 0:
                    entry_box.delete(0, "end")
                    entry_box.insert(0, str(integer_part_seventh))

                fractional_part_seventh = ""
                precision = 8  # Number of decimal places to consider

                while fractional_part > 0 and precision > 0:
                    product = fractional_part * 7
                    whole_part = int(product)
                    fractional_part = product - whole_part
                    fractional_part_seventh += str(whole_part)
                    precision -= 1

                entry_box.delete(0, "end")
                entry_box.insert(str(f"{integer_part_seventh}.{fractional_part_seventh}"))
        decimal_number = int(decimal_number)
        seventh_digits = []
        while decimal_number > 0:
            decimal_number, remainder = divmod(decimal_number, 7)
            seventh_digits.append(str(remainder))

        entry_box.delete(0, "end")
        entry_box.insert(0, str(''.join(seventh_digits[::-1])))

    def seventh_to_decimal():
        A=entry_box.get()
        if not isit_num(A):
            messagebox.showerror("Error", "Input is not a number.")
            entry_box.delete(0, END)
        elif ('7' in A) or('8' in A) or ('9' in A):
            messagebox.showerror("Error", "Septenary can only have 0, 1, 2, 3, 4, 5, 6")
            entry_box.delete(0, END)
        else:
            if A[0] == '-':
                sign = -1
                A=A[1:]
            else:
                sign = 1
            result = 0
            chars=  str(float(A)).split(".")
            # Split the number at the decimal point and store the left and right side as a list
            # Convert the left and right sides of the decimal point from strings to integers
            chars[0], chars[1]=list(map(int , chars[0])), list(map(int, chars[1]))
            m=-1
            for i in range(len(chars[0]) - 1, -1, -1):
                m += 1
                result += chars[0][i] * (7**m)
            m=0
            for i in range(len(chars[1])):
                m -= 1
                result += chars[1][i] * (7**m)
            result *= sign
            entry_box.delete(0, END)
            entry_box.insert(END, result)
            result_list.append(A)
        status_bar.configure(text="History: " + "|".join(result_list))

    result=0
    def equal():
        content=entry_box.get()
        result=eval(content)
        entry_box.delete(0, "end")
        entry_box.insert(0, str(result))
        result_list.append(content)

        status_bar.configure(text="History: " + "|".join(result_list))
    
    def exit_():
        if(messagebox.askquestion("Exit", "Are you sure?")) == "yes":
            window.destroy()
    

    menu_bar = Menu(window)
    file_menu = Menu(menu_bar, tearoff=0)
    # The 'label' parameter is used to specify the text that is displayed in the menu, and the 'command'
    # parameter is used to specify the function that is executed when the command is clicked.
    file_menu.add_command(label="Seventh Base", command=decimal_to_seventh)
    file_menu.add_command(label="Decimal", command=seventh_to_decimal)
    file_menu.add_command(label="Clear", command=fun_clear)
    menu_bar.add_cascade(label="Option", menu=file_menu)
    file_menu.add_separator()
    file_menu.add_command(label="Exit", command=exit_)

    help_menu=Menu(menu_bar, tearoff=0)
    help_menu.add_command(label="Help", command=help)
    help_menu.add_command(label="About...", command=about)
    menu_bar.add_cascade(label="License", menu=help_menu)

    # Entry box (verdana is font, 12 is the size)
    entry_box=ttk.Entry(font="verdana 12 bold", width=25, justify=LEFT) # creates widget # LEFT is the position here

    entry_box.place(x=20, y=10, width=350, height=36)
    
    s = ttk.Style()
    # This loop is used to create a list of buttons containing numbers from 0 to 9. It iterates 10 times, and each
    #  iteration creates a new button with the text set to the value of 'i', and the command set to a function that 
    # will be executed when the button is clicked. The style of the button is set to 'Die.TButton'.
    btn_numbers = []
    for i in range(10):
        for i in range(10):
            btn_numbers.append(ttk.Button(text=str(i), command=lambda x=i: get_text(x), style='Die.TButton'))

    btn_operators = []
    for i in range(4):
        btn_operators.append(ttk.Button(command=lambda x=i: enter_operator(x), style='TButton'))
    # In the given example, ["text"] is an attribute of the ttk.Button object that sets the text displayed by the button.
    btn_operators[0]["text"] = "+"
    btn_operators[1]["text"] = "-"
    btn_operators[2]["text"] = "*"
    btn_operators[3]["text"] = "/"
    print(btn_operators)

    btn_text=1
    for i in range(3):
        for j in range(3):
            btn_numbers[btn_text].place(x=25 + j * 90,y=70 + i * 50)
            btn_text += 1
    for i in range(4):
        btn_operators[i].place(x=290,y=70 + i * 50)
    

    bt_zero = ttk.Button(text="0", command=lambda x=0: get_text(x), style='Die.TButton')
    btn_clear=ttk.Button(text="C", command=fun_clear)
    btn_clear.place(x=25,y=260)
    bt_zero.place(x=25, y=70 + 3 * 50, width=230)
    btn_dot=ttk.Button(text=".", command=lambda x=".": get_text(x))
    btn_dot.place(x=110, y=260) 
    btn_equal=ttk.Button(text="=", command=equal)
    btn_equal.place(x=200, y=260)
    btn_del=ttk.Button(text="del", command=delete_fun)
    btn_del.place(x=290, y=260)
    btn_seventh=ttk.Button(text="Seventh Base", command=decimal_to_seventh, style='e.TButton')
    btn_seventh.place(x=23, y=300, width=130, height=50)
    btn_clear_his=ttk.Button(text="Clear hist", command=clear_history, style='e.TButton')
    btn_clear_his.place(x=155, y=312)
    btn_decimal=ttk.Button(text="Decimal", command=seventh_to_decimal, style='e.TButton')
    btn_decimal.place(x=240, y=300, width=130, height=50)
    #In tkinter, the relief SUNKEN refers to a sunken relief effect on a widget, which is a visual effect that makes the
    #  widget appear to be pushed into the window. This effect is often used for buttons and other widgets to create a 
    # more visually appealing look.
    status_bar=ttk.Label(window, text="History: ", relief=SUNKEN)
    #This line of code is used to create a status bar in a tkinter window. The "side" argument specifies the side of the
    #  window that the status bar should be placed (in this case, the bottom). The "fill" argument specifies how the status bar
    #  should be sized (in this case, it will stretch to fill the full width of the window).
    status_bar.pack(side=BOTTOM, fill=X)

    window.config(menu=menu_bar)
    window.mainloop()
main()

