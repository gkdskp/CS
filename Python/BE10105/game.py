# Project

import random
print("HANGMAN Game")
def startGame(word, attempts, found):
	if attempts == 0:
		print("You Lost! The word is {0}".format(word))
		return 
	if len(found) == len(word):
		print( "You won! The word is {0}".format(word))
		return
	s = ""
 
	for i in range(len(word)):

		if i in found:
			k = word[i] + " "
		else:
			k = "_ "
		s = s + k
	print(s)
	print("Attempts left: {0}".format(attempts))			
	y = input("Enter guess: ").upper()
	
	c = -1
	
	for i in range(len(word)):
		if word[i] == y:
			if i not in found: found.append(i)
			print("The letter found at {0}th position".format(i+1))
			c = 0
	if c == -1:
		attempts = attempts - 1
	print()
	print()
	print()
	startGame(word, attempts, found)
	


words = ["ALPHABET", "AEROPLANE", "IRREGARDLESS", "CALCULATOR", "ENCYCLOPEDIA", "DISINTERESTED"]
x = int(len(words) * random.random())
word = words[x].upper()
attempts = 5
found = []
print("Length of the word is: {0}".format(len(word)))
startGame(word, attempts, found)
