/*
* CECS 2223, Computer Programming II Lab
* Winter 2020
* Date: January 27, 2021
* Topic: Lab 7 - Composition
* File name: lab07.cpp
*/
// which include statement is required?
#include "Dealership.h"

int main() {
	// create a Dealership object named PUPR Auto Sales
	Dealership dealer("PUPR Auto Sales");
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
	dealer.addCarToInventory("Mitsubishi", "Mirage");
	dealer.printDetailedInventory();
	dealer.addCarToInventory("Toyota", "Yaris");
	// call the method to print the summary brand inventory
	dealer.printBrandSummary();
	// call the method to print the summary inventory
	dealer.printSummaryInventory();
	// sell three cars, calling the methods to print the
	// summary brand and summary inventory after each car is sold
	dealer.sellCar("HyPa001");
	dealer.sellCar("ToCo002");
	dealer.sellCar("MiMi003");
	// call the method to print the detailed inventory
	dealer.printDetailedInventory();

	system("pause");
	return 0;
}