#! /bin/bash

# Write a shell script that displays a special listing showing the
# permissions, size filename and last modification time of filename
# supplied as arguments. Provide suitable headers using the printf
# command.

if [[ $# -ne 1 ]]; then
    echo "Invalid number of arguments"
    exit
fi

if [[ ! (-f $1) ]]; then
    echo "$1 not a file"
    exit
fi

perm="$(stat -c %A $1)"
size="$(stat -c %s $1)"
fname="$(stat -c %n $1)"
modtime="$(stat -c %y $1)"

printf "Permissions: %s\nSize: %dB\nName: %s\nLast Modified:\
%s %s %s\n" $perm $size $fname $modtime
