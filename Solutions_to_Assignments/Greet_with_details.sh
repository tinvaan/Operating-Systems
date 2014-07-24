#
# A simple shell script that shows the user the following detials
# 1. Today's lab is shell programming.
# 2. We have "dd" files in /etc
# 3. The value of $x is 100
#

#! /bin/sh

echo "Today's lab is shell programming"
read -p "Enter path to look into : " path_to_dir
cd $path_to_dir
count=$(ls -l | wc -l)
echo "The no. of files in $path_to_dir is : $count"
echo "The value of \$x is 100"
echo
