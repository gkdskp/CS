# Write a program to input a string and to do the following processes.
# 	a. Count the number of times a given substring is occurring and display the starting
# 	   index of each occurrance.
# 	b. Replace the first two occurrences of the substring with another given string.
# 	   [Hint: Use replace (old,new,max)]

s = input("Enter string: ")
sub = input("Enter substring: ")
c = 0
str = s
s1 = "Hi" # The given string

for i in range(len(s)):
	subcheck = s[i:len(sub)+i]
	if subcheck == sub:
		print("The index of {0}th occurence is {1}".format(c, i))
		if c == 0 or c == 1:
			str = str[:i] + s1 + str[len(sub)+i:]
		c += 1

print("Total number of occurence is ",c)
print("String with the substring \'{}\' replaced by 'Hi' is : {}".format(sub, str))





