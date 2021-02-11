/*
* CECS 2223, Computer Programming II Lab
* Winter 2020
* Date: February 10, 2021
* Lab 8
* File name: Circle.cpp
* Define the Circle class
*/
#include "Circle.h"

const double Circle::pi = 3.1416;

Circle::Circle() {
	radius = 0;
}
Circle::Circle(double theRadius) {
	radius = theRadius;
}
void Circle::setRadius(double theRadius) {
	radius = theRadius;
}
double Circle::getRadius() const {
	return radius;
}
double Circle::getArea() const {
	return (pi * getRadius() * getRadius());
}