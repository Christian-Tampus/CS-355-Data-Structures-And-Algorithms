// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #4 - Make A Stack Iterator
// Date due: 02/14/2025
// Description: Stack Iterator that can do a for loop that iterates the entire stack to print out the values inside the stack from top to bottom but does not modify the stack itself.
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include "myStack.h"
//Namespaces
using namespace std;
//Driver
int main()
{
	stackType<int> stack1;
	stack1.push(99);
	stack1.push(12);
	stack1.pop();
	stack1.push(17);
	stack1.push(25);
	stack1.push(42);
	stack1.push(34);
	stack1.push(13);
	stack1.push(74);
	stack1.push(82);
	stack1.push(59);
	stack1.push(66);
	/*
	1. Create a stackIterator as in: stackIterator<int> it;
	2. Use your stackIterator in a simple for loop here that iterates over the entire stack and prints the stack out
	3. Make use of the overloaded ++ and * to do so
	4. Make sure the stackIterator does not modify the stack itself
	*/
	stackIterator<int> it;
	std::cout << "|------------STACK-TOP-------------|" << std::endl;
	for (it = stack1.begin(); it != stack1.end(); it++)
	{
		std::cout << "|                " << *it << "                |" << std::endl;
		std::cout << "|----------------------------------|" << std::endl;
	};
	std::cout << "|-----------STACK-BOTTOM-----------|" << std::endl;
	std::cout << "[SYSTEM MESSAGE] Program Terminated..." << std::endl;
	return 0;
};