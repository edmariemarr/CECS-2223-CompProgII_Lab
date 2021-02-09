/*
* CECS 2223, Computer Programming II Lab
* Winter 2020
* Date: January 20, 2021
* Topic: Lab 6 - Composition
* File name: Car.cpp
*/
#include "Car.h"
#include <string>
// initialize static variable to 0
int Car::count = 0;
// The default constructor initializes strings to "" and adds 1 to count
Car::Car() {
	brand = "";
	model = "";
	serialNumber = "";
	count++;
}

// The parametrized constructor initializes the brand and model fields 
// to the parameter value and adds 1 to count
// calls the method to set the serial number
Car::Car(string aBrand, string aModel) {
	brand = aBrand;
	model = aModel;
	count++;
	setSerialNumber();
}

// destroys a Car object and prints the phrase
// "Car [brand name] [model name], serial number [serial number] has been removed"
Car::~Car() {
	printf("Car %s %s, serial number %s has been removed\n", brand.c_str(), model.c_str(), serialNumber.c_str());
}

// this is a private method which can only be invoked by the object itself
// sets the serial number for each new Car object only if it has none
// the serial number is composed of the first two letters of the brand and model
// with the count value, in three digits, appended at the end.
// for example, if brand is Kia, model is Rio, and count is 1
// the serialnumber would be KiRi001
void Car::setSerialNumber() {
	if (count < 10)
		serialNumber = brand.substr(0, 2) + model.substr(0, 2) + "00" + to_string(count);
	else if (count < 100)
		serialNumber = brand.substr(0, 2) + model.substr(0, 2) + "0" + to_string(count);
	else
		serialNumber = brand.substr(0, 2) + model.substr(0, 2) + to_string(count);
}

// Sets the brand field to the parameter value
void Car::setBrand(string theBrand) {
	brand = theBrand;
	if (!model.empty())
		setSerialNumber();
}

// Sets the model field to the parameter value
void Car::setModel(string theModel) {
	model = theModel;
	if (!brand.empty())
		setSerialNumber();
}

// returns the brand field's value
string Car::getBrand() const {
	return brand;
}

// returns the model field's value
string Car::getModel() const {
	return model;
}

// returns a car's serial number
string Car::getSerialNumber() const {
	return serialNumber;
}

// returns the count of Car objects created
int Car::getCount() const {
	return count;
}

// prints the details about each car in the form
// serial number, brand name, model name
void Car::printCar() const {
	cout << serialNumber << ", " << brand << ", " << model << endl;
}