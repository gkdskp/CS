#! /bin/bash

# Write a script called addnames that is to be called as follows ./addnames ulist username
# Here ulist is the name of the file that contains list of user names and username is a
# particular student’s username. The script should
#	i) check that the correct number of arguments was received and print a message, in
#    case the number of arguments is incorrect
#   ii) check whether the ulist file exists and print an error message if it does not
#   iii) check whether the username already exists in the file. If the username exists, print
#    a message stating that the name already exists. Otherwise, add the username to the
#    end of the list

if [[ $# -ne 2 ]]; then
	echo "Invalid number of arguments. Argument1 - userlists file. Argument 2 - user"
	exit
fi

if [[ ! (-e $1) ]]; then
	echo "Not a valid file location or file dosent exist"
	exit
fi

NO=$(grep -c -e $2 $1)
if [[ $NO -eq 0 ]]; then
	echo $2 >>$1
	echo "Username is added"
	exit

else
	echo "Username already exists"
	exit
fi
