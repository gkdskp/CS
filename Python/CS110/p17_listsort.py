# Write a program to input a list of numbers and to rearrange them in ascending or
# descending order depending on user's choice. Find the largest, second largest and
# smallest values in the list.

n = int(input("Enter number of elements: "))
l = []

print("Enter the numbers to be inserted: ")
for i in range(n):
	x = int(input())
	l.append(x)

c = int(
	input(
		"""
Select option
1.Ascending order
2.Descending order
:"""
	)
)

if c == 1:
	l.sort()
	print("The sorted list is {0}".format(l))
	print(
		"The largest, second largest and smallest number in \
the list is {0}, {1} and {2}".format(
			l[-1], l[-2], l[0]
		)
	)
elif c == 2:
	l.sort(reverse=True)
	print("The sorted list is {0}".format(l))
	print(
		"The largest, second largest and smallest number in \
the list is {0}, {1} and {2}".format(
			l[0], l[1], l[-1]
		)
	)
