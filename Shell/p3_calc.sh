#! /bin/bash

# Write a shell script to implement a menu driven calculator with following functions
#   1) Addition
#   2) Subtraction
#   3) Multiplication
#   4) Division
#   5) Modulus

clear
i="y"
echo "Enter First number"
read num1
echo "Enter second number"
read num2
while [ $i = "y" ]; do
	echo "1 - Sum"
	echo "2 - Difference"
	echo "3 - Product"
	echo "4 - Quotient"
	echo "5 - Remainder"
	read c

	case $c in
	1)
		sum=$(expr $num1 + $num2)
		echo "Sum = "$sum
		;;

	2)
		sum=$(expr $num1 - $num2)
		echo "Difference = "$sum
		;;

	3)
		sum=$(expr $num1 \* $num2)
		echo "Product = "$sum
		;;

	4)
		sum=$(expr $num1 / $num2)
		echo "Quotient = "$sum
		;;

	5)
		sum=$(expr $num1 % $num2)
		echo "Remainder = "$sum
		;;
	esac

	echo "Continue (y/n)?"
	read i
	if [ $i != "y" ]; then
		exit
	fi
done
