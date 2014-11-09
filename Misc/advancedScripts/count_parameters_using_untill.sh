#
# A simple shell script to count the no. of parameters using untill loop.
#

#! /bin/sh

newvar=0

for i in $*
do
  until [ "$i" -ne $NULL ]
  do
    echo "$newvar"
    a=`expr $a + 1`
    break
  done
done
echo "No of parameters = $newvar"
