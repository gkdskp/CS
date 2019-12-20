# To find the largest and second largest of N numbers.

i = 0
x = int(input("Enter number of terms: "))
largest1 = int(input("Enter number1: "))
largest2 = largest1

while i < x-1:
	y = int(input("Enter number{}: ".format(i+2)))
	if y > largest1:
		largest2 = largest1
		largest1 = y
	i = i + 1

print("The largest and second largest number in the list is {0} and {1} \
".format(largest1, largest2))
