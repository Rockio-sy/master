# Tarek Chawich
# IU7 lab 14
import os
from struct import pack, unpack, calcsize
print(os.getcwd())
frml = '60s60sfi'
L = calcsize(frml)              # pacage

hat = '|----------------------------------------------------------------|----------------------------' \
      '----|------------|------|\n| name                                                           | category' \
      'y                       | price      | size |\n|-------------------------------------------------------' \
      '---------|--------------------------------|------------|------|'
bottom = '|----------------------------------------------------------------|--------------------------------|-' \
         '-----------|------|'

default_info_file = 'default_info_edit.txt'              # created table is filled with info taken from this table
file = 'db.txt'                                          # default file


def pacage(name, category, price, size):
    packed_row = pack(frml, name, category, price, size)
    return packed_row


"""                                               Creates a new one if not exists                                    """


def create(path):
    try:
        if '\\' in path:
            os.makedirs('\\'.join(path.split('\\')[:-1]), exist_ok=True)
        with open(path, 'ab'):
            print(f'\nChoosen file: {path}')
            return path
    except Exception:
        print("\nTry again.")
    return 'db.txt'


"""                                                     Initializes a DB                                             """


def down_data(path):
    with open(path, 'rb') as f:
        length = len(f.read(L).decode('windows-1251').rstrip('\x00'))
    if length < 4:
        try:
            with open(path, 'wb') as f:
                f.write(pack('5s', 'empty'.encode()))
            result = '\nDid not download.'
            #   Требуется ли заполнить таблциу несколькими сущностями? (Y(н) - да, <любая клавиша> - нет)
            fill = input("Do you need to populate a table with multiple entities? (Y(n) - yes, <any key> - no): ")
            if fill == 'Y' or fill == 'y' or fill == 'Н' or fill == 'н' or fill == '':
                with open(path, 'wb') as f:
                    with open(default_info_file, 'r') as default:
                        for line in default:
                            fields = line.split('%(')
                            f.write(pacage(fields[0].encode(), fields[1].encode(), float(fields[2]), int(fields[3])))
        except Exception as e:
            result = f"Error: {e}"
    else:
        result = '\nDid not download'
    return result


"""                                                     Prints the table                                             """


def show(path):
    empty = False
    with open(path, 'rb') as f:
        length = len(f.read(L).decode('windows-1251').rstrip('\x00'))
    if length < 4:
        print(f'Did not download')
    else:
        try:
            if 5 <= length < 10:
                empty = True
                with open(path, 'w') as file:
                    file.write('')
            print(f'Таблица ({path}):')
            print(hat)
            with open(path, 'rb') as f:
                n = 0
                while True:
                    f.seek(n)
                    line = f.read(L)
                    if len(line.decode('windows-1251').rstrip('\x00')) < 4:
                        break
                    name, category, price, size = unpack(frml, line)
                    name = name.decode('windows-1251').rstrip('\x00')
                    category = category.decode('windows-1251').rstrip('\x00')
                    print(f"| {name: <63}| {category: <31}| ${f'{float(price):.2f}': <10}|"
                    f" {size: <5}|")
                    n += L
            print(bottom)
            if empty:
                with open(path, 'wb') as file:
                    file.write(pack('5s', 'empty'.encode()))
        except Exception as e:
            print(f"Error: {e}")


"""                                                           Inserts a line                                         """


def insert(path):
    with open(path, 'rb') as f:
        length = len(f.read(L).decode('windows-1251').rstrip('\x00'))
    if length < 4:
        response = '\ndid not dowloded.'
    else:
        if 5 <= length < 10:
            with open(path, 'w') as file:
                file.write('')
        print('(Insert the information.)')
        while True:
            name = input('Insert  prod name: ').strip()
            if len(name) <= 63:
                break
            else:
                print('Try again.')
        while True:
            category = input('Insert  prod category: ').strip()
            if len(category) <= 31:
                break
            else:
                print('Try again.')
        while True:
            try:
                price = input('Insert  prod price : ').strip()
                if len(price) == 0:
                    break
                if '.' in price:
                    if len(price) <= 9:
                        price = float(price)
                        break
                    else:
                        print("Invalid value length")
                else:
                    if len(price) <= 6:
                        price = float(price)
                        break
                    else:
                        print("Invalid value length")

            except ValueError:
                print("Try again")

        while True:
            try:
                size = input('Insert  prod size: ').strip()
                if len(size) <= 4:
                    if size:
                        size = int(size)
                    else:
                        size = ''
                    break
                else:
                    print('it is cannot exist 4 symbols!!')
            except ValueError:
                print("Try again:")
        while True:
            try:
                k = input('which position?? ')
                if '.' not in k:
                    k = int(k)
                    if k >= 1:
                        break
                    else:
                        print(" Try again with INT ")
            except ValueError:
                print('Try again')
        to_end = False
        if name or category or size or price:
            try:
                packed_row = pack(frml, name.encode(), category.encode(), price, size)
                pos = 0
                counter = 0
                with open(path, 'rb') as file:
                    while True:
                        file.seek(pos)
                        line = file.read(L)
                        if len(line.decode('windows-1251').rstrip('\x00')) < 10:
                            break
                        pos += L
                        counter += 1
                if k > counter + 1:
                    k = counter + 1
                    to_end = True
                z = k
                with open(path, 'r+b') as file:
                    for i in range(counter, k-1, -1):
                        file.seek((i-1)*L)
                        move = file.read(L)
                        file.seek(i*L)
                        file.write(move)
                    file.seek((k-1)*L)
                    file.write(packed_row)
                if not to_end:
                    response = f'\nRecorded in  {z}th position.'
                else:
                    response = '\nThe entry has been added .'
            except Exception as e:
                response = f'\n Error: {e} '
        else:
            response = '\nEmpty.'
            with open(path, 'wb') as file:
                file.write(pack('5s', 'empty'.encode()))
    return response


"""                                     Removes the last row                                                         """


def remove(path, n):
    k = n
    pos = 0
    counter = 0
    empty = False
    with open(path, 'rb') as file:
        while True:
            file.seek(pos)
            line = file.read(L)
            if len(line.decode('windows-1251').rstrip('\x00')) < 10:
                break
            pos += L
            counter += 1
    if counter == 1 and n == 1:
        empty = True
    with open(path, 'r+b') as file:
        while True:
            file.seek(n * L)
            cover = file.read(L)
            file.seek((n - 1) * L)
            file.write(cover)
            if n >= counter - 1:
                file.seek(n*L)
                file.write(pack(f'{2*L}s', ' '.encode()))
                break
            n += 1
    if empty:
        with open(path, 'wb') as file:
            file.write(pack('5s', 'empty'.encode()))
    return f"{k}th one removed."


"""                                     Selects rows by category given                                               """


def find1(path, values):
    try:
        rows = []
        with open(path, 'rb') as f:
            n = 0
            while True:
                f.seek(n)
                row = f.read(L)
                if row.decode('windows-1251').rstrip('\x00') == '':
                    break
                name, category, price, size = unpack(frml, row)
                rows.append((name.decode('windows-1251').rstrip('\x00'), category.decode('windows-1251').rstrip('\x00'), price, size))
                n += L
            saved_rows = []
            count = 0
            for line in rows:
                if line[3] in values:
                    saved_rows.append(line)
                    count += 1
            print(f"\nChoosen file: {count}")
    except Exception as e:
        print(f"\nError: {e}")
        saved_rows = []
    return saved_rows


"""                         Returns the rows that follow the requirements                                            """


def find2(path, category_values, size_values):
    try:
        rows = []
        with open(path, 'rb') as f:
            n = 0
            while True:
                f.seek(n)
                row = f.read(L)
                if row.decode('windows-1251').rstrip('\x00') == '':
                    break
                name, category, price, size = unpack(frml, row)
                rows.append((name.decode('windows-1251').rstrip('\x00'), category.decode('windows-1251').rstrip('\x00'), price, size))
                n += L
            saved_rows = []
            count = 0
            for line in rows:
                for category in category_values:
                    if line[1] == category:
                        for size_value in size_values:
                            if line[3] == size_value:
                                saved_rows.append(line)
                                count += 1
                                break
            print(f'\nfounds: {count}')
    except Exception as e:
        print(f"Error: {e}")
        saved_rows = []
    return saved_rows


'''Menu'''
commands = {
    1: ('Выбрать файл для работы.', create),
    2: ('Инициализировать базу данных.', down_data),
    3: ('Вывести содержимое базы данных.', show),
    4: ('Добавить запись.', insert),
    5: ('Удалить запись по номеру.', remove),
    6: ('Поиск по размеру.', find1),
    7: ('Поиск по категории и размеру.', find2),
    8: ('Завершить работу.', None)
}


'''Main part'''
while True:
    print(f'\nCurrent file: {file}')
    for key in commands.keys():
        print(f'{key}. {commands.get(key)[0]}')
    action = None
    while True:
        try:
            action = int(input('\nChoose one: '))
            if action in commands.keys():
                break
            else:
                print('Not correct.')
        except ValueError:
            print('Not number.')

    if action == 1:                 # choose file
        while True:
            file_name = input('File name: ')
            if file_name[-4:] != '.txt':
                print('the name should end with (.txt) !')
            else:
                if file_name == 'default_info_edit.txt':
                    print('Choose another one:')
                else:
                    break
        file = create(file_name)

    elif action == 2:                           # init
        print(commands.get(action)[1](file))
    elif action == 4:                           # insert
        print(commands.get(action)[1](file))
        show(file)
    elif action == 5:                           # remove
        with open(file, 'rb') as f:
            length = len(f.read(L).decode('windows-1251').rstrip('\x00'))
        if length > 10:
            while True:
                try:
                    delete = input('which order you want to remove: ')
                    if '.' not in delete:
                        delete = int(delete)
                        if delete >= 1:
                            break
                except ValueError:
                    print('Try again:')
            print(commands.get(5)[1](file, delete))
            show(file)
        elif 5 <= length < 10:
            print('Empty')
        else:
            print("didn't download")

    elif action == 6:                       # select by
        with open(file, 'rb') as f:
            length = len(f.read(L).decode('windows-1251').rstrip('\x00'))
        if length > 10:
            while True:
                try:
                    select = list(map(int, input('Enter size(s) to search separated by spaces: ').split()))
                    break
                except ValueError:
                    print('Try again')
            found = find1(file, select)
            if found:
                print(hat)
                for row in found:
                    print(f"| {row[0]: <63}| {row[1]: <31}| ${f'{float(row[2]):.2f}': <10}|"
                    f" {row[3]: <5}|")
                print(bottom)
            else:
                print()
        elif 5 <= length < 10:
            print('Empty')
        else:
            print('did not dowloded')
    elif action == 7:                                   # double select
        length = 0
        with open(file, 'rb') as f:
            length = len(f.read(L).decode('windows-1251').rstrip('\x00'))
        if length > 10:
            categories = [category.strip() for category in
                          input('Enter search categories SEPARATED WITH COMMA( ЧЕРЕЗ ЗАПЯТУЮ): ').split(',')]
            while True:
                try:
                    sizes = list(map(int, input('Enter size(s) to search separated by spaces: ').split()))
                    break
                except ValueError:
                    print('Try again:')
            found = find2(file, categories, sizes)
            if found:
                print(hat)
                for row in found:
                    print(f"| {row[0]: <63}| {row[1]: <31}| ${f'{float(row[2]):.2f}': <10}|"
                          f" {row[3]: <5}|")
                print(bottom)
        elif 5 <= length < 10:
            print('Empty')
        else:
            print('did not dowloded')
    elif action == 8:                           # exit()
        break
    else:                                       # table output
        commands.get(action)[1](file)