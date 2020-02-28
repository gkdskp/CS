#! /bin/bash

# Write a shell script that, given a file name as the argument will count
# vowels, blank spaces, characters, number of line and symbols.

if [[ $# -ne 1 || !(-f $1) ]]; then
    echo "Please provide a filename"
    exit
fi

vc="$(grep -o [aeiouAEIOU] $1 | wc -l)"
bsc="$(grep -o " " $1 | wc -l)"
cc="$(cat $1 | wc -m)"
lc="$(cat $1 | wc -l)"
sc="$(grep -o [\!\@\#$\%\^\&\*\(\)] $1 | wc -l)"

printf "Number of vowels: %s\n\
Number of blank spaces: %s\n\
Number of characters: %s\n\
Number of lines: %s\n\
Number of symbols: %s\n" $vc $bsc $cc $lc $sc
