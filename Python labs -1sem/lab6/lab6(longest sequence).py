#Tarek shawesh ѕоследовательность чисел, в которой все, начина€ с 3-го, €вл€ютс€
#произведением двух предыдущих
n=0
while n <= 2:
    n = int(input('Insert the list size(more than 2): '))
a = [0] * n
for i in range(n):
    a[i] = int(input(f'Insert {i+1}th element: '))  
 
if n <= 2: 
    print('The size should be more than 2')
else:
    mas_1 = []
    len_mas_1 = 0
    max_len_mas_1 = 0
    for i in range(len(a)-1,1,-1):
        if a[i] == a[i-1] * a[i-2] or a[i] == a[i-1] * a[i-2]:
            len_mas_1 += 1
            max_len_mas_1 = len_mas_1
        else:
            len_mas_1 = 0
    mas_2 = []
    len_mas_2 = 0
    while len_mas_2 != max_len_mas_1:
        for i in range(len(a)-1,1,-1):
            if a[i] == a[i-1] * a[i-2]:
                len_mas_2 += 1
                mas_2.append(a[i])
                if len_mas_2 == max_len_mas_1:
                    mas_2.append(a[i-1])
                    mas_2.append(a[i-2])
                    break
            else:
                len_mas_2 = 0
                mas_2 = []
    if mas_2 == []:
        print('The longest sequence length is 0')
    else:
        print('longest continuous sequence: ',list(reversed(mas_2)))
        
