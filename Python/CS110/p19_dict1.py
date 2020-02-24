# Write a python program to create a dictionary having key-value pairs (“Name”, age). Write
# the code for following operations
# 	a. To add a new key value pair.
# 	b. To display the number of items in the dictionary.
# 	c. To remove a particular key-value pair from the dictionary

dict = {}

n = int(input("Enter number of items: "))
for i in range(n):
	y = input("Enter name: ")
	x = int(input("Enter age: "))
	dict[y] = x

print("Insert a new key-value pair")
y = input("Enter name: ")
x = int(input("Enter age: "))
dict[y] = x

print("The updated dictionary is {0}".format(dict))

print("The dictionary has {0} items".format(len(dict)))

y = input("Enter the name to be deleted: ")
del dict[y]

print("The updated dictionary is {0}".format(dict))


