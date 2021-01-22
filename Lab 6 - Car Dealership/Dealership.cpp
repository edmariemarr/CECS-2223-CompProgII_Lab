/*
* CECS 2223, Computer Programming II Lab
* Winter 2020
* Date: January 20, 2021
* Topic: Lab 6 - Composition
* File name: Dealership.cpp
*/
#include "Dealership.h"

// the default constructor initilizes strings to ""
// integers to 0, and inventory to the null pointer
Dealership::Dealership() {
	name = " ";
	carCount = 0;
	brandCount = 0;
	modelCount = 0;
	inventory = nullptr;
}

// the parametrized constructor initilizes the string to
// the parameter value, integers to 0, and inventory to the null pointer
Dealership::Dealership(string theName) {
	name = theName;
	carCount = 0;
	brandCount = 0;
	modelCount = 0;
	inventory = nullptr;
}

// destroys the Dealership object, and all car objects 
// associated with it. Prints the phrase
// "Dealership [name] has been closed"
Dealership::~Dealership() {
	cout << "Dealership " << name << " has been closed!" << endl;
	delete[] inventory;
}

// set the dealership's name to the parameter's value
void Dealership::setName(string theName) {
	name = theName;
}

// adds a Car object to the inventory by creating
// a new Car object using the parameters as data 
// fed to the constructor
void Dealership::addCarToInventory(string theBrand, string theModel) {
	Car** temp = inventory;
		carCount++;
		inventory = new Car* [carCount];
		for (int i = 0; i < carCount - 1; i++) {
			inventory[i] = temp[i];
		}
		inventory[carCount - 1] = new Car(theBrand, theModel);
		for (int i = 0; i < carCount; i++) {
			if (inventory[i]->getModel() == theModel) {
				modelCount++;
			}
			if (inventory[i]->getBrand() == theBrand) {
				brandCount++;
			}
		}
		orderInventory();
		delete[] temp;
	}

// removes a Car object from the inventory
void Dealership::sellCar(string theBrand, string theModel) {
	for (int i = 0; i < carCount; i++) {
		if (inventory[i]->getModel() == theModel) {
			modelCount--;
		}
		if (inventory[i]->getBrand() == theBrand) {
			brandCount--;
		}
	}
		Car** temp = inventory;
		inventory = new Car* [--carCount];
		int index = 0;
		for (int i = 0; i < carCount + 1; i++) {
			if (temp[i]->getBrand().compare(theBrand) == 0) {
				continue;
			}
			else {
				inventory[index] = temp[i];
				index++;
			}
		}
		delete[] temp;
		orderInventory();
	}

// returns the count of cars in inventory
int Dealership::getCarCount() const {
	return carCount;
}

// returns the count of a single brand of cars in inventory
int Dealership::getBrandCount() const {
	return brandCount;
}

// returns the count of a single model of cars in inventory
int Dealership::getModelCount() const {
	return modelCount;
}

// orders the inventory by brand name and then by model name
// HINT: can use the serial number value!
void Dealership::orderInventory() {
	if (carCount > 1) {
		int lowIndex = -1;
		for (int i = 0; i < carCount - 1; i++) {
			for (int j = i + 1; j < carCount; j++) {
				if (inventory[i]->getSerialNumber().compare(inventory[j]->getSerialNumber()) > 0)
					lowIndex = j;
			}
			if (lowIndex > -1) { 
				Car* temp = inventory[i];
				inventory[i] = inventory[lowIndex];
				inventory[lowIndex] = temp;
				lowIndex = -1;
			}
		}
	}
}

// prints the dealer's inventory by brand and model
// format is brand name, model name, model count
void Dealership::printSummaryInventory() const {
	cout << "SUMMARY INVENTORY FOR " << name << endl;
	for (int i = 0; i < carCount; i++) {
		cout << inventory[i]->getBrand() << ", " << inventory[i]->getModel() << ", " << modelCount << " cars" << endl;
	}
	cout << endl;
}

// prints the dealer's detailed inventory in the form
// serial number, brand name, model name
void Dealership::printDetailedInventory() const {
	cout << "DETAILED INVENTORY FOR " << name << endl;
	for (int i = 0; i < carCount; i++) {
		cout << inventory[i]->getSerialNumber() << ", " << inventory[i]->getBrand() << ", " << inventory[i]->getModel() << endl;
	}
	cout << endl;
}
