#! /bin/bash

# Write a shell script that will take an input file and remove identical lines

if [[ $# -ne 1 || !(-f $1) ]]
then
    echo "Enter filename"
    exit
fi

text="`sort $1 | uniq`"
echo "$text" > samplefile
