// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #7
// Date due: 04/01/2025
// Description: A program to determine the largest digit of a positive integer & generates the chance in US currency for amounts less than $1
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
//Namespaces
using namespace std;
//Function Declarations
int getLargestDigit(int inputInteger);
std::string getChange(int inputChange);
//Driver
int main()
{
	std::cout << "[SYSTEM MESSAGE] Testing Function 1 (Largest Digit Of A Positive Integer)..." << std::endl;
	std::cout << "[SYSTEM MESSAGE] Testing Single Digits & Negative Values..." << std::endl;
	for (int num = -10; num <= 10; num++)
	{
		std::cout << "Input: " << num << " Largest Digit: " << getLargestDigit(num) << std::endl;
	};
	std::cout << "[SYSTEM MESSAGE] Testing If Largest Digit Is Left Most Position..." << std::endl;
	std::cout << "Input:  987654321" << " Largest Digit: " << getLargestDigit(987654321) << std::endl;
	std::cout << "[SYSTEM MESSAGE] Testing If Largest Digit Is Right Most Position..." << std::endl;
	std::cout << "Input:  123456789" << " Largest Digit: " << getLargestDigit(123456789) << std::endl;
	std::cout << "[SYSTEM MESSAGE] Testing If Largest Digit Is Some Where In The Middle Position..." << std::endl;
	std::cout << "Input: 123495678" << " Largest Digit: " << getLargestDigit(123495678) << std::endl;
	std::cout << "[SYSTEM MESSAGE] Testing If Largest Digit Is Some Where In The Middle Position..." << std::endl;
	std::cout << "Input: 129345678" << " Largest Digit: " << getLargestDigit(129345678) << std::endl;
	std::cout << "[SYSTEM MESSAGE] Testing If Largest Digit Is Some Where In The Middle Position..." << std::endl;
	std::cout << "Input: 123456978" << " Largest Digit: " << getLargestDigit(123456978) << std::endl;
	std::cout << "[SYSTEM MESSAGE] Testing If All Digits Are The Same Value..." << std::endl;
	std::cout << "Input: 111111111" << " Largest Digit: " << getLargestDigit(111111111) << std::endl;
	std::cout << "Input: 555555555" << " Largest Digit: " << getLargestDigit(555555555) << std::endl;
	std::cout << "Input: 999999999" << " Largest Digit: " << getLargestDigit(999999999) << std::endl;
	std::cout << "[SYSTEM MESSAGE] Testing Random Largest Digits & Positions..." << std::endl;
	std::cout << "Input: 811111111" << " Largest Digit: " << getLargestDigit(811111111) << std::endl;
	std::cout << "Input: 111111118" << " Largest Digit: " << getLargestDigit(111111118) << std::endl;
	std::cout << "Input: 111181111" << " Largest Digit: " << getLargestDigit(111181111) << std::endl;
	std::cout << "Input: 722222222" << " Largest Digit: " << getLargestDigit(722222222) << std::endl;
	std::cout << "Input: 222222227" << " Largest Digit: " << getLargestDigit(222222227) << std::endl;
	std::cout << "Input: 227222222" << " Largest Digit: " << getLargestDigit(227222222) << std::endl;
	std::cout << "Input: 633333333" << " Largest Digit: " << getLargestDigit(633333333) << std::endl;
	std::cout << "Input: 333333336" << " Largest Digit: " << getLargestDigit(333333336) << std::endl;
	std::cout << "Input: 333333633" << " Largest Digit: " << getLargestDigit(333333633) << std::endl;
	std::cout << "Input: 544444444" << " Largest Digit: " << getLargestDigit(544444444) << std::endl;
	std::cout << "Input: 444444445" << " Largest Digit: " << getLargestDigit(444444445) << std::endl;
	std::cout << "Input: 444454444" << " Largest Digit: " << getLargestDigit(444454444) << std::endl;
	std::cout << "Input: 433333333" << " Largest Digit: " << getLargestDigit(433333333) << std::endl;
	std::cout << "Input: 333333334" << " Largest Digit: " << getLargestDigit(333333334) << std::endl;
	std::cout << "Input: 333343333" << " Largest Digit: " << getLargestDigit(333343333) << std::endl;
	std::cout << "Input: 322222222" << " Largest Digit: " << getLargestDigit(322222222) << std::endl;
	std::cout << "Input: 222222223" << " Largest Digit: " << getLargestDigit(222222223) << std::endl;
	std::cout << "Input: 222232222" << " Largest Digit: " << getLargestDigit(222232222) << std::endl;
	std::cout << "Input: 211111111" << " Largest Digit: " << getLargestDigit(211111111) << std::endl;
	std::cout << "Input: 111111112" << " Largest Digit: " << getLargestDigit(111111112) << std::endl;
	std::cout << "Input: 111121111" << " Largest Digit: " << getLargestDigit(111121111) << std::endl;
	std::cout << "Input: 100000000" << " Largest Digit: " << getLargestDigit(100000000) << std::endl;
	std::cout << "Input: 000000001" << " Largest Digit: " << getLargestDigit(000000001) << std::endl;
	std::cout << "[SYSTEM MESSAGE] Testing Function 2 (Currency Change Generator)..." << std::endl;
	for (int cents = 0; cents <= 100; cents++)
	{
		std::cout << "Change In Cents: " << cents << " => " << getChange(cents) << std::endl;
	};
	std::cout << "[SYSTEM MESSAGE] Program Terminated..." << std::endl;
	return 0;
};
//Function Definitions
/*
// ---------------------------------------------------------------------------
Description: int getLargestDigit(int inputInteger), Recursively determines the largest digit of a positive integer.
Incoming Data: inputInteger (Integer)
Outgoing Data: largestDigit (Integer)
// ---------------------------------------------------------------------------
*/
int getLargestDigit(int inputInteger)
{
	int largestDigit = inputInteger;
	if (inputInteger <= 9)
	{
		return largestDigit;
	};
	int rightMostDigit = inputInteger % 10;
	int remainingDigits = inputInteger / 10;
	/*
	IMPORTANT: The if statement short circuits the function to check if rightMostDigit is equal to 9 then that has to be the largest digit since it can only be from 0-9.
	EXAMPLE: if input is 111191111, it will only have to do recursion starting from the right most position all the way to the middle position where the digit is equal to 9, if it is equal to 9 it has to be the largest digit.
	Therefore the best case could be where the right most position digit is 9 of a large positive integer value and instantly returns that value.
	*/
	if (rightMostDigit == 9)
	{
		largestDigit = rightMostDigit;
	}
	else
	{
		int comparisonDigit = getLargestDigit(remainingDigits);
		if (rightMostDigit >= comparisonDigit)
		{
			largestDigit = rightMostDigit;
		}
		else
		{
			largestDigit = comparisonDigit;
		};
	};
	return largestDigit;
};
/*
// ---------------------------------------------------------------------------
Description: std::string getChange(int inputChange), Recursively generates change (in US currency) for amounts less than $1.
Incoming Data: inputChange (Integer)
Outgoing Data: changeString (String)
// ---------------------------------------------------------------------------
*/
std::string getChange(int inputChange)
{
	if (inputChange <= 0)
	{
		return "";	
	}
	else
	{
		const int QUARTER_VALUE = 25;
		const int DIME_VALUE = 10;
		const int NICKEL_VALUE = 5;
		const int PENNY_VALUE = 1;
		std::string changeString;
		if (inputChange >= QUARTER_VALUE)
		{
			changeString = "Q" + getChange(inputChange - QUARTER_VALUE);
		}
		else if (inputChange >= DIME_VALUE)
		{
			changeString = "D" + getChange(inputChange - DIME_VALUE);
		}
		else if (inputChange >= NICKEL_VALUE)
		{
			changeString = "N" + getChange(inputChange - NICKEL_VALUE);
		}
		else
		{
			changeString = "P" + getChange(inputChange - PENNY_VALUE);
		};
		return changeString;
	};
};