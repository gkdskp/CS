# Write a recursive function to display first N fibonacci numbers. Also print the sum of
# first n terms.


def fib(n):
	if n <= 1:
		return 1
	else:
		return fib(n - 1) + fib(n - 2)


n = int(input("Enter the number of terms: "))
s = 0

for i in range(n):
	print(fib(i))
	s = s + fib(i)

print("Sum of first {0} Fibronacci terms is {1}".format(n, s))
