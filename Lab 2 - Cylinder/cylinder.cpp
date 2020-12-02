/*
	CECS 2223, Computer Programming II Lab
	Winter 2020
	Date: November 25, 2020
	Topic: OOD Review
	File name: Cylinder.cpp
	Define the Cylinder class
*/

#include "cylinder.h"

// number must be initialized to 1
int Cylinder::number = 1;
// PI must be initialized to 3.1416
const double Cylinder::PI  = 3.1416;

Cylinder::Cylinder() {
	radius = 0.0;
	height = 0.0;
	cylNumber = number++;	
}

// The get and set methods DO NOT prompt the user for values
// or include any cout or printf statements
Cylinder::Cylinder(double aRadius) {
	radius = aRadius;
	height = 0.0;
	cylNumber = number++;
}

Cylinder::Cylinder(double aRadius, double aHeight) {
	radius = aRadius;
	height = aHeight;
	cylNumber = number++;
}

void Cylinder::setRadius(double aRadius) {
	radius = aRadius;
}

void Cylinder::setHeight(double aHeight) {
	height = aHeight;
}

double Cylinder::getRadius() {
	return radius;
}

double Cylinder::getHeight() {
	return height;
}

double Cylinder::getDiameter() {
	return 2 * getRadius();
}

double Cylinder::getCircumference() {
	return 2 * PI * getRadius();
}

double Cylinder::getArea() {
	return PI * (getRadius() * getRadius());
}

double Cylinder::getVolume() {
	return PI * (getRadius() * getRadius()) * getHeight();
}

// The printDetails method uses printf to output values formatted
// to be displayed in a table
// the values to be displayed are: object number, radius, height,
// diameter, circumference, area and volume. All values must be 
// printed in the same line.

void Cylinder::printDetails() {
	printf("%3i%7.2f%7.2f%7.2f%7.2f%7.2f%7.2f\n", cylNumber, getRadius(), getHeight(), getDiameter(), getCircumference(), getArea(), getVolume());
}