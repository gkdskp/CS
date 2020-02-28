#! /bin/bash

# Write a shell script to delete all lines containing a specific word in one or
# more file supplied as argument to it.

if [[ $# -eq 0 ]]; then
    echo "Enter one or more filename(s)"
    exit
fi

echo "Enter the word to search"
read word

i=1
for file in "$@"; do
    cat $file |
        while read line; do
            if [[ $line != *"$word"* ]]; then
                echo $line >>.tempfile
            fi
        done
    cat .tempfile >$file
    rm .tempfile
done
