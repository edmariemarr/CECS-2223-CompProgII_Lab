/*
* CECS 2223, Computer Programming II Lab
* Winter 2020
* Date: February 10, 2021
* Lab 8
* File name: Cylinder.h
* The Cylinder class is derived (inherits) from Circle
* You MUST define the class in Circle.cpp
*/
#pragma once
#include "Circle.h"

class Cylinder : public Circle {
private:
	double height;
public:
	Cylinder();
	Cylinder(double);
	void setHeight(double);
	double getHeight() const;
	double getVolume() const;
};
