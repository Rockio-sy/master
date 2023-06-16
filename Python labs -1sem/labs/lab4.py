#Tarek shawesh IU7-11B
#Zashita
import math as m
pi=3.14
x1 = float(input("Please enter the initial value: "))
step = float(input("Please enter the step: "))
x2 = float(input("Please enter the final value: "))


a=[]
x=x1
while x <= x2:
  y = x**2 - 25
  x += step
  a.append(y)
ymin=min(a)
ymax=max(a)
print("\n")
n = int(((x2 - x1)/step)) + 1
for x in range(n):
   x = x1 +step * x
   y = x**2 - 25
   print("|","{:5.1f}".format(x)," " * round(( ( y - ymin) / (ymax - ymin)) * 80),"*" )
 
