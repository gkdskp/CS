#! /bin/bash

# Write a script that compares two directories dir1 and dir2(supplied as
# arguments) and copies to dir1 from dir2 every file that is not present in
# dir1.

if [[ $# -ne 2 ]]; then
    echo "Insufficient number of arguments"
    exit
fi

if [[ !(-d $1) || !(-d $2) ]]; then
    echo "Invalid arguments. Please enter directory names"
    exit
fi

diff $1 $2 | grep "$1" | awk '{for(i = 4; i <= NF; i++) printf "%s ",$i; printf "\n"}' |
    while read filename; do
        cp "$1/$filename" $2
        echo "Copied $filename"
    done
