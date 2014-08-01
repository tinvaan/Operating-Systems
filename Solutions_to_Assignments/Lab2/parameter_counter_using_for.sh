#
# A shell script that counts the number of command line arguments using the for statement
#

#! /bin/bash

parameter_count=0

for i in $@
do 
  parameter_count=$((parameter_count + 1))
done
echo "No of parameters is : $parameter_count"
echo
