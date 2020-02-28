#! /bin/bash

# Write a shell script that accepts two file names as arguments, checks if
# the permissions for these files are identical and if the permissions are
# identical,output common permissions and otherwise output each file
# name followed by its permissions.

if [[ $# -ne 2 ]]; then
    echo "Insufficient number of arguments"
    exit
fi

if [[ !(-f $1) || !(-f $2) ]]; then
    echo "Enter valid filenames"
    exit
fi

perm1="$(stat -c %A $1)"
perm2="$(stat -c %A $2)"

if [[ $perm1 = $perm2 ]]; then
    printf "Common permission: %s\n" $perm1
else
    printf "Permissions\n %s: %s\n%s: %s\n" $1 $perm1 $2 $perm2
fi
