// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #7
// Date due: 04/27/30
// Description: A program to do heapify stuff and sortify it too i guess...
// ---------------------------------------------------------------------------
#include <iostream>
#include "HeapImp.h"
using namespace std;
int main()
{
	HeapImp myHeap;
    myHeap.printArray();
    myHeap.loadArray();
    myHeap.printArray();
    myHeap.makeHeap();
    myHeap.printArray();
    myHeap.sort();
    myHeap.printArray();
    return 0;
};