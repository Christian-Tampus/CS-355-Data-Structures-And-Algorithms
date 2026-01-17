// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #1 Create FizzBuzz Generator Class
// Date due: 01/14/2025
// Description: This program is designed to generate FizzBuzz where the user can change the limits
// add new divisibile numbers & new terms or remove them.
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include "FizzBuzz.h"
//Class Definition
/*
// ---------------------------------------------------------------------------
Description: FizzBuzz default constructor
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
FizzBuzz::FizzBuzz()
{
	//set limit to 100 by default, add divisibility 3 & 5 with Fizz & Buzz as the value pair
	this->limit = 100;
	this->divisibilityMap[3] = "Fizz";
	this->divisibilityMap[5] = "Buzz";
};
/*
// ---------------------------------------------------------------------------
Description: FizzBuzz constructor with one parameter (initialLimit)
Incoming Data: initialLimit (Integer)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
FizzBuzz::FizzBuzz(int initialLimit):limit(initialLimit){};
void FizzBuzz::run()
{
	std::cout << "-------------------------" << std::endl;
	//loop from 1 to this->limit
	for (int num = 1; num <= this->limit; num++)
	{
		//variable declarations
		std::string currentTerm = "";
		//loop the map to get the key/value pairs to check the num if it is divisible, if it is, append it to currentTerm
		for (const auto& KVPair : this->divisibilityMap)
		{
			if (num % KVPair.first == 0)
			{
				currentTerm += KVPair.second;	
			};
		};
		//print currentTerm if it is not empty, if it is empty print the num instead
		if (currentTerm != "")
		{
			std::cout << currentTerm << std::endl;
		}
		else
		{
			std::cout << num << std::endl;
		};
	};
	std::cout << "-------------------------" << std::endl;
};
/*
// ---------------------------------------------------------------------------
Description: FizzBuzz setLimit method used to change this->limit to newLimit
Incoming Data: newLimit (Integer)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void FizzBuzz::setLimit(int newLimit)
{
	//first check newLimit if its not less than 1 before allowing it to change this->limit
	if (newLimit >= 1)
	{
		this->limit = newLimit;
		std::cout << "[SYSTEM MESSAGE] Successfully Updated Limit To: " << this->limit << std::endl;
	}
	else
	{
		std::cout << "[SYSTEM ERROR] New Limit Out Of Valid Range! New Limit Must Be >= 1!" << std::endl;	
	};
};
/*
// ---------------------------------------------------------------------------
Description: FizzBuzz setNewDivisibility method is add/change divisibilities applied to the FizzBuzz generator along with a newTerm
Incoming Data: newDivisibility (Integer), newTerm(String)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void FizzBuzz::setNewDivisibility(int newDivisibility, std::string newTerm)
{
	//overwrite or add a new number the generator will be divisible by and the newTerm as its value pair for printing
	this->divisibilityMap[newDivisibility] = newTerm;
	std::cout << "[SYSTEM MESSAGE] Successfully Added New Divisibility: " << newDivisibility << " & New Term: " << newTerm << std::endl; 
};
void FizzBuzz::removeDivisibility(int divisibilityToRemove)
{
	//checks the divisibilityMap to find the divisibility integer/number to remove from the map, prints if it was successfull or not.
	if (this->divisibilityMap.find(divisibilityToRemove) != this->divisibilityMap.end())
	{
		this->divisibilityMap.erase(divisibilityToRemove);
		std::cout << "[SYSTEM MESSAGE] Successfully Removed Divisibility: " << divisibilityToRemove << std::endl;
	}
	else
	{
		std::cout << "[SYSTEM ERROR] Divisibility: " << divisibilityToRemove << " Does Not Exist!" << std::endl;
	};
};