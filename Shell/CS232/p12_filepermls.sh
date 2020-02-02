#! /bin/bash

# Write a shell script that displays a list of all the files in the current
# directory to which the user has read, write and execute permissions.

ls -l | grep "^-rwx" | awk '{printf "%s",$NF; printf "\n"}'