// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #4 - Make A Stack Iterator
// Date due: 02/14/2025
// Description: Stack Iterator that can do a for loop that iterates the entire stack to print out the values inside the stack from top to bottom but does not modify the stack itself.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_MYSTACK
#define H_MYSTACK
//Dependencies
#include <iostream>
#include <cassert>
#include "stackADT.h"
//Namespaces
using namespace std;
/*
// ---------------------------------------------------------------------------
stackNode<StackDataType> Struct
// ---------------------------------------------------------------------------
*/
template <class StackDataType>
struct stackNode
{
	StackDataType* stackListInfo;
	int currentIndex;
};
/*
// ---------------------------------------------------------------------------
stackIterator Class Declaration
// ---------------------------------------------------------------------------
*/
template <class StackDataType>
class stackIterator
{
	private:
		stackNode<StackDataType> currentStackNode;
	public:
		stackIterator();
		stackIterator(stackNode<StackDataType> newCurrentStack);
		StackDataType operator*();
		stackIterator<StackDataType> operator++(int);
		bool operator!=(const stackIterator<StackDataType>& rightStackIterator) const;
};
/*
// ---------------------------------------------------------------------------
Description: stackIterator<StackDataType> Default Constructor, sets stackNode<StackDataType> currentStackNode stackListInfo to nullptr & currentIndex to 0
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
template <class StackDataType>
stackIterator<StackDataType>::stackIterator()
{
	this->currentStackNode.stackListInfo = nullptr;
	this->currentStackNode.currentIndex = 0;
};
/*
// ---------------------------------------------------------------------------
Description: stackIterator<StackDataType> Constructor with stackNode<StackDataType> newStackNode parameter to set currentStackNode to newStackNode
Incoming Data: stackNode<StackDataType> newStackNode
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
template <class StackDataType>
stackIterator<StackDataType>::stackIterator(stackNode<StackDataType> newStackNode)
{
	this->currentStackNode = newStackNode;
};
/*
// ---------------------------------------------------------------------------
Description: stackIterator<StackDataType> Dereference operator overload to return the current value in the stack at currentIndex
Incoming Data: None
Outgoing Data: StackDataType
// ---------------------------------------------------------------------------
*/
template <class StackDataType>
StackDataType stackIterator<StackDataType>::operator*()
{
	return this->currentStackNode.stackListInfo[this->currentStackNode.currentIndex];
};
/*
// ---------------------------------------------------------------------------
Description: stackIterator<StackDataType> Post-Fix Increment operator overload to decrement the currentIndex starting from the top of the stack to the bottom of the stack then return the actual iterator object, not the pointer to itself (*this)
Incoming Data: None
Outgoing Data: stackIterator<StackDataType>
// ---------------------------------------------------------------------------
*/
template <class StackDataType>
stackIterator<StackDataType> stackIterator<StackDataType>::operator++(int)
{
	this->currentStackNode.currentIndex--;
    return *this;
};
/*
// ---------------------------------------------------------------------------
Description: stackIterator<StackDataType> Not equals operator overloaded to check if current stackIterator does not equal the rightStackIterator and returns the boolean result
Incoming Data: const stackIterator<StackDataType>& rightStackIterator
Outgoing Data: Boolean
// ---------------------------------------------------------------------------
*/
template <class StackDataType>
bool stackIterator<StackDataType>::operator!=(const stackIterator<StackDataType>& rightStackIterator) const
{
	return (this->currentStackNode.currentIndex != rightStackIterator.currentStackNode.currentIndex);	
};
/*
// ---------------------------------------------------------------------------
REFACTORED stackType Class Declaration
// ---------------------------------------------------------------------------
*/
template <class StackDataType>
class stackType : public stackADT<StackDataType>
{
	private:
		int maxStackSize;
		int stackTop;
		StackDataType* list;
		void copyStack(const stackType<StackDataType>& otherStack);
		/*
		// ---------------------------------------------------------------------------
		MODIFICATIONS: Add stackNode<StackDataType> stackList attribute to stackType class so that the stackIterator can iterate over stackType
		// ---------------------------------------------------------------------------
		*/
		stackNode<StackDataType> stackList;
	public:
		void initializeStack();
		bool isEmptyStack() const;
		bool isFullStack() const;
		void push(const StackDataType& newItem);
		StackDataType top() const;
		void pop();
		const stackType<StackDataType>& operator=(const stackType<StackDataType>&);
		stackType(int stackSize = 100);
		stackType(const stackType<StackDataType>& otherStack);
		~stackType();
		/*
		// ---------------------------------------------------------------------------
		MODIFICATIONS: Add begin() & end() method declarations
		// ---------------------------------------------------------------------------
		*/
		stackIterator<StackDataType> begin();
		stackIterator<StackDataType> end();
};
/*
// ---------------------------------------------------------------------------
REFACTORED stackType Class Definition
// ---------------------------------------------------------------------------
*/
template <class StackDataType>
void stackType<StackDataType>::initializeStack()
{
	this->stackTop = 0;
};
template <class StackDataType>
bool stackType<StackDataType>::isEmptyStack() const
{
	return (this->stackTop == 0);	
};
template <class StackDataType>
bool stackType<StackDataType>::isFullStack() const
{
	return (this->stackTop == this->maxStackSize);
};
template <class StackDataType>
void stackType<StackDataType>::push(const StackDataType& newItem)
{
	if (!this->isFullStack())
	{
		this->list[this->stackTop] = newItem;
		this->stackTop++;
	}
	else
	{
		std::cout << "Cannot add to a full stack." << std::endl;	
	};
};
template <class StackDataType>
StackDataType stackType<StackDataType>::top() const
{
	assert(this->stackTop != 0);
	return this->list[this->stackTop - 1];
};
template <class StackDataType>
void stackType<StackDataType>::pop()
{
	if (!this->isEmptyStack())
	{
		this->stackTop--;	
	}
	else
	{
		std::cout << "Cannot remove from an empty stack." << std::endl;
	};
};
template <class StackDataType>
const stackType<StackDataType>& stackType<StackDataType>::operator=(const stackType<StackDataType>& otherStack)
{
	if (this != &otherStack)
	{
		this->copyStack(otherStack);
	};
	return *this;
};  
template <class StackDataType>
stackType<StackDataType>::stackType(int stackSize) 
{
	if (stackSize <= 0)
	{
		std::cout << "Size of the array to hold the stack must be positive." << std::endl;
		std::cout << "Creating an array of size 100." << std::endl;
		this->maxStackSize = 100;		
	}
	else
	{
		this->maxStackSize = stackSize;	
	};
	this->stackTop = 0;
	this->list = new StackDataType[this->maxStackSize];
	/*
	// ---------------------------------------------------------------------------
	MODIFICATIONS: Update stackList's currentIndex & stackListInfo attributes inside the stackType<StackDataType> constructor
	// ---------------------------------------------------------------------------
	*/
	this->stackList.currentIndex = 0;
	this->stackList.stackListInfo = this->list;
};
template <class StackDataType>
stackType<StackDataType>::stackType(const stackType<StackDataType>& otherStack)
{
	this->list = nullptr;
	this->copyStack(otherStack);
	/*
	// ---------------------------------------------------------------------------
	MODIFICATIONS: Update stackList's currentIndex & stackListInfo attributes inside the stackType<StackDataType> copy constructor
	// ---------------------------------------------------------------------------
	*/
	this->stackList.currentIndex = 0;
	this->stackList.stackListInfo = this->list;
};
template <class StackDataType>
stackType<StackDataType>::~stackType()
{
    delete[] this->list;
};
template <class StackDataType>
void stackType<StackDataType>::copyStack(const stackType<StackDataType>& otherStack)
{
	delete[] this->list;
	this->maxStackSize = otherStack.maxStackSize;
    this->stackTop = otherStack.stackTop;
    this->list = new StackDataType[this->maxStackSize];
    for (int index = 0; index < this->stackTop; index++)
    {
		this->list[index] = otherStack.list[index];	
	};
};
/*
// ---------------------------------------------------------------------------
MODIFICATIONS: Add begin() & end() method definitions
// ---------------------------------------------------------------------------
*/
/*
// ---------------------------------------------------------------------------
Description: Creates a stackNode<StackDataType> currentStackList then updates its currentIndex & stackListInfo attributes then uses it as the parameter for stackIterator<StackDataType> currentStackIterator(currentStackList)
Incoming Data: None
Outgoing Data: stackIterator<StackDataType>
// ---------------------------------------------------------------------------
*/
template <class StackDataType>
stackIterator<StackDataType> stackType<StackDataType>::begin()
{
	stackNode<StackDataType> currentStackList;
	currentStackList.currentIndex = this->stackTop - 1;
	currentStackList.stackListInfo = this->stackList.stackListInfo;
	stackIterator<StackDataType> currentStackIterator(currentStackList);
	return currentStackIterator;
};
/*
// ---------------------------------------------------------------------------
Description: Creates a stackNode<StackDataType> currentStackList then updates its currentIndex & stackListInfo attributes then uses it as the parameter for stackIterator<StackDataType> currentStackIterator(currentStackList)
Incoming Data: None
Outgoing Data: stackIterator<StackDataType>
// ---------------------------------------------------------------------------
*/
template <class StackDataType>
stackIterator<StackDataType> stackType<StackDataType>::end()
{
	stackNode<StackDataType> currentStackList;
	currentStackList.currentIndex = -1;
	currentStackList.stackListInfo = this->stackList.stackListInfo;
	stackIterator<StackDataType> currentStackIterator(currentStackList);
	return currentStackIterator;
};
#endif