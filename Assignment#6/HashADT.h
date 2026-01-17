// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #6 - Hash Class
// Date due: 03/12/2025
// Description: A program to create a Hash Class
// ---------------------------------------------------------------------------
#include <iostream>
using namespace std;

#include "unorderedLinkedList.h"

template <class elemType>
class hashADT
{
public:

	int getHash(const elemType& key);
		//Function to return the hash value of a given key


	virtual void insert(const elemType& rec) = 0;
		//Function to insert an item in the hash table.
		//The item to be inserted is specified by the parameter rec.
		//	Postcondition: rec is inserted in the proper list (create
		//   the list if not already created).

	virtual void search(const elemType& rec, bool& found) = 0;
		//Function to determine whether the item specified by the
		//parameter rec is in the hash table.
		//Postcondition: If rec is found, found is set to true,
		//found is set to false.


	virtual void remove(const elemType& rec) = 0;
		//Function to remove an item from the hash table.
		//Postcondition: If rec is found in the table it is removed;
		//otherwise, an appropriate error message is displayed.

	virtual void print() const = 0;
		//Function to output the values in the hash table.

	hashADT<elemType>(int size = 101);
		//constructor
		//Postcondition: Create the array HTTable of list pointers;
		//   HTSize = size; and the default array size is 101.

	~hashADT<elemType>();
		//destructor
		//Postcondition: Array HTable and indexStatusList are deleted.

protected:
	unorderedLinkedList<elemType>** HTable;   //pointer to the hash table
	int HTSize;    //maximum size of the hash table
};

//===
template <class elemType>
hashADT<elemType>::hashADT(int size){
	HTSize = size;
	HTable = new unorderedLinkedList<elemType>* [HTSize];
	for(int i=0; i<HTSize; i++){
		HTable[i] = NULL;
	}
}
template <class elemType>
hashADT<elemType>::~hashADT(){
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION START
	// ---------------------------------------------------------------------------
	*/
	/*
	// ---------------------------------------------------------------------------
	// IMPORTANT MODIFICATIONS: Added for loop to delete/deallocate the pointers to linkedLists inside the dynamically allocated HTable array to prevent memory leaks.
	// ---------------------------------------------------------------------------
	*/
	for (int index = 0; index < this->HTSize; index++)
	{
		delete HTable[index];
	};
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION END
	// ---------------------------------------------------------------------------
	*/
    //memory leak?
	delete[] HTable;
	std::cout << "[CRITICALLY IMPORTANT!] [Hash ADT] Deallocated The Hash Table & All The Pointers Inside The Array That Points To Dynamically Allocated Linked Lists!" << std::endl;
}
template <class elemType>
int hashADT<elemType>::getHash(const elemType& key){
	return key % HTSize;
}