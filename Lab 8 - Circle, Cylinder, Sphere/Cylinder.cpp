/*
* CECS 2223, Computer Programming II Lab
* Winter 2020
* Date: February 10, 2021
* Lab 8
* File name: Cylinder.cpp
* Define the Cylinder class
*/
#include "Cylinder.h"

Cylinder::Cylinder() {
	height = 0;
}
Cylinder::Cylinder(double theHeight) {
	setHeight(theHeight);
}
void Cylinder::setHeight(double theHeight) {
	height = theHeight;
}
double Cylinder::getHeight() const {
	return height;
}
double Cylinder::getVolume() const {
	return (getArea() * getHeight());
}