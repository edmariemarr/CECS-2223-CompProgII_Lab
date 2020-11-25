/*
	CECS 2223, Computer Programming II Lab
	Winter 2020, Sec. 05
	Date: November 25, 2020
	Topic: OOD Review
	File name: Cylinder.h
	This file declares a class named Cylinder
	Name: EDMARIE RODRIGUEZ MARRERO, ID#132704
*/

#pragma once
#include <iostream>

class Cylinder {
private:
	double radius;
	double height;
	int cylNumber;
	static const double PI;
	static int number;
public:
	Cylinder();
	Cylinder(double aRadius);
	Cylinder(double aRadius, double aHeight);
	void setRadius(double aRadius);
	void setHeight(double aHeight);
	double getRadius();
	double getHeight();
	double getDiameter();
	double getCircumference();
	double getArea();
	double getVolume();
	void printDetails();
};
