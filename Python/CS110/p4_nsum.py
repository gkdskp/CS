# To find the sum of first N odd numbers and even numbers.


def sum(n):
	p = 0
	for i in range(1, n + 1):
		p = p + i
	return p


x = int(input("Enter number: "))
print("The sum of first {0} natural numbers is {1}".format(x, sum(x)))
