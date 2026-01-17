// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #7
// Date due: 04/27/30
// Description: A program to do heapify stuff and sortify it too i guess...
// ---------------------------------------------------------------------------
//Dependencies
#include <fstream>
#include <string>
#include "HeapImp.h"
/*
// ---------------------------------------------------------------------------
Description: HeapImp::HeapImp(), HeapImp default constructor, sets heapArray to nullptr and arraySize to 0
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
HeapImp::HeapImp()
{
	this->heapArray = nullptr;
	this->arraySize = 0;
};
/*
// ---------------------------------------------------------------------------
Description: HeapImp::~HeapImp(), deallocates heapArray and sets it to nullptr, arraySize set to 0
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
HeapImp::~HeapImp()
{
	delete[] this->heapArray;
	this->heapArray = nullptr;
	this->arraySize = 0;
};
/*
// ---------------------------------------------------------------------------
Description: void HeapImp::loadArray(), loads data from a text file that is obtained from the user's input
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void HeapImp::loadArray()
{
	std::ifstream inputFile;
	std::string fileName;
	std::cout << "[SYSTEM MESSAGE] Please Enter The Name Of The File You Wish To Load The Array From..." << std::endl;
	std::cout << "[SYSTEM MESSAGE] File Name User Input: ";
	std::getline(std::cin, fileName);
	inputFile.open(fileName);
	if (inputFile)
	{
		inputFile >> this->arraySize;
		this->heapArray = new int[this->arraySize];
		for (int index = 0; index < this->arraySize; index++)
		{
			inputFile >> this->heapArray[index];
		};
	}
	else
	{
		std::cout << "[SYSTEM ERROR] Failed To Open File: " << fileName << "!" << std::endl;
	};
	inputFile.close();
};
/*
// ---------------------------------------------------------------------------
Description: void HeapImp::makeHeap(), calls heapify recursive method inside a for loop going from last to first node with children
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void HeapImp::makeHeap()
{
	int lastNonLeafNodeIndex = (this->arraySize / 2) - 1;
	for (int index = lastNonLeafNodeIndex; index >= 0; index--)
	{
		this->heapify(index, this->arraySize);
	};
};
/*
// ---------------------------------------------------------------------------
Description: void HeapImp::heapify(int currentIndex, int currentArraySize), recursively heapifies the current node (max heap)
Incoming Data: currentIndex (Integer), currentArraySize (Integer)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void HeapImp::heapify(int currentIndex, int currentArraySize)
{
	int offset = 1;
	int leftChildIndex = (2 * (currentIndex + offset)) - 1;
	int rightChildIndex = (2 * (currentIndex + offset));
	int maxChildValue;
	int maxChildIndex = -1;
	if (leftChildIndex < currentArraySize && this->heapArray[leftChildIndex] > this->heapArray[currentIndex])
	{
		maxChildValue = this->heapArray[leftChildIndex];
		maxChildIndex = leftChildIndex;
	};
	if (rightChildIndex < currentArraySize)
	{
		if (maxChildIndex != -1 && this->heapArray[rightChildIndex] > maxChildValue || maxChildIndex == -1 && this->heapArray[rightChildIndex] > this->heapArray[currentIndex])
		{
			maxChildValue = this->heapArray[maxChildIndex];
			maxChildIndex = maxChildIndex;
		};
	};
	if (maxChildIndex != -1)
	{
		int temp = this->heapArray[currentIndex];
		this->heapArray[currentIndex] = this->heapArray[maxChildIndex];
		this->heapArray[maxChildIndex] = temp;
		this->heapify(maxChildIndex,currentArraySize);
	};
};
/*
// ---------------------------------------------------------------------------
Description: void HeapImp::printArray(), prints the heapArray in [n,n+1,n+2,...,n-1,n] format where 'n' is the current index in the heapArray and 'n' starts at 0
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void HeapImp::printArray()
{
	if (this->arraySize == 0)
	{
		std::cout << "[SYSTEM ERROR] The Heap Array Is Empty!" << std::endl;
	}
	else
	{
		std::cout << "[SYSTEM MESSAGE] Heap Array: [";
		for (int index = 0; index < this->arraySize; index++)
		{
			std::cout << this->heapArray[index] << (index + 1 < this->arraySize ? "," : "");
		};
		std::cout << "]" << std::endl;
	};
};
/*
// ---------------------------------------------------------------------------
Description: void HeapImp::sort(), calls the sortify recursive method
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void HeapImp::sort()
{
	this->sortify(this->arraySize - 1);
};
/*
// ---------------------------------------------------------------------------
Description: void HeapImp::sortify(int currentIndex), first swaps the first and last index of the current sub heap of the heapArray then heapifies the 'root' or index 0 to push that value down and get the largest value of the heap to the top, it then recursively calls sortify until it meets the base case
Incoming Data: currentIndex (Integer)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void HeapImp::sortify(int currentIndex)
{
	if (currentIndex <= 0)
	{
		return;	
	};
	int temp = this->heapArray[currentIndex];
	this->heapArray[currentIndex] = this->heapArray[0];
	this->heapArray[0] = temp;
	this->heapify(0, currentIndex);
	this->sortify(currentIndex - 1);
};