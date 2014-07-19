#
# Shell script to calculate the area and perimeter of a rectangle.
#

read -p "Hello ! Who are you ? : " name
echo "Hi $name, Nice to see you :) "
read -p "$name Please enter the lenght of the rectangle : " length
read -p "$name Now enter the breadth of the rectangle : " breadth

echo "Area of the rectangle is : $((length * breadth))"
echo "Perimeter of the rectangle is : $((2 * (length + breadth)))"
