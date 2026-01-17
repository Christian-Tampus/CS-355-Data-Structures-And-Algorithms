// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #4 - AbstractSort
// Date due: 02/09/2025
// Description: This program is an Abstract Sort Class that has a pure virtual method called compare that can be implemented to handle different sort by (increasing or decreasing)
// ---------------------------------------------------------------------------
//Headers
#ifndef H_ABSTRACTSORTADT
#define H_ABSTRACTSORTADT
//Class Declaration
class AbstractSortADT
{
	private:
		int* abstractSortADTArray;
		int arraySize;
	public:
		AbstractSortADT();
		~AbstractSortADT();
		void randomFill();
		void print();
		virtual bool compare(int, int) = 0;
		void sort();
};
#endif