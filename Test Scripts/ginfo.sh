#
# Simple Shell script to give the user info, date and time
#

echo "Hello $USER"
echo "Today is \c"; date 
echo "No. of users logged in : \c"; who | wc -l 
echo "Calendar" 
cal
exit 0
