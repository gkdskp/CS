# Write a python program to create a class Car with attributes- model, year and 
# price and a method cost () for displaying price. Create two instances of the 
# class and call the method for each instance

class Car:
	def __init__(self, model, year, cost):
		self.model = model
		self.year = year
		self.price = cost
	def cost(self):
		print(self.price)

name1 = input("Enter car 1 name: ")
year1 = int(input("Enter car 1 year: "))
cost1 = int(input("Enter car 1 cost: "))
car1 = Car(name1, year1, cost1)

name2 = input("Enter car 2 name: ")
year2 = int(input("Enter car 2 year: "))
cost2 = int(input("Enter car 2 cost: "))
car2 = Car(name2, year2, cost2)

print("Cost of cars")
print("Car1: ", end="") 
car1.cost()
print("Car2: ", end="") 
car2.cost()
