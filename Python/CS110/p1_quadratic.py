# To find the roots of a quadratic equation

a = int(input("Enter a: "))
b = int(input("Enter b: "))
c = int(input("Enter c: "))

d = b ** 2 - 4 * a * c

if d >= 0:
	root1 = (-b + d ** 0.5) / (2 * a)
	root2 = (-b - d ** 0.5) / (2 * a)
	print("Roots are {0} and {1}".format(root1, root2))

else:
	x = -b / (2 * a)
	y = (-d) ** (0.5) / (2 * a)
	print("Roots are {0} + i{1} and {0} - i{1}".format(x, y))
