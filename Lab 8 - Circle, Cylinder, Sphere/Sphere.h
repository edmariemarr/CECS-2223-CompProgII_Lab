/*
* CECS 2223, Computer Programming II Lab
* Winter 2020
* Date: February 10, 2021
* Lab 8
* File name: Sphere.h
* The Sphere class is derived (inherits) from Circle
* You MUST define the class in Sphere.cpp
*/
#pragma once
#include "Circle.h"

class Sphere : public Circle {
private:
	Circle radius;
public:
	Sphere();
	Sphere(double);
	double getVolume() const;
};
