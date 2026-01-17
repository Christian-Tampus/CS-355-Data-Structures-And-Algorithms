// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #1 Create FizzBuzz Generator Class
// Date due: 01/14/2025
// Description: This program is designed to generate FizzBuzz where the user can change the limits
// add new divisibile numbers & new terms or remove them.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_FizzBuzz
#define H_FizzBuzz
//Dependencies
#include <map>
//Class Declaration
class FizzBuzz
{
	//divisibilityMap stores all numbers that will be checked for divisibility on the FizzBuzz generator, users can add/remove numbers that it can check for divisibility
	private:
		int limit;
		std::map<int, std::string> divisibilityMap;
	public:
		FizzBuzz();
		FizzBuzz(int initialLimit);
		void run();
		void setLimit(int newLimit);
		//add & remove divisibility methods
		void setNewDivisibility(int newDivisibility, std::string newTerm);
		void removeDivisibility(int divisibilityToRemove);
};
#endif