// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #7
// Date due: 04/27/30
// Description: A program to do heapify stuff and sortify it too i guess...
// ---------------------------------------------------------------------------
#ifndef H_HEAPADT
#define H_HEAPADT
class HeapADT
{
	public:
		virtual void loadArray() = 0;
		virtual void makeHeap() = 0;
		virtual void printArray() = 0;
		virtual void sort() = 0;
};
#endif