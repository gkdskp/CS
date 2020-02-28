# Write a program to input a string and to count the number of vowels, consonants, words
# and commas in it. Also display the string with all its vowels removed.

x = input("Enter a string: ")
s = x.lower()
vowels = 0
consonants = 0
words = 1
commas = 0
str = x

for i in range(len(s)):
	if s[i] in "aeiou":
		vowels += 1
		str = str.replace(s[i], "")
	elif s[i] in " ":
		words += 1
	elif s[i] in ",":
		commas += 1
	elif s[i].isalpha() and s[i] not in "aeiou":
		consonants += 1

print("Number of vowels are ", vowels)
print("Number of consonants are ", consonants)
print("Number of words are ", words)
print("Number of commas are ", commas)
print("The string without vowels is ", str)
