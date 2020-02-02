#! /bin/bash

# Write a shell script that folds long lines into 40 columns. Thus any line
# that exceeds 40 characters must be broken after 40th ; a\ is to be
# appended as the indication of folding and the processing is to be
# continued with the residue. The input is to be through a text file created
# by the user.

if [[ $# -ne 2 || !(-f $1) ]]
then
    echo "Please provide valid input filename and desired output filename"
    exit
fi

cat $1 |
while read line
do
    i=0
    echo $line |
    while read -r -n1 char
    do
        i="`expr $i + 1`"
        if [[ i -eq 40 ]]
        then
            printf "\n%s" $char >> $2
            i=1
        elif [[ $char = "" ]]
        then
            printf " " >> $2
        else
            printf "%s" $char >> $2
        fi
    done
done