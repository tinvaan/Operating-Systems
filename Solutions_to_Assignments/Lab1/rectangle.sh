#
# Shell script to calculate the area and perimeter of a rectangle.
#

pi=3
read -p "Hello ! Who are you ? : " name
echo "Hi $name, Nice to see you :) "
read -p "$name Please enter the length of the rectangle : " length
read -p "$name Now enter the breadth of the rectangle : " breadth

echo "Area of the rectangle is : $((length * breadth))"
echo "Perimeter of the rectangle is : $((2 * (length + breadth)))"

read -p  "$name, Give the radius of a cirlce : " radius
echo "\n ### Assuming the value of pi ~ 3\n"
area_circle=$((6*(radius * radius)))
circumference=$((2 * (pi * radius)))
echo "Area of the circle : $area_circle"
echo "Circumference of the circle : $circumference"
echo

