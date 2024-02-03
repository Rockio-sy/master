#Шавиш Тарек         ИУ7-11Б
# Remove elements b(1,2)
num=0
while num <= 0:
 num=int(input("Insert the list's size: "))
list=[0] *num
for i in range(len(list)):
  list[i]=int(input(f"Insert the {i+1}'th elemnt:  "))
print(list)
rm=int(input("Write the elements index to remove: "))
if rm>=len(list):
  rm=len(list)-1
del list[rm]
print(list)
rm2=int(input("Write the second element's index to remove: "))  
if rm2>=len(list): 
  rm2=len(list) - 1
new_list=list[:rm2]+list[rm2+1:]
print(new_list)
