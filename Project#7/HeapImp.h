// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #7
// Date due: 04/27/30
// Description: A program to do heapify stuff and sortify it too i guess...
// ---------------------------------------------------------------------------
//Dependencies
#ifndef H_HEAPIMP
#define H_HEAPIMP
#include <iostream>
#include "HeapADT.h"
//Class Declaration
class HeapImp : public HeapADT
{
	public:
		HeapImp();
		~HeapImp();
		void loadArray();
		void makeHeap();
		//Heapify Recursive Method
		void heapify(int currentIndex, int currentArraySize);
		void printArray();
		void sort();
		//Sortify Recursive Method
		void sortify(int currentIndex);
	private:
		int* heapArray;
		int arraySize;
};
#endif