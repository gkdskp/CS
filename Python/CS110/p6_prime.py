# To print all prime numbers within a given range.

def prime(n):
	if n == 2 or n == 3:
		print(n)
	for i in range(2, int(n/2) + 1):
		if n % i == 0:
			break
		else:
			if i == int(n/2):
				print(n)


x = int(input("Enter lower limit: "))
y = int(input("Enter upper limit: "))

print("The prime numbers between {0} and {1} are:".format(x,y))
for i in range(x, y+1):
	prime(i)





