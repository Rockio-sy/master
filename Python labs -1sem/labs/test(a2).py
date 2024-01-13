#Tarek shawesh 
#a(1,2)
num=0
while num<=0:
  num=int(input("Insert the array size: "))
list=[0] *num
for i in range(len(list)):
  list[i]=int(input(f"Insert the {i+1} th number: "))
print(list)              
new2=int(input("insert your new sec number: "))
index2=int(input("insert the index: "))
fin_list=list[:index2]+[new2]+list[index2:]
print(fin_list)
