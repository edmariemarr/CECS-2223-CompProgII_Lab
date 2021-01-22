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
	brand = " ";
	model = " ";
	serialNumber = " ";
	count++;
}

// The parametrized constructor initializes the model and brand fields 
// to the parameter value and adds 1 to count
// calls the method to set the serial number
Car::Car(string theBrand, string theModel) {
	brand = theBrand;
	model = theModel;
	count++;
	setSerialNumber();
}

// destroys a Car object and prints the phrase
// "Car [brand name] [model name], serial number [serial number] has been removed"
Car::~Car() {
	cout << "Car " << getBrand() << ", " << getModel() << ", " << getSerialNumber() << " has been removed!" << endl;
}

// this is a private method which can only be invoked by the object itself
// sets the serial number for each new Car object
// the serial number is composed of the first two letters of the brand and model
// with the count value, in three digits, appended at the end.
// for example, if brand is Kia, model is Rio, and count is 1
// the serialnumber would be KiRi001
void Car::setSerialNumber() {
	string brands = brand.substr(0, 2);
	string models = model.substr(0, 2);
	
	if (count < 10) {
		serialNumber = brands + models + "00" + to_string(count);
	}
	else {
		serialNumber = brands + models + "0" + to_string(count);
	}
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
	cout << "CAR DETAILS: " << endl;
	for (int i = 0; i < count; i++) {
		cout << serialNumber << ", " << brand << ", " << model << endl;
	}
	cout << endl;
}
