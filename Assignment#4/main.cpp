// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #4 - AbstractSort
// Date due: 02/09/2025
// Description: This program is an Abstract Sort Class that has a pure virtual method called compare that can be implemented to handle different sort by (increasing or decreasing)
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include "Increasing.h"
#include "Decreasing.h"
//Namespaces
using namespace std;
//Driver
int main()
{
	//Increasing Sort
	std::cout << "Assignment #4" << std::endl;
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	Increasing increasingSort;
	increasingSort.randomFill();
	std::cout << "Increasing (Unsorted): ";
	increasingSort.print();
	increasingSort.sort();
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "Increasing (Sorted): ";
	increasingSort.print();
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	//Decreasing Sort
	Decreasing decreasingSort;
	decreasingSort.randomFill();
	std::cout << "Decreasing (Unsorted): ";
	decreasingSort.print();
	decreasingSort.sort();
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "Decreasing (Sorted): ";
	decreasingSort.print();
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "[SYSTEM MESSAGE] Program Terminated!" << std::endl;
	return 0;
};