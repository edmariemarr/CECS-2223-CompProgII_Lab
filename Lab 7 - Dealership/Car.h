/*
* CECS 2223, Computer Programming II Lab
* Winter 2020
* Date: January 20, 2021
* Topic: Lab 6 - Composition
* File name: Car.h
*/
#pragma once
#include <iostream>
using namespace std;
class Car {
private:
	string brand;
	string model;
	string serialNumber;
	static int count;
	void setSerialNumber();
public:
	Car();
	Car(string, string);
	~Car();
	void setBrand(string);
	void setModel(string);
	string getBrand() const;
	string getModel() const;
	string getSerialNumber() const;
	int getCount() const;
	void printCar() const;
};