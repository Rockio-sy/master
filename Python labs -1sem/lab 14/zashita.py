import os
from struct import pack, unpack, calcsize
pat = "db.txt"
frml = '60s60sfi'
L = calcsize(frml)
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

def insert(path):
    with open(path, 'rb') as f:
        length = len(f.read().decode('windows-1251').rstrip('\x00'))
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

print(insert(pat))
pp = int(input("Which one you want to remove: "))

print(remove(pat, pp))
