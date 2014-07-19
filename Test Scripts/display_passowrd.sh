#
# Shell script that doesn't display the characters being inputted.
# Useful when recieving passowrds as input.
#

#! /bin/bash

read -s -p "Enter password : " entered_password
echo
echo "Your password - ${entered_password} "

