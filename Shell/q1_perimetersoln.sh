#! /bin/bash

# If p is the perimeter of a right angle triangle with integral length sides, {a,b,c},
# there are exactly three solutions for p = 120.  {20,48,52}, {24,45,51}, {30,40,50} 
# For which value of p ≤ 1000, is the number of solutions maximised? Write a shell script
# to find the same

noOfSolutions() {
	# No solutions if perimeter is odd
	if (( $1%2 != 0 ))
	then
		echo "0"

	else
		count=0
		# for (( i=1; i <= $1; i++ ))
		for (( i=1; i <= $(( $1/2 )); i++ ))
		do
			# for (( j=1; j <= $1; j++ ))
			for (( j=1; j < $(( $1/3 )); j++ ))
			do
				c=$(( $1-i-j ))
				if (( i*i + j*j == c*c ))
				then
					count=$(( count+1 ))
				fi
			done
		done

		echo $count
	fi
}

# for (( i=1; i <= 1000; i++ ))
for (( i=2; i <= 1000; i=i+2 ))
do
	echo "$i $( noOfSolutions $i )" >> temp
done

echo "The number with maximum number of solution and its number of solution is"
echo `cat temp | sort -r -k 2 | head -n 1`
rm temp