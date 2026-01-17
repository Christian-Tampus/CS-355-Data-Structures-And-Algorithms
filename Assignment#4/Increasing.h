// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #4 - AbstractSort
// Date due: 02/09/2025
// Description: This program is an Abstract Sort Class that has a pure virtual method called compare that can be implemented to handle different sort by (increasing or decreasing)
// ---------------------------------------------------------------------------
//Headers
#ifndef H_INCREASING
#define H_INCREASING
//Dependencies
#include "AbstractSortADT.h"
//Class Declaration
class Increasing : public AbstractSortADT
{
	public:
		Increasing();
		~Increasing();
		bool compare(int, int) override;
};
#endif