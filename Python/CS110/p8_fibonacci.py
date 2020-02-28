# To generate first N Fibonacci numbers.


def fib(n):
	i1 = 1
	i2 = 1
	i = 0

	print(i1)
	if n != 1:
		print(i2)
	while i < n - 2:
		print(i1 + i2)
		temp = i1
		i1 = i2
		i2 = temp + i2
		i = i + temp


x = int(input("Enter number of terms: "))
print("The first {0} numbers in Fibonacci series is:".format(x))
fib(x + 1)
