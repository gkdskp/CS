# Write a program to input a string and to check whether it is a palindrome. Also change
# the case of the string.

x = input("Enter a string: ")
rev = x.lower()[::-1]

if x.lower() == rev:
	print("The given string is pallindrome")
else:
	print("The given string is not pallindrome")

print("The given string in uppercase is ", x.upper())
print("The given string in lowercase is ", x.lower())
print("The given string with case changed is ", x.swapcase())
