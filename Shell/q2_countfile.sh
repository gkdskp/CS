#! /bin/bash

# Write a script to count the line of a file, to 
# also compute the total number of bytes and the 
# total number of words in the input files.

if [[ $# != 1 ]]
then
        echo "Give a file as an argument"
fi

if [[ !(-f $1) ]]
then
        echo "$1 is not a valid file"
fi

noOfLines=$( cat $1 | wc -l )
noOfBytes=$( cat $1 | wc -c )
noOfWords=$( cat $1 | wc -w )

printf "No of lines: %s\nNo of bytes: %s\nNo of words: %s\n" \
	"$noOfLines" \
	"$noOfBytes" \
	"$noOfWords" 