// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #4 - Make A Stack Iterator
// Date due: 02/14/2025
// Description: Stack Iterator that can do a for loop that iterates the entire stack to print out the values inside the stack from top to bottom but does not modify the stack itself.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_STACKADT
#define H_STACKADT
/*
// ---------------------------------------------------------------------------
REFACTORED stackADT Class Declaration
// ---------------------------------------------------------------------------
*/
template <class StackDataType>
class stackADT
{
	public:
		virtual void initializeStack() = 0;
		virtual bool isEmptyStack() const = 0;
		virtual bool isFullStack() const = 0;
		virtual void push(const StackDataType& newItem) = 0;
		virtual StackDataType top() const = 0;
		virtual void pop() = 0;
};
#endif