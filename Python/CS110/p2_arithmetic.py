# Using functions develop a menu driven calculator for addition, substraction,
# multiplication, division and exponentiation

def add(a, b):
	return a + b

def sub(a, b):
	return a - b

def product(a, b):
	return a * b

def division(a, b):
	if b != 0:
		return a / b
	else:
		return "Error"

def exp(a, b):
	return a ** b


x = int(input('''
Select option
1.Addition
2.Substraction
3.Multiplication
4.Division
5.Exponentiation
: '''))
y = int(input("Enter first number: "))
z = int(input("Enter second number: "))

if x == 1:
	print("The sum is {0}".format(add(y,z)))
elif x == 2:
	print("The result is {0}".format(sub(y, z)))
elif x == 3:
	print("The product is {0}".format(product(y, z)))
elif x == 4:
	print("The result is {0}".format(division(y, z)))
elif x == 5:
	print("The result is {0}".format(exp(y, z)))
else:
	print("Invalid option")

