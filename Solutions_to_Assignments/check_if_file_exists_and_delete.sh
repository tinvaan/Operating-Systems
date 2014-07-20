#
# Simple shell script that verifies if a file exists in a given in the pwd
# if not, creates the file and then asks for the user's confirmation for deleting it
#

#! /bin/bash

read -p "Enter the directory(enter the full path) : " dirname
cd $dirname
read -p "Enter the filename : " filename
locate $filename
if($?!=0)
  echo "Could found $filename"
