#Шавиш Тарек ИУ7-11Б
# finding the extimum

num=0
while num<=2:
  num=int(input("Insert the list size (more than 2): "))
list=[0] *num
for i in range (len(list)):
  list[i]=int(input(f"insert the {i+1} th element: "))
k=int(input("How many extremum u want: "))
count=0
for i in range(1,len(list)-1):
  if list[i]<list[i+1] and list[i]<list[i-1] or list[i]>list[i+1] and list[i]>list[i-1]:
      count+=1
      if count==k:
          print(list[i])
          break
if count==0:
  print("there isn't any extrimum.")
elif count<k:
  print(f"The list dosn't exist {k} extrimums.")
  
  


