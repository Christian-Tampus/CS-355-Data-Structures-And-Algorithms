// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #4 - AbstractSort
// Date due: 02/09/2025
// Description: This program is an Abstract Sort Class that has a pure virtual method called compare that can be implemented to handle different sort by (increasing or decreasing)
// ---------------------------------------------------------------------------
//Dependencies
#include "AbstractSortADT.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
/*
// ---------------------------------------------------------------------------
Description: AbstractSortADT::AbstractSortADT(), AbstractSortADT Constructor that sets arraySize to 10 then sets abstractSortADTArray to a dynamically allocated integer array of size 10 then finally sets the random number generator seed
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
AbstractSortADT::AbstractSortADT()
{
	this->arraySize = 10;
	this->abstractSortADTArray = new int[this->arraySize];
	std::srand(std::time(0));
};
/*
// ---------------------------------------------------------------------------
Description: AbstractSortADT::~AbstractSortADT(), AbstractSortADT Destructor that deallocates the abstractSortADTArray and sets it to nullptr
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
AbstractSortADT::~AbstractSortADT()
{
	delete[] this->abstractSortADTArray;
	this->abstractSortADTArray = nullptr;
};
/*
// ---------------------------------------------------------------------------
Description: AbstractSortADT::randomFill(), fills the entire abstractSortADTArray with a random integer from 1 to 100 (inclusive)
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void AbstractSortADT::randomFill()
{
	int maxNum = 100;
	int offset = 1;
	for (int index = 0; index < this->arraySize; index++)
	{
		this->abstractSortADTArray[index] = (std::rand() % maxNum) + offset;
	};
};
/*
// ---------------------------------------------------------------------------
Description: AbstractSortADT::print(), prints all contents of the abstractSortADTArray in the format [_,_,_,...] where '_' is an integer
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void AbstractSortADT::print()
{
	int offset = 1;
	std::cout << "[";
	for (int index = 0; index < this->arraySize; index++)
	{
		std::cout << this->abstractSortADTArray[index];
		if (index < this->arraySize - offset)
		{
			std::cout << ",";
		};
	};
	std::cout << "]" << std::endl;
};
/*
// ---------------------------------------------------------------------------
Description: AbstractSortADT::sort(), sorts the array using the bubble sort algorithm O(n^2) and uses the pure virtual method compare(int, int) to decide to swap the values or not
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void AbstractSortADT::sort()
{
	int offset = 1;
	for (int index1 = 0; index1 < this->arraySize; index1++)
	{
		for (int index2 = this->arraySize - offset; index2 > index1; index2--)
		{
			if (this->compare(this->abstractSortADTArray[index2],this->abstractSortADTArray[index2 - offset]))
			{
				int temp = this->abstractSortADTArray[index2];
				this->abstractSortADTArray[index2] = this->abstractSortADTArray[index2 - offset];
				this->abstractSortADTArray[index2 - offset] = temp;
			};
		};
	};
};