# Write a program to input a list of numbers and to do following
# 	a. Count number of zeros, positive numbers and negative numbers in the list.
# 	b. Copy zeros, positive numbers and negative numbers from the original list to three
#      separate lists.

l = []
n = int(input("Enter number of elements in list: "))

print("Enter numbers to be inserted: ")
for i in range(0, n):
	x = int(input())
	l.append(x)

zero = 0
positive = 0
negative = 0

zlist = []
plist = []
nlist = []

for i in range(0, n):
	if l[i] == 0:
		zero = zero + 1
		zlist.append(l[i])
	elif l[i] > 0:
		positive = positive + 1
		plist.append(l[i])
	elif l[i] < 0:
		negative = negative + 1
		nlist.append(l[i])

print(
	"The number of negative numbers is {0} and the list is {1}".format(negative, nlist)
)
print(
	"The number of positive numbers is {0} and the list is {1}".format(positive, plist)
)
print("The number of zeroes is {0} and the list is {1}".format(zero, zlist))
