#! /bin/bash

echo "You are currently in : "; pwd
read -p "Enter name of new directory : " dirname
echo "Name of the new directory to be created $dirname "
echo "Creating new directory ... "
cd ~/Desktop
mkdir "$dirname"
echo "DONE ! Successfully created new directory"
echo

#Check if the directory was created.
#if ($? == 0)
#  echo "Successfully created new directory"
#else
#  echo "Failed to create new directory"

