 # Write a program that reads a file and writes out a new file with the 
 # lines in reversed order.

try:
	f = open("input.txt", "r")
	k = open("output.txt", "w")
	
	c = f.readlines()
	for i in reversed(range(len(c))):
		k.write(c[i])
	k.close()

	print("Contents of output.txt")
	k = open("output.txt","r")
	x = k.readlines()
	for i in x:
		print(i)

	f.close()
	k.close()

except FileNotFoundError:
	print("The file input.txt does not exists. Please try again after \
creating the file.")

