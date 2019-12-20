# Create functions to calculate factorial and power.
# Do the following programs by importing this function.
# 	a. Calculate nCr
# 	b. Calculate sum of series 1+x+x2/2!+x3/3!+..........N terms.
# 	c. Calculate the sum of sine series (x - x3/3! + x5/5! - x7/7! + x9/9! - ...N terms)


def fact(n):
	p = 1
	for i in range(1, n+1):
		p = p * i
	return p

def pow(n, r):
	return n ** r

print("Combination:")
n = int(input("Enter n: "))
r = int(input("Enter r: "))

if n >= r:
	ncr = fact(n)//(fact(r)*fact(n-r))
	print("nCr is: {0}".format(ncr))
else:
	print("Math error")

print("\nSum of first series")
x = int(input("Enter x: "))
n = int(input("Enter n: "))
s = 0
for i in range(0, n):
	s = s + float(pow(x,i))/fact(i)
print("Sum of the series is: {0}".format(s))

print("\nSum of sine series")
x = float(input("Enter x: "))
n = int(input("Enter n: "))
s = 0

for i in range(1, n+1, 1):
	o = 2 * (i - 1) + 1
	s = s + float((-1)**(i+1) * pow(x, o))/fact(o)
print("Sum of the sine series is: {0}".format(s))
