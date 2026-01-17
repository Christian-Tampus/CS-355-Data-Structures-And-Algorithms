// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #8
// Date due: 04/13/2025
// Description: A program to determine the Kth statistic in any given list size and any randomly sorted list
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
//Namespaces
using namespace std;
//Function Declarations
void printList(int inputArray[], int inputArraySize);
int kStat(int inputArray[], int inputArraySize, int kval, int recursiveDepth = 1);
int kStatRec(std::vector<int> inputVec, int kval, int recursiveDepth);
//Driver
int main()
{
	//Generate random array size & fill array with random values from 1 to 100
	std::srand(std::time(0));
	int inputArraySize = (std::rand() % 25) + 1;
	int inputArray[inputArraySize];
	for (int index = 0; index < inputArraySize; index++)
	{
		inputArray[index] = std::rand() % 100;
	};
	std::cout << "[SYSTEM MESSAGE] Here Is Your Random List Of Numbers!" << std::endl;
	printList(inputArray,inputArraySize);
	int choice;
	int kval;
	do
	{
		//Allow the user to continue to find the Kth statistic in the randomly generated array until they choose to quit the program
		std::cout << std::endl << std::endl;
		std::cout << "Choose An Option From The Following List." << std::endl;
		std::cout << "Selection: " << std::endl;
		std::cout << "\t 0: Quit" << std::endl;
		std::cout << "\t 1: Find A Kth Statistic" << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			std::cout << "Enter An Integer Value K." << std::endl;
			std::cin >> kval;
			std::cout << std::endl << std::endl;
			printList(inputArray,inputArraySize);
			std::cout << std::endl << std::endl;
			std::cout << "The " << kval << "th Order Statistic Is:" << std::endl;
			std::cout << kStat(inputArray, inputArraySize, kval - 1) << std::endl;
			std::cout << "--------------------------------------------------" << std::endl;
		};
	}while (choice != 0);
	std::cout << "[SYSTEM MESSAGE] Program Terminated..." << std::endl;
	return 0;
};
//Function Definitions
/*
// ---------------------------------------------------------------------------
Description: void printList(int inputArray[], int inputArraySize), prints the inputArray in unsorted, sorted list versions along with the kth index list
Incoming Data: inputArray (Integer Array), inputArraySize (Integer)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void printList(int inputArray[], int inputArraySize)
{
	//Display the randomly generated list size
	std::cout << "Randomly Generated List Size (1 To 25): " << inputArraySize << std::endl;
	//Copy the values of the input array into a vector then & print the unsorted list version of the inputArray
	std::cout << "List Unsorted:  [";
	int copyInputArray[inputArraySize];
	for (int index = 0; index < inputArraySize; index++)
	{
		std::cout << inputArray[index] << (index < inputArraySize - 1 ? "," : "");
		copyInputArray[index] = inputArray[index];
	};
	std::cout << "]" << std::endl;
	//Print the sorted list version of the input array
	std::cout << "List Sorted:    [";
	for (int index1 = 0; index1 < inputArraySize; index1++)
	{
		int comparisonIndex = index1;
		for (int index2 = index1 + 1; index2 < inputArraySize; index2++)
		{
			if (copyInputArray[index2] < copyInputArray[comparisonIndex])
			{
				comparisonIndex = index2;
			};
		};
		int temp = copyInputArray[index1];
		copyInputArray[index1] = copyInputArray[comparisonIndex];
		copyInputArray[comparisonIndex] = temp;
		std::cout << copyInputArray[index1] << (index1 < inputArraySize - 1 ? "," : "");
	};
	std::cout << "]" << std::endl;
	//Print the Kth index value list associated with the sorted list version of the inputArray
	std::cout << "List Kth Index: [";
	for (int index = 0; index < inputArraySize; index++)
	{
		if (copyInputArray[index] > 9 && index + 1 <= 9)
		{
			std::cout << "0" << index + 1 << (index < inputArraySize - 1 ? "," : "");
		}
		else
		{
			std::cout << index + 1 << (index < inputArraySize - 1 ? "," : "");
		};
	};
	std::cout << "]" << std::endl;
};
/*
// ---------------------------------------------------------------------------
Description: int kStat(int inputArray[], int inputArraySize, int kval, int recursiveDepth), kStat function that first checks if kval is a valid input then copies the values into a vector and calls recursive helper function kStatRec to find the Kth statistic
Incoming Data: inputArray (Integer Array), inputArraySize (Integer), recursiveDepth (Integer)
Outgoing Data: -999999999 OR kStatRec(inputVec, kval, recursiveDepth) (Integer)
// ---------------------------------------------------------------------------
*/
int kStat(int inputArray[], int inputArraySize, int kval, int recursiveDepth)
{
	if (kval + 1 <= 0 || kval + 1 > inputArraySize)
	{
		//return -999999999 if the kval + 1 Offset is not bounded by 1 to n, where 'n' is the size of the input array (Inclusive)
		std::cout << "The Kth Input Value Is Not Valid Because It Must Be In Between 1 And " << inputArraySize << " (Inclusive)!" << std::endl;
		return -999999999;
	};
	//Copy the inputArray values and append them to the inputVec and call the kStatRec() recursive helper function then return the result
	std::vector<int> inputVec;
	for (int index = 0; index < inputArraySize; index++)
	{
		inputVec.push_back(inputArray[index]);
	};
	return kStatRec(inputVec, kval, recursiveDepth);
};
/*
// ---------------------------------------------------------------------------
Description: int kStatRec(std::vector<int> inputVec, int kval, int recursiveDepth), recursive helper function to find the Kth statistic in a given list
Incoming Data: inputVec (Integer Vector), kval (Integer), recursiveDepth (Integer)
Outgoing Data: pivotValue Or inputVec[0] (Integer)
// ---------------------------------------------------------------------------
*/
int kStatRec(std::vector<int> inputVec, int kval, int recursiveDepth)
{
	//Display the recursiveDepth call
	std::cout << "kStatRec() Recursive Call (Depth): " << recursiveDepth << std::endl;
	if (inputVec.size() <= 1)
	{
		//Return the first item in vector or -999999999 if the vector is empty.
		return (inputVec.size() == 1 ? inputVec[0] : -999999999);
	};
	//Get random pivot value from inputVec
	std::srand(std::time(0));
	int randomPivotIndex = std::rand() % inputVec.size();
	int pivotValue = inputVec[randomPivotIndex];
	//Initialize Partition Vectors
	std::vector<int> smallerPartitionVec;
	std::vector<int> pivotPartitionVec;
	std::vector<int> largerPartitionVec;
	//Iterate inputVec to append the values to the appropriate partitions vectors
	for (int index = 0; index < inputVec.size(); index++)
	{
		if (inputVec[index] < pivotValue)
		{
			smallerPartitionVec.push_back(inputVec[index]);
		}
		else if (inputVec[index] > pivotValue)
		{
			largerPartitionVec.push_back(inputVec[index]);
		}
		else
		{
			pivotPartitionVec.push_back(inputVec[index]);
		};
	};
	//Display the partitions for each recursive call
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "Input Vector: [";
	for (int index = 0; index < inputVec.size(); index++)
	{
		std::cout << inputVec[index] << (index + 1 == inputVec.size() ? "" : ",");
	};
	std::cout << "]" << std::endl;
	std::cout << "Small Partition (< Pivot): [";
	for (int index = 0; index < smallerPartitionVec.size(); index++)
	{
		std::cout << smallerPartitionVec[index] << (index + 1 == smallerPartitionVec.size() ? "" : ",");
	};
	std::cout << "]" << std::endl;
	std::cout << "Pivot Partition (== Pivot): [";
	for (int index = 0; index < pivotPartitionVec.size(); index++)
	{
		std::cout << pivotPartitionVec[index] << (index + 1 == pivotPartitionVec.size() ? "" : ",");
	};
	std::cout << "]" << std::endl;
	std::cout << "Large Partition (> Pivot): [";
	for (int index = 0; index < largerPartitionVec.size(); index++)
	{
		std::cout << largerPartitionVec[index] << (index + 1 == largerPartitionVec.size() ? "" : ",");
	};
	std::cout << "]" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	//If kval + 1 offset is less than or equal to the smaller partition vector's size then it must be inside the smaller partition and therefore must do a recursive call to search the smaller partition vector
	if (kval + 1 <= smallerPartitionVec.size())
	{
		return kStatRec(smallerPartitionVec, kval, recursiveDepth + 1);
	}
	//If kval + 1 offset is greater than the smaller partition vector but less than or equal to the smaller partition vector size plus the pivot partition vector size then it must be one of the pivot values (which are all the same) and therefore simply return the pivot value
	else if (kval + 1 <= smallerPartitionVec.size() + pivotPartitionVec.size())
	{
		return pivotValue;
	}
	//If kval + 1 Offset is greater than the smaller partition vector plus the pivoto partition vector size then it must be inside the larger partition and therefore must do a recursive call to search the larger partition vector
	else
	{
		return kStatRec(largerPartitionVec, kval - smallerPartitionVec.size() - pivotPartitionVec.size(), recursiveDepth + 1);
	};
};