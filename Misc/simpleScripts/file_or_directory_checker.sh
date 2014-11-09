#
# Given a number of filenames as arguments, check if every argument supplied is a file or directory.
# If it's a directory, it should be appropriately reported.
# If it's a filename, then the file as well as the number of lines present in it should be reported.
#

#! /bin/bash

for i in $@
do
  passed="$i";
  if [ -d ${passed} ]; then
    echo "${passed} is a directory";
  else
    if [ -f ${passed} ]; then
      echo "${passed} is a file";
      no_of_lines=`cat $i | wc -l`
      echo "Number of lines in ${passed} is : $no_of_lines"
    else
      echo "Invalid filename/type";
    fi
  fi
done
