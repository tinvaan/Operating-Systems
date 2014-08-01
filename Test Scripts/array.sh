#
# Simple shell script to demonstrate the working of arrays.
#

#! /bin/bash

echo "Creating an array called ARRAY\n"
random_var=05
# Declare array 
ARRAY=($random_var)

# Add/insert values to array
ARRAY+=(20)
ARRAY+=(30)

echo ${ARRAY[*]}
