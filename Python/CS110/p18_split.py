# Write a program to input a string and to:
# 	a. Sort it in alphabetical order of starting letter of each word.
#	   [eg: 'hello how are you' should be sorted as 'are hello how you']
# 	b. Insert a word before a specified word in the string. [eg: in the above string insert
# 	   'dear' before 'how' so that output is 'hello dear how are you ']
# 	c. To reverse each word of the string [eg:'hello how are you ' should become 'olleh
#      woh era uoy ']

s = input("Enter a string: ")
l = s.split()
l.sort()
print(" ".join(l))

l = s.split()
x = input("Enter string to be searched: ")
y = input("Enter the string to be inserted: ")
print("String after inserting ", y)
for i in range(len(l)):
	if l[i] == x:
		l.insert(i, y)
		break
print(" ".join(l))

print("String after letters in each word reversed")
l = s.split()
for i in range(len(l)):
	l[i] = l[i][::-1]
print(" ".join(l))
