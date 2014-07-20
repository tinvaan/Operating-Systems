#
# Script to understand some options(specifically the -e) option of the echo command
#

clear
echo -e "Today is \c "; date
echo -e "Number of users logged in today is \c "; who | wc -l
echo "Calendar"; cal

