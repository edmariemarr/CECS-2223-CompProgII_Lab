/*
* CECS 2223, Computer Programming II Lab
* Winter 2020
* Date: February 10, 2021
* Lab 8
* File name: Circle.h
* You MUST define the class in Circle.cpp
*/
#pragma once
class Circle {
private:
	double radius;
public:
	Circle();
	Circle(double);
	void setRadius(double);
	double getRadius() const;
	double getArea() const;
	static const double pi;
};