# Write a menu driven program using functions to calculate the area of a shape specified by
# the user (shape can be circle, rectangle, square or cube).


def cir(r):
	area = 3.14 * (r ** 2)
	return area


def rec(a, b):
	area = a * b
	return area


def sq(a):
	return a ** 2


def cube(a):
	return 6 * (a ** 2)


n = int(
	input(
		"""
Select option
1.Circle
2.Rectangle
3.Square
4.Cube
:"""
	)
)

if n == 1:
	r = float(input("Enter radius: "))
	print("Area of the circle is {0}".format(cir(r)))
elif n == 2:
	a = float(input("Enter length: "))
	b = float(input("Enter breadth: "))
	print("Area of the rectangle is {0}".format(rec(a, b)))
elif n == 3:
	a = float(input("Enter side length: "))
	print("Area of the square is {0}".format(sq(a)))
elif n == 4:
	a = float(input("Enter cube length: "))
	print("Surface area of the cube is {0}".format(cube(a)))
else:
	print("Invalid option")
