#
# A simple shell script that demonstrates the usage of case statements.
# Using case statements to show which number was entered.
#

#! /bin/sh

# Get the number
read -p "Enter the number (1-6) : " num
# case statements begin

case $num in
  1) echo "ONE" ;;
2) echo "TWO" ;;
3) echo "THREE" ;;
4) echo "FOUR" ;;
5) echo "FIVE" ;;
6) echo "SIX" ;;
*) echo "Number you entered was greater than 6" ;;
  esac
