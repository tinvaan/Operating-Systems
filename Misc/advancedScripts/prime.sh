#
# A simple shell script to check if a number is prime or not
#

#! /bin/bash

read -p "Enter a number : " num
count=0
i=1
while [ $i -le $num ]
do
  if [ $((num % i)) == 0 ]
    # increment count
    count=$((count + 1))

    # increment counter var
    i=$((i + 1))
  fi
done

if [ $count == 2 ]
then
  echo "Prime !"
else
  echo "NOT Prime !"
fi
