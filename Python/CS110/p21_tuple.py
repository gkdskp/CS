# Create a tuple that contains the names of all the months in a year.Find the length of
# the tuple and also check whether an element exists within a tuple or not.

tu = (
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December",
)

print("The length of the tuple is {0}".format(len(tu)))

x = input("Enter search term: ")

if x in tu:
	print("{0} is in the tuple".format(x))
else:
	print("{0} is not found in the tuple".format(x))
