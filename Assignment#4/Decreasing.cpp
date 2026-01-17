// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #4 - AbstractSort
// Date due: 02/09/2025
// Description: This program is an Abstract Sort Class that has a pure virtual method called compare that can be implemented to handle different sort by (increasing or decreasing)
// ---------------------------------------------------------------------------
//Dependencies
#include "Decreasing.h"
/*
// ---------------------------------------------------------------------------
Description: Decreasing::Decreasing(), Decreasing Constructor
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
Decreasing::Decreasing(){};
/*
// ---------------------------------------------------------------------------
Description: Decreasing::~Decreasing(), Decreasing Destructor
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
Decreasing::~Decreasing(){};
/*
// ---------------------------------------------------------------------------
Description: Decreasing::compare(int inputNum1, int inputNum2), returns if inputNum1 is less than inputNum2
Incoming Data: inputNum1 (Integer), inputNum2 (Integer)
Outgoing Data: inputNum1 < inputNum2 (Boolean)
// ---------------------------------------------------------------------------
*/
bool Decreasing::compare(int inputNum1, int inputNum2)
{
	return inputNum1 > inputNum2;
};