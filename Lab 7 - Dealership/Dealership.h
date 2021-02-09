/*
* CECS 2223, Computer Programming II Lab
* Winter 2020
* Date: January 20, 2021
* Topic: Lab 6 - Composition
* File name: Dealership.h
*/
#pragma once
#include "Car.h"
class Dealership {
private:
	string name;
	Car** inventory;
	int carCount;
	int brandCount;
	int modelCount;
public:
	Dealership();
	Dealership(string);
	~Dealership();
	void setName(string);
	void addCarToInventory(string, string);
	void sellCar(string);
	int getCarCount() const;
	int getBrandCount() const;
	int getModelCount() const;
	void orderInventory();
	void printSummaryInventory() const;
	void printDetailedInventory() const;
	bool brandFound(string);
	bool modelFound(string);
	bool carFound(string);
	void printBrandSummary() const;
	int getBrandCount(string) const;
	int getModelCount(string) const;
};