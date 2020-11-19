/*
	CECS 2223, Computer Programming II Lab
	Winter 2020, Sec. 05
	Date: November 18, 2020
	Topic: Review
	File name: Box.h
	This file declares a class named Box
	Name: EDMARIE RODRIGUEZ MARRERO, ID#132704
*/

#pragma once
#include <iostream>
using namespace std;

class Box {
private:
	int height;
	int width;
	int length;
public:
	Box();
	Box(int aHeight);
	Box(int aHeight, int aWidth);
	Box(int aHeight, int aWidth, int aLength);
	void setHeight(int aHeight);
	void setWidth(int aWidth);
	void setLength(int aLength);
	int getHeight();
	int getWidth();
	int getLength();
	int getVolume();
	int getArea();
	void printBox();
};