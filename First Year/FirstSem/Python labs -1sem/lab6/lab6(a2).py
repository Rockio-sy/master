#шавиш тарек
# add element a(1,2)
num=0
while num <= 0:
  num = int(input("Insert the array size: "))
list = [0] *num
for i in range(len(list)):
  list[i]=int(input(f"Insert the {i+1} th number: "))
print(list)              
new2 = int(input("insert your new sec number: "))
index2 = int(input("insert the index: "))
list.append(0)
for i in range(len(list)-1,1,-1):
  list[i]=list[i-1]
  if index2==i:
    list[i]=new2
    break


print(list)