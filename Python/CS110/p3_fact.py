# Using functions find the factorial of first N natural numbers

def fact(n):
	p = 1
	for i in range(1, n+1):
		p = p * i
	return p

x = int(input("Enter number: "))
for i in range(1, x+1, 1):
	print("The factorial of {0} is {1}".format(i, fact(i)))

