# Tarek Shawesh
# IU7-11B
"""1 task. make new file with structure Student {name: string(20), age: integer, marks: array of integer}
2 taks. read prev file and print table of student with (avg  of marks > 3.5)
"""
print("THANKS FOR HOLDING SASHA ")
'''                                             Given Info                                                   '''
stud_1, age_1 = str("Tarek"), 199
stud_2, age_2 = str("Hasan"), 33
stud_3, age_3 = str("Lord"), 79
marks_1 = [2,5,6,7]
marks_2 = [3,5,6]
marks_3 = [8,9,4,2,4]
names = [stud_1, stud_2, stud_3]
ages = [age_1, age_2, age_3]
marks = [marks_1, marks_2, marks_3]

'''                                             Find the AVG                                                         '''
mids = []
med_1 = 0
for i in marks_1:
    med_1 += i
med_1 = med_1//len(marks_1)
if med_1 > 3.5:
    mids.append(med_1)
med_2 = 0
for i in marks_2:
    med_2 += i
med_2 = med_2//len(marks_2)
if med_2 > 3.5:
    mids.append(med_2)
med_3 = 0
for i in marks_3:
    med_3 += i
med_3 = med_3//len(marks_3)
if med_3 > 3.5:
    mids.append(med_3)

'''                                             Open file to write                                                   '''

with open("filo.txt", "w") as p:
    p.write(f"\nstud_1 name is :{stud_1}, with age {age_1} and marks:{marks_1}\n"
            f"stud_2 name is :{stud_2}, with age {age_2} and marks:{marks_2}\n"
            f"stud_3 name is :{stud_3}, with age {age_3} and marks:{marks_3}")
    p.close()

'''                                             Open file to read                                                    '''

with open("filo.txt", "r") as f:
    for line in f:
        print(f.read())
        print()

'''                                             Print the table                                                      '''

print("=" * 20, "THE TABLE", "=" * 20)
print(f"|{'-' *50}|\n|{'Student':^10}|{'Age':^5}|{'AVG of Marks':^33}|")
for i in range(3):
    mids[i] = str(mids[i])
    print(f"|{'-' *50}|\n|{names[i]:^10}|{ages[i]:^5}|{mids[i]:^33}|")
print(f"|{'-'*50}|")