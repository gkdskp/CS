# To compute the sum of the series x-x2/2+x3/3-x4/4+.......N terms. Use functions to
# compute the power of x.


def sum(x, n):
	s = 0
	for i in range(1, n + 1):
		s = s + float((-1) ** (i + 1) * x ** i) / i
	return s


def power(a, b):
	return a ** b


a = int(input("Enter x: "))
y = int(input("Enter n: "))
print("The sum of the series is {0}".format(sum(a, y)))

c = int(input("Enter number: "))
d = int(input("Enter power: "))
print("{0} raised to {1} is {2}".format(c, d, power(c, d)))
