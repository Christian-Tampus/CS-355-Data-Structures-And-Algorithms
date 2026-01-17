// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #6 - Hash Class
// Date due: 03/12/2025
// Description: A program to create a Hash Class
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include "HashChainType.h"
//Namespaces
using namespace std;
//Driver
int main()
{
	std::cout << "[SYSTEM MESSSAGE] Using 13 Instead Of 10 For The Hash Table Size To Match Sample Run Example!" << std::endl;
	//Modified myHashTable to take 13 instead of 10 to match the sample run example.
	hashChainType<int> myHashTable(13);
	for (int index = 0; index < 100; index++)
	{
		myHashTable.insert(index);
	};
	myHashTable.print();
	bool test = false;
	myHashTable.search(50,test);
	if (test)
	{
		std::cout << "Found 50!" << std::endl;
	}
	else
	{
		std::cout << "50 Not Found!" << std::endl;
	};
	myHashTable.search(105,test);
	if (test)
	{
		std::cout << "Found 105!" << std::endl;
	}
	else
	{
		std::cout << "105 Not Found!" << std::endl;
	};
	myHashTable.insert(105);
	myHashTable.print();
	myHashTable.search(105,test);
	if (test)
	{
		std::cout << "Found 105!" << std::endl;
	}
	else
	{
		std::cout << "105 Not Found!" << std::endl;
	};
	myHashTable.remove(15);
	myHashTable.print();
	myHashTable.search(15,test);
	if (test)
	{
		std::cout << "Found 15!" << std::endl;
	}
	else
	{
		std::cout << "15 Not Found!" << std::endl;
	};
	std::cout << "[SYSTEM MESSAGE] Program Terminated..." << std::endl;
	return 0;
};