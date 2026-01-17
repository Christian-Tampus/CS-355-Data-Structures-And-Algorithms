// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #5 - Sorting Analysis
// Date due: 03/05/2025
// Description: This program sorts 4 integer arrays using bubble sort, selection sort, insertion sort & merge sort and displays the number of comparisons for each sorting algorithm
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include <ctime>
#include <vector>
//Namespaces
using namespace std;
//Function Declarations
int bubbleSort(int inputArray[], int inputArraySize);
int selectionSort(int inputArray[], int inputArraySize);
int insertionSort(int inputArray[], int inputArraySize);
std::vector<int> mergeSort(std::vector<int> inputVector, int& comparisons);
std::vector<int> merger(std::vector<int> leftVector, std::vector<int> rightVector, int& comparisons);
//Driver
int main()
{
	std::cout << "[SYSTEM MESSAGE] Sorting Algorithm Analysis" << std::endl;
	std::srand(std::time(0));
	int listSize = 5000;
	int list1[listSize] = {};
	int list2[listSize] = {};
	int list3[listSize] = {};
	int mergeSortComparisons = 0;
	std::vector<int> list4(listSize);
	for (int index = 0; index < listSize; index++)
	{
		int randomNumber = std::rand() % 10000 + 1;
		list1[index] = randomNumber;
		list2[index] = randomNumber;
		list3[index] = randomNumber;
		list4[index] = randomNumber;
	};
	std::cout << "List 1 Bubble Sort Comparisons: " << bubbleSort(list1, listSize) << std::endl;
	std::cout << "List 2 Selection Sort Comparisons: " << selectionSort(list2, listSize) << std::endl;
	std::cout << "List 3 Insertion Sort Comparisons: " << insertionSort(list3, listSize) << std::endl;
	list4 = mergeSort(list4, mergeSortComparisons);
	std::cout << "List 4 Merge Sort Comparisons: " << mergeSortComparisons << std::endl;
	std::cout << "[SYSTEM MESSAGE] Program Terminated..." << std::endl;
	return 0;
};
//Function Definitions
/*
// ---------------------------------------------------------------------------
Description: Sorts an integer array using bubble sort with a time complexity of Big O(n^2).
Incoming Data: inputArray (Integer Array), inputArraySize (Integer)
Outgoing Data: comparisons (Integer)
// ---------------------------------------------------------------------------
*/
int bubbleSort(int inputArray[], int inputArraySize)
{
	/*
	Bubble Sort is a Big O(n^2) quadtratic time complexity algorithm because it has a nested for loop which is 'rounded'
	up to n^2 because the algorithm iterates through the array once then has to iterate it again minus the area that was
	already sorted thus n * n or (n^2)
	since n = 5000 for this example
	n^2 = 5000 * 5000 = 25,000,000 comparisons
	however since it does not actually iterate through the entire array input after it has finished sorting an item
	and since it keeps reducing the number of actual interations as the number of sorted items increases
	the worse case scenario is actually about [(n - 1) * n] / 2
	which is [(5000 - 1) * 5000] / 2 = 12,497,500 comparisons
	*/
	//Time Complexity O(1)
	int comparisons = 0;
	//Time Complexity O(n)
	for (int index1 = 0; index1 < inputArraySize; index1++)
	{
		//Time Complexity O(n), This for loop causes the total time complexity to be O(n^2)
		for (int index2 = inputArraySize - 1; index2 > index1; index2--)
		{
			//Time Complexity O(1)
			comparisons++;
			//Time Complexity O(1)
			if (inputArray[index2] < inputArray[index2 - 1])
			{
				//Time Complexity O(1)
				int temp = inputArray[index2];
				inputArray[index2] = inputArray[index2 - 1];
				inputArray[index2 - 1] = temp;	
			};
		};
	};
	//Time Complexity O(1)
	return comparisons;
};
/*
// ---------------------------------------------------------------------------
Description: Sorts an integer array using selection sort with a time complexity of Big O(n^2).
Incoming Data: inputArray (Integer Array), inputArraySize (Integer)
Outgoing Data: comparisons (Integer)
// ---------------------------------------------------------------------------
*/
int selectionSort(int inputArray[], int inputArraySize)
{
	/*
	Selection Sort is a Big O(n^2) quadtratic time complexity algorithm because it has a nested for loop which is 'rounded'
	up to n^2 because the algorithm iterates through the array once then has to iterate it again minus the area that was
	already sorted thus n * n or (n^2)
	since n = 5000 for this example
	n^2 = 5000 * 5000 = 25,000,000 comparisons
	however since it does not actually iterate through the entire array input after it has finished sorting an item
	and since it keeps reducing the number of actual interations as the number of sorted items increases
	the worse case scenario is actually about [(n - 1) * n] / 2
	which is [(5000 - 1) * 5000] / 2 = 12,497,500 comparisons
	*/
	//Time Complexity O(1)
	int comparisons = 0;
	//Time Complexity O(n)
	for (int index1 = 0; index1 < inputArraySize; index1++)
	{
		//Time Complexity O(1)
		int comparisonIndex = index1;
		//Time Complexity O(n), This for loop causes the total time complexity to be O(n^2)
		for (int index2 = index1 + 1; index2 < inputArraySize; index2++)
		{
			//Time Complexity O(1)
			comparisons++;
			//Time Complexity O(1)
			if (inputArray[index2] < inputArray[comparisonIndex])
			{
				//Time Complexity O(1)
				comparisonIndex = index2;
			};
		};
		//Time Complexity O(1)
		int temp = inputArray[index1];
		inputArray[index1] = inputArray[comparisonIndex];
		inputArray[comparisonIndex] = temp;
	};
	//Time Complexity O(1)
	return comparisons;
};
/*
// ---------------------------------------------------------------------------
Description: Sorts an integer array using insertion sort with a time complexity of Big O(n^2).
Incoming Data: inputArray (Integer Array), inputArraySize (Integer)
Outgoing Data: comparisons (Integer)
// ---------------------------------------------------------------------------
*/
int insertionSort(int inputArray[], int inputArraySize)
{
	/*
	Insertion Sort is a Big O(n^2) quadtratic time complexity algorithm because it has a nested while loop which is 'rounded'
	up to n^2 because the algorithm iterates through the array once then CAN theoretically iterate through the entire array where the items
	are not sorted thus n * n or (n^2)
	since n = 5000 for this example
	n^2 = 5000 * 5000 = 25,000,000 comparisons
	however this is typically not the case since the average number of comparisons in a real world setting will never reach this number of comparisons
	unlike selection sort & insertion sort where it has to iterate through the entire array and do comparisons for the same ammount of times
	insertion sort comparisons vary because it only needs to continue to check if items to the left side of the current value to perform an insertion sort
	is greater than the value that needs to be sorted, therefore it does significantly less comparisons needed to sort the array compared to bubble & selection sort
	the average/typical is actually about [(n - 1) * n] / 4
	which is [(5000 - 1) * 5000] / 4 = 6,248,750 comparisons
	*/
	//Time Complexity O(1)
	int comparisons = 0;
	//Time Complexity O(1)
	if (inputArraySize > 1)
	{
		//Time Complexity O(1)
		comparisons++;
		//Time Complexity O(n)
		for (int index = 1; index < inputArraySize; index++)
		{
			//Time Complexity O(1)
			int temp = inputArray[index];
			int insertionIndex = index - 1;
			comparisons++;
			//Time Complexity O(n), This while loop causes the total time complexity to be O(n^2)
			while (insertionIndex >= 0 && inputArray[insertionIndex] > temp)
			{
				//Time Complexity O(1)
				comparisons++;
				inputArray[insertionIndex + 1] = inputArray[insertionIndex];
				insertionIndex--;	
			};
			//Time Complexity O(1)
			inputArray[insertionIndex + 1] = temp;
		};
	};
	//Time Complexity O(1)
	return comparisons;
};
/*
// ---------------------------------------------------------------------------
Description: Sorts an integer array using merge sort with a time complexity of Big O(n Log(n)) (The 'splitter' recursive function)
Incoming Data: inputVector (Integer Vector), comparisons (Integer Pass By Reference)
Outgoing Data: merger(mergeSort(leftVector, comparisons), mergeSort(rightVector, comparisons), comparisons) (Integer Vector), comparisons (Integer Pass By Reference)
// ---------------------------------------------------------------------------
*/
std::vector<int> mergeSort(std::vector<int> inputVector, int& comparisons)
{
	/*
	Merge Sort is a Big O(n Log(n)) time complexity algorithm because the 'n' part comes the 'merger' part from having to perform comparisons if the
	left array items are smaller or equal to the right array items then having to add/combine them into a merged array while the 'Log(n)'
	part comes 'splitter' part from having to split/divide & conquer the array into smaller sub arrays until they reach the base case of an array size of
	less than or equal to 1
	since n = 5000 for this example
	n Log[Base 2](n) = 5000 * Log[Base 2](5000) ~= 61438 Comparisons
	The average case of mergesort is typically roughly around the same quantity plus/minus a few thousand comparisons to the expected result from the formula nLog[Base 2](n)
	*/
	//Time Complexity O(1)
	if (inputVector.size() <= 1)
	{
		//Time Complexity O(1)
		comparisons++;
		return inputVector;
	};
	//Time Complexity O(1)
	int middleIndex = inputVector.size() / 2;
	std::vector<int> leftVector(inputVector.begin(), inputVector.begin() + middleIndex);
	std::vector<int> rightVector(inputVector.begin() + middleIndex, inputVector.end());
	//Time Complexity O(Log (n)), this divide & conquer recursive behavior causes the total time complexity to be O(n Log(n))
	return merger(mergeSort(leftVector, comparisons), mergeSort(rightVector, comparisons), comparisons);
};
/*
// ---------------------------------------------------------------------------
Description: Sorts an integer array using merge sort with a time complexity of Big O(n Log(n)) (The 'merger' function)
Incoming Data: leftVector (Integer Vector), rightVector (Integer Vector), comparisons (Integer Pass By Reference)
Outgoing Data: mergedVector (Integer Vector), comparisons (Integer Pass By Reference)
// ---------------------------------------------------------------------------
*/
std::vector<int> merger(std::vector<int> leftVector, std::vector<int> rightVector, int& comparisons)
{
	//Time Complexity O(1)
	std::vector<int> mergedVector;
	int leftIndex = 0;
	int rightIndex = 0;
	//Time Complexity O(n)
	while (leftIndex < leftVector.size() && rightIndex < rightVector.size())
	{
		//Time Complexity O(1)
		comparisons++;
		//Time Complexity O(1)
		if (leftVector[leftIndex] <= rightVector[rightIndex])
		{
			//Time Complexity O(1)
			mergedVector.push_back(leftVector[leftIndex]);
			leftIndex++;
		}
		else
		{
			//Time Complexity O(1)
			mergedVector.push_back(rightVector[rightIndex]);
			rightIndex++;
		};
	};
	//Time Complexity O(n)
	while (leftIndex < leftVector.size())
	{
		//Time Complexity O(1)
		comparisons++;
		mergedVector.push_back(leftVector[leftIndex]);
		leftIndex++;	
	};
	//Time Complexity O(n)
	while (rightIndex < rightVector.size())
	{
		//Time Complexity O(1)
		comparisons++;
		mergedVector.push_back(rightVector[rightIndex]);
		rightIndex++;
	};
	//Time Complexity O(1)
	return mergedVector;
};