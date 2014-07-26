#
# Shell script to calcuate the area and circumference of a circle.
#

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ #

#! /bin/zsh

# Get the input
read -p "Enter the radius of the circle : " radius

# Define the value of pi
pi=3.14

# Print the result
echo "The area of the circle is : $((pi * (radius * radius)))"
