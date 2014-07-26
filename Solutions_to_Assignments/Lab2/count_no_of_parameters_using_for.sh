#
# A shell script that counts the number of command line arguments using the for statement
#

#! /bin/bash

max_val=10

for i in $max_val
do
  if [$i -eq " "] || [$i -eq "\n"]; then
    echo "No of command line arguments provided is : $i"
    break
  fi
done
