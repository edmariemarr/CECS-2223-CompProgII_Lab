/*
* CECS 2223, Computer Programming II Lab
* Winter 2020
* Date: February 10, 2021
* Lab 8
* File name: Sphere.cpp
* Define the Sphere class
*/
#include "Sphere.h"

Sphere::Sphere() {
	radius = 0;
}
Sphere::Sphere(double theRadius) {
	setRadius(theRadius);
}
double Sphere::getVolume() const {
	return ((4.0 / 3.0) * getRadius() * getArea());
}