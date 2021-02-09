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
	name = "";
	carCount = 0;
	brandCount = 0;
	modelCount = 0;
	inventory = nullptr;
}

// the parametrized constructor initilizes the string to
// the parameter value, integers to 0, and inventory to the null pointer
Dealership::Dealership(string aName) {
	name = aName;
	carCount = 0;
	brandCount = 0;
	modelCount = 0;
	inventory = nullptr;
}

// destroys the Dealership object, and all car objects 
// associated with it. Prints the phrase
// "Dealership [name] has been closed"
// Use a cycle to 'destroy' all cars in inventory
Dealership::~Dealership() {
	cout << "Dealership " << name << " has been closed" << endl;
	for (int i = 0; i < carCount; i++) {
		inventory[i]->~Car();
	}
}

// set the dealership's name to the parameter's value
void Dealership::setName(string aName) {
	name = aName;
}

// adds a Car object to the inventory by creating
// a new Car object using the parameters as data 
// fed to the constructor
void Dealership::addCarToInventory(string brand, string model) {
	carCount++;
	Car** temp = inventory;
	inventory = new Car * [carCount];
	for (int i = 0; i < carCount - 1; i++)
		inventory[i] = temp[i];
	inventory[carCount - 1] = new Car(brand, model);
	if (brandFound(brand))
		brandCount++;
	if (modelFound(model))
		modelCount++;
	if (carCount > 1)
		orderInventory();
	if (temp != nullptr)
		delete[] temp;

}

// removes a Car object from the inventory
void Dealership::sellCar(string serial) {
	// first, find if car is in inventory
	if (carFound(serial)) {
		carCount--;
		Car** temp = inventory;
		int index = 0;
		inventory = new Car * [carCount];
		string brand, model;
		for (int i = 0; i < carCount + 1; i++) {
			if (temp[i]->getSerialNumber() == serial) {
				brand = temp[i]->getBrand();
				model = temp[i]->getModel();
				continue;
			}
			else {
				inventory[index] = temp[i];
				index++;
			}
		}
		// are there any cars with the same brand left
		if (brandFound(brand)) {
			brandCount--;
			modelCount--;
		}
		else {
			if (modelFound(model))
				modelCount--;
		}
	}
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
	int smaller = -1;
	for (int i = 0; i < carCount - 1; i++) {
		for (int j = i + 1; j < carCount; j++) {
			if (inventory[i]->getSerialNumber().compare(inventory[j]->getSerialNumber()) > 0)
				smaller = j;
		}
		if (smaller != -1) {
			Car* temp = inventory[i];
			inventory[i] = inventory[smaller];
			inventory[smaller] = temp;
		}
	}
}

// prints the dealer's inventory by brand an model
// format is brand name, model name, model count
// Toyota, Prius, 5 cars
// starts with the phrase "The summary inventory for [name] is:"

// You must also edit the printSummaryInventory method. 
// The output should be in a table-like format. 
// The first line should read "The summary model inventory for [name] is:", 
// followed by the list of brands and models in alphabetical order. 
// Make the brand field 2 spaces longer than the length of the longest brand 
// name and do the same for the model field. 
// For example, if two Toyota Prius vehicles are in inventory, the method would print:
void Dealership::printSummaryInventory() const {
	cout << "The summary model inventory for " << name << " is: " << endl;
	printf("%-13s%-13s%-6s\n", "Brand", "Model", "Count");
	printf("%-13s%-13s%-6s\n", "-----", "-----", "-----");
	for (int i = 0; i < carCount; i++) {
		printf("%-13s%-13s%-6i\n", inventory[i]->getBrand().c_str(), inventory[i]->getModel().c_str(), getModelCount(inventory[i]->getModel()));
	}
	cout << endl;
}

// prints the dealer's detailed inventory in the form
// serial number, brand name, model name
// starts with the phrase "The detailed inventory for [name] is:"
void Dealership::printDetailedInventory() const {
	cout << "The detailed inventory for " << name << " is: " << endl;
	for (int i = 0; i < carCount; i++) {
		cout << inventory[i]->getSerialNumber() << ", " << inventory[i]->getBrand()
			<< ", " << inventory[i]->getModel() << endl;
	}
	cout << endl;
}

// this method checks if a brand name is in inventory
// returns true if brand not found, false otherwise
bool Dealership::brandFound(string aBrand) {
	for (int i = 0; i < carCount; i++) {
		if (inventory[i]->getBrand().compare(aBrand) == 0)
			return false;
	}
	return true;
}

// this method checks if a model name is in inventory
// returns true if model not found, false otherwise
bool Dealership::modelFound(string aModel) {
	for (int i = 0; i < carCount; i++) {
		if (inventory[i]->getModel().compare(aModel) == 0)
			return false;
	}
	return true;
}

// this method searches for a specific car inventory by serial number
// returns true if match found, other returns false
bool Dealership::carFound(string serial) {
	for (int i = 0; i < carCount; i++) {
		if (inventory[i]->getSerialNumber() == serial)
			return true;
	}
	return false;
}
// create a new public method, named printBrandSummary, which has no parameters. 
// The output should be in a table-like format. 
// The first line should read "The summary brand inventory for [name] is:", 
// followed by the list of brands (in alphabetical order) and the count of cars per brand. 
// Make the brand field 2 spaces longer than the length of the longest brand name. 
// For example, if two Toyota vehicles are in inventory, the method would print "Toyota 2".
void Dealership::printBrandSummary() const {
	cout << "The summary brand inventory for " << name << " is: " << endl;
	printf("%-13s%-6s\n", "Brand", "Count");
	printf("%-13s%-6s\n", "-----", "-----");
	for (int i = 0; i < carCount; i++) {
		printf("%-13s%-6i\n", inventory[i]->getBrand().c_str(), getBrandCount(inventory[i]->getBrand()));
	}
	cout << endl;
}

// returns the count of a single brand of cars in inventory
int Dealership::getBrandCount(string aBrand) const {
	int counter = 0;
	for (int i = 0; i < carCount; i++) {
		if (inventory[i]->getBrand().compare(aBrand) == 0)
			counter++;
	}
	return counter;
}

// returns the count of a single model of cars in inventory
int Dealership::getModelCount(string aModel) const {
	int counter = 0;
	for (int i = 0; i < carCount; i++) {
		if (inventory[i]->getModel().compare(aModel) == 0)
			counter++;
	}
	return counter;
}