// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #3 - CaesarCipher
// Date due: 02/02/2025
// Description: This program can encrypt, or decrypt depending on the constructor input, and can also print the result of the cipher alphabet. 
// ---------------------------------------------------------------------------
//Dependencies
#include "caesarCipher.h"
#include <iostream>
#include <string>
//Namespaces
using namespace std;
//Method definitions
/*
IMPORTANT: Rewrote the code to conform to the code standards [DID NOT CHANGE the logic of the original code, just rewrote it to conform to the code standards & personal preferences for variable names]
*/
caesarCipher::caesarCipher()
{
	this->shiftValue = 1;
};
caesarCipher::caesarCipher(int newShiftValue)
{
	this->shiftValue = newShiftValue;
};
std::string caesarCipher::encrypt(std::string inputString)
{
	int a_ASCII = 97;
	int z_ASCII = 122;
	int offset = 1;
	for (int index = 0; index < inputString.length(); index++)
	{
		if (inputString[index] >= a_ASCII && inputString[index] <= z_ASCII)
		{
			/*
			IMPORTANT WARNING: THIS CODE WILL OVERFLOW! IF SHIFT VALUE IS >= 6! (122 + 6 = 128 => -128)
			*/
			inputString[index] += this->shiftValue;
			if (inputString[index] > z_ASCII)
			{
				inputString[index] = ((inputString[index] % z_ASCII) + a_ASCII) - offset;
			};
		}
		else
		{
			std::cout << "limit your characters to a-z all lower case" << std::endl;	
		};
	};
	return inputString;
};
std::string caesarCipher::decrypt(std::string inputString)
{
	int a_ASCII = 97;
	int z_ASCII = 122;
	int offset = 1;
	for (int index = 0; index < inputString.length(); index++)
	{
		if (inputString[index] >= a_ASCII && inputString[index] <= z_ASCII)
		{
			/*
			IMPORTANT WARNING: THIS CODE WILL OVERFLOW! IF SHIFT VALUE IS >= 6! (122 + 6 = 128 => -128)
			*/
			inputString[index] -= this->shiftValue;
			if (inputString[index] < a_ASCII)
			{
				inputString[index] = z_ASCII - (a_ASCII - inputString[index] - offset);	
			};
		}
		else
		{
			std::cout << "limit your characters to a-z all lower case" << std::endl;
		};
	};
	return inputString;
};
void caesarCipher::print()
{
	std::cout << this->shiftValue << std::endl;
};