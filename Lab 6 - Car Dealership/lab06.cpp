/*
* CECS 2223, Computer Programming II Lab
* Winter 2020
* Date: January 20, 2021
* Topic: Lab 6 - Composition
* File name: lab06.cpp
*/
// which include statement is required?
#include "Dealership.h"
#include "Car.h"
int main() {
	// create a Dealership object named Poli Auto Sales
	Dealership dealer("Poli Auto Sales");
	// add 10 cars to the inventory, calling the method
	// to print the detailed inventory after each car is added
	dealer.addCarToInventory("Hyundai", "Palisade");
	dealer.printDetailedInventory();
	dealer.addCarToInventory("Toyota", "Corolla");
	dealer.printDetailedInventory();
	dealer.addCarToInventory("Mitsubishi", "Mirage");
	dealer.printDetailedInventory();
	dealer.addCarToInventory("Toyota", "Yaris");
	dealer.printDetailedInventory();
	dealer.addCarToInventory("Tesla", "Model S");
	dealer.printDetailedInventory();
	dealer.addCarToInventory("Nissan", "Rogue");
	dealer.printDetailedInventory();
	dealer.addCarToInventory("Jeep", "Compass");
	dealer.printDetailedInventory();
	dealer.addCarToInventory("Honda", "Accord");
	dealer.printDetailedInventory();
	dealer.addCarToInventory("Ford", "Escape");
	dealer.printDetailedInventory();
	dealer.addCarToInventory("Kia", "Soul");
	dealer.printDetailedInventory();
	// call the method to print the summary inventory
	dealer.printSummaryInventory();
	// sell three cars, calling the method to print the
	// summary inventory after each car is sold
	dealer.sellCar("Ford", "Escape");
	dealer.printSummaryInventory();
	dealer.sellCar("Honda", "Accord");
	dealer.printSummaryInventory();
	dealer.sellCar("Kia", "Soul");
	dealer.printSummaryInventory();
	// call the method to print the detailed inventory
	dealer.printDetailedInventory();

	system("pause");
	return 0;
}
