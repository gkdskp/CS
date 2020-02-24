#! /bin/bash

# Write shell script to show various system configuration like
#    1) Currently logged user and his login name
#    2) Your current shell
#    3) Your home directory
#    4) Your operating system type
#    5) Your current path setting
#    6) Your current working directory
#    7) Number of users currently logged in

clear
log=`who|wc -l`
echo "The current user is $USER"
echo "The current shell is $SHELL"
echo "The home directory is $HOME"
echo "The OS type is $OSTYPE"
echo "the current path setting is $PATH"
echo "The working directory is $PWD"
echo "There are $log users logged in"
