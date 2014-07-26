#
# Shell script that gives the command entered, each and every argument and total number of arguments in separate lines.
#

#! /bin/sh

echo "Command you entered is : $0"
echo "List of arguments given are : "
echo
for i in "$@"
do
  echo "$i"
done
echo
echo "Total number of arguments are : $*"
echo
