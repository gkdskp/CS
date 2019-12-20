#  Using functions
#  	(i) Print the digits of a number
#  	(ii) Reverse the number
#  	(iii) To check whether a given number is Armstrong or not
#  	(iv) To check whether a number is palindrome or not

def digits(n):
	while n > 0:
		digit = n % 10
		print(digit)
		n = n // 10

def rev(n):
	num = 0
	while n > 0:
		digit = n % 10
		num = num * 10 + digit
		n = n // 10
	return num

def armstrong(n):
	sum = 0
	num = n
	while n > 0:
		digit = n % 10
		sum = sum + digit ** 3
		n = n /10
	if num == sum:
		print("Number is Armstrong")
	else:
		print("Number is not Armstrong")

def pallindrome(n):
	if n == rev(n):
		print("Number is pallindrome")
	else:
		print("Number is not pallindrome")

x = int(input("Enter a number: "))

print("The digits of the number are: ")
digits(x)
print("The reverse of the number is {0}".format(rev(x)))
armstrong(x)
pallindrome(x)
