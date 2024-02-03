#Шавиш Тарек         ИУ7-11Б
# Remove elements b(2)
num=0
while num <= 0:
 num=int(input("Insert the list's size: "))
list=[0] *num
for i in range(len(list)):
  list[i]=int(input(f"Insert the {i+1}'th elemnt:  "))
print(list)
rm2=int(input("Write the element's index to remove: "))
if rm2 >= len(list):
  rm2 = len(list) - 1
for i in range(rm2, len(list)-1):
    list[i]=list[i+1]
list.pop()

print(list)