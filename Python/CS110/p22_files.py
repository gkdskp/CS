# Write a Python program to create a file containing N numbers. Read the contents of 
# the file and display the square of each number.

import pickle

f = open("numbers.txt", "wb")
n = int(input("Enter limit: "))

for i in range(n):
	k = int(input("Enter number: "))
	pickle.dump(str(k), f)
f.close()


f = open("numbers.txt","rb")
for i in range(n):
	x = int(pickle.load(f))
	print(x**2)
f.close()
