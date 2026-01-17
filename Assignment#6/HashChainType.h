// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #6 - Hash Class
// Date due: 03/12/2025
// Description: A program to create a Hash Class
// ---------------------------------------------------------------------------
#ifndef H_HashChainType
#define H_HashChainType
#include "HashADT.h"
using namespace std;
template <class elemType>
class hashChainType: public hashADT<elemType>
{
	public:
		hashChainType(int size = 101):hashADT<elemType>(size){};
		void insert(const elemType& rec);
		void search(const elemType& rec, bool& found);
		void remove(const elemType& rec);
		void print() const;
};
template <class elemType>
void hashChainType<elemType>::insert(const elemType& rec)
{
	//Function to insert an item in the hash table.
	//The item to be inserted is specified by the parameter rec.
	//Postcondition: rec is inserted in the proper list (create
	//the list if not already created).
	//WRITE CODE::insert into the hash table
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION START
	// ---------------------------------------------------------------------------
	*/
	int hashValueIndex = hashADT<elemType>::getHash(rec);
	if (hashADT<elemType>::HTable[hashValueIndex] == nullptr)
	{
		hashADT<elemType>::HTable[hashValueIndex] = new unorderedLinkedList<elemType>;
	};
	hashADT<elemType>::HTable[hashValueIndex]->insertLast(rec);
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION END
	// ---------------------------------------------------------------------------
	*/
};
template <class elemType>
void hashChainType<elemType>::search(const elemType& rec, bool& found)
{
	//Function to determine whether the item specified by the
	//parameter rec is in the hash table.
	//Postcondition: If rec is found, found is set to true,
	//found is set to false.
	//WRITE CODE:: search for an item in the hash table
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION START
	// ---------------------------------------------------------------------------
	*/
	found = false;
	int hashValueIndex = hashADT<elemType>::getHash(rec);
	if (hashADT<elemType>::HTable[hashValueIndex] != nullptr)
	{
		if (hashADT<elemType>::HTable[hashValueIndex]->search(rec))
		{
			found = true;
		};
	};
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION END
	// ---------------------------------------------------------------------------
	*/
};
template <class elemType>
void hashChainType<elemType>::remove(const elemType& rec)
{
	//Function to remove an item from the hash table.
	//Postcondition: If rec is found in the table it is removed;
	//otherwise, an appropriate error message is displayed.
	//WRITE CODE:: remove an item from the hash table
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION START
	// ---------------------------------------------------------------------------
	*/
	int hashValueIndex = hashADT<elemType>::getHash(rec);
	if (hashADT<elemType>::HTable[hashValueIndex] != nullptr)
	{
		if (hashADT<elemType>::HTable[hashValueIndex]->search(rec))
		{
			hashADT<elemType>::HTable[hashValueIndex]->deleteNode(rec);
			return;
		};
	};
	std::cout << "[HASH TABLE] Unsuccessfully Removed Item: " << rec << "!" << std::endl;
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION END
	// ---------------------------------------------------------------------------
	*/
};
template <class elemType>
void hashChainType<elemType>::print() const
{
	//Function to output the values in the hash table.
	//WRITE CODE:: output the values in the hash table.
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION START
	// ---------------------------------------------------------------------------
	*/
	for (int index = 0; index < hashADT<elemType>::HTSize; index++)
	{
		if (hashADT<elemType>::HTable[index] != nullptr)
		{
			hashADT<elemType>::HTable[index]->print();
		};
		std::cout << std::endl;
	};
	/*
	// ---------------------------------------------------------------------------
	// CODE IMPLEMENTATION END
	// ---------------------------------------------------------------------------
	*/
};
#endif