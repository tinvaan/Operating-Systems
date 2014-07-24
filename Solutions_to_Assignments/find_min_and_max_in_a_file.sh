#
# Shell script to find the lowest and highest values in a file
#

#! bin/bash

echo "5\n3\n6\n2\n1\n8\n4" > file_with_values.txt
sort file_with_values.txt > sorted.txt
echo "Lowest value in the file : "; head -1 sorted.txt
echo "Largest value in the file : "; tail -1 sorted.txt
echo 

