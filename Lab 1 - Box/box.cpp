/*
	CECS 2223, Computer Programming II Lab
	Winter 2020, Sec. 05
	Date: November 18, 2020
	Topic: Review
	File name: Box.cpp
	Name: EDMARIE RODRIGUEZ MARRERO, ID#132704
	Define the Box class
*/
// write the include statements required
#include "box.h"

// write the using declaration
Box::Box() {
	height = 0;
	width = 0;
	length = 0;
}
// The get and set methods DO NOT prompt the user for values
// or include any cout or printf statements
Box::Box(int aHeight) {
	height = aHeight;
	width = 0;
	length = 0;
}
Box::Box(int aHeight, int aWidth) {
	height = aHeight;
	width = aWidth;
	length = 0;
}
Box::Box(int aHeight, int aWidth, int aLength) {
	height = aHeight;
	width = aWidth;
	length = aLength;
}
void Box::setHeight(int aHeight) {
	height = aHeight;
}
void Box::setWidth(int aWidth) {
	width = aWidth;
}
void Box::setLength(int aLength) {
	length = aLength;
}
int Box::getHeight() {
	return height;
}
int Box::getWidth() {
	return width;
}
int Box::getLength() {
	return length;
}
int Box::getVolume() {
	return (getHeight() * getWidth() * getLength());
}
int Box::getArea() {
	return ((2 * getLength() * getWidth()) + (2 * getLength() * getHeight()) + (2 * getHeight() * getWidth()));
}

// The printBox method uses printf to output values formatted
// to be displayed in a table
// the values to be displayed are: height, width, length,
// volume, and area. All values must be printed in the same line.
void Box::printBox() {
	printf("%7i%7i%7i%7i%6i\n", height, width, length, getVolume(), getArea());
}
