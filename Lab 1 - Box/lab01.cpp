/*
CECS 2223, Computer Programming II Lab
Winter 2020, Sec. 05
Date: November 18, 2020
Topic : Review
File name : lab01.cpp
Name : EDMARIE RODRIGUEZ MARRERO, ID#132704
Complete the C++ code as required
*/
// write the required include statement
#include "box.h"

// the main function returns an integer value, should be 0
int main() {
	// declare a Box object, named box1, use the default constructor
	Box box1;
	// assign a height of 5, width of 10 and a length of 20 to box1
	box1.setHeight(5);
	box1.setWidth(10);
	box1.setLength(20);
	// declare a Box object, named box2, whose height is 7
	// use the appropriate parametrized constructor
	Box box2;
	box2.setHeight(7);
	// assign a width of 5, length of 10 to box2
	box2.setWidth(5);
	box2.setLength(10);
	// declare a Box object, named box3, whose height is 3 and width is 4
	// use the appropriate parametrized constructor
	Box box3;
	box3.setHeight(3);
	box3.setWidth(4);
	// assign a length of 12 to box3
	box3.setLength(12);
	// declare a Box object, named box4, whose height is 20 and width is 10
	// and length is 5; use the appropriate parametrized constructor
	Box box4;
	box4.setHeight(20);
	box4.setWidth(10);
	box4.setLength(5);

	printf("The boxes created have the following dimensions:\n");
	printf("%7s%7s%7s%7s%6s\n", "HEIGHT", "WIDTH", "LENGTH", "VOLUME", "AREA"); // table headers
	// using printBox method, print the dimensions for each box object
	box1.printBox();
	box2.printBox();
	box3.printBox();
	box4.printBox();
	// write a statement which prints the phrase
	// "Program developed by [YOUR NAME], ID#[YOUR ID NUMBER]"
	// where the square brackets and the text within is substitued with
	// your personal information.
	cout << "Program developed by EDMARIE RODRIGUEZ MARRERO, ID#132704" << endl;
	system("pause"); // for Visual Studio use only
	return 0; // this statement MUST be included at the end of main
}