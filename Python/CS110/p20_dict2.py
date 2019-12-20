# Write a Python program to create a dictionary of roll numbers and names of N students.
# Print the student details in alphabetical order.

dict = {}

n = int(input("Enter number of students: "))
for i in range(n):
	x = int(input("Enter roll no: "))
	y = input("Enter name: ")
	dict[y] = x

l = sorted(dict)

print("The students list in alphabetic order")
for i in range(len(l)):
	print("{0}\t{1}".format(dict[l[i]], l[i]))