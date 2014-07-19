#
# A simple shell script to count the no. of files in a given directory
#

read -p "Enter the directory you want to look into(Make sure you enter the complete path) : " path_to_dir
cd $path_to_dir
count=$(ls -l | wc -l)
echo "The no. of files in ${pwd} is : $count"
echo
