#! /bin/bash

# Write a shell script which receives two file names as arguments. It
# should check whether the two file contents are same or not. If they are
# same then second file should be deleted.

if [[ $# -ne 2 ]]
then
    echo "Invalid number of arguments"
    exit
fi

if [[ !(-f $1) || !(-f $2) ]]
then
    echo "Enter valid filenames"
    exit
fi

text="`diff $1 $2 | wc -l`"

if [[ text -eq 0 ]]
then
    echo "Both files are the same. Removing $2"
    rm $2
    exit
else
    echo "Both files are different"
    exit
fi