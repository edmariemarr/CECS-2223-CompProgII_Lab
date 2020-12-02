/*
	CECS 2223, Computer Programming II Lab
	Winter 2020
	Date: December 2, 2020
	Topic: Pointers Review
	This program finds the average of a set of monthly sales.
	It dynamically allocates space for the array holding the sales.
	File name: lab03.cpp
	Complete the C++ code as required
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	// monthSales is a pointer used to point to an array
	// holding monthly sales  
	float* monthSales;
	float total = 0; // total of all sales
	float average = 0; // average of monthly sales
	int numOfSales = 0; // number of sales to be processed 
	int count = 0; // loop counter
	cout << fixed << showpoint << setprecision(2);
	cout << "How many monthly sales will be processed? ";
	cin >> numOfSales;
	while (numOfSales < 1) { // input validation, must be a positive value
		cout << "Error. Input a positive value." << endl;
		cin >> numOfSales;
	}
	// Fill in the code to allocate memory for the array 
	// pointed to by monthSales.
	monthSales = new float[numOfSales];
	// Fill in the condition to determine if memory 
	// has been allocated 
	if (monthSales == NULL) {
		cout << "Error allocating memory!\n";
		return -1;
	}
	cout << "Enter the sales below\n";
	// complete the condition of the for structure
	for (count = 0; count < numOfSales; count++) {
		// Fill in code to show the number of the month
		cout << "Sales for month number " << count + 1 << ": $";
		// Write the code to store the sales for the month
		// into an element of the array
		cin >> monthSales[count];
	}
	// write the code to compute the total
	for (int i = 0; i < numOfSales; i++) {
		total += monthSales[i];
	}
	// Fill in code to find the average
	average = total / numOfSales;
	cout << "Average monthly sale is $" << average << endl;
	// Fill in the code to deallocate memory assigned to the array.
	delete[] monthSales;

	system("pause");
	return 0;
}