// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #3 - CaesarCipher
// Date due: 02/02/2025
// Description: This program can encrypt, or decrypt depending on the constructor input, and can also print the result of the cipher alphabet. 
// ---------------------------------------------------------------------------
//Dependencies
#include "advancedCaesar.h";
#include <iostream>
#include <string>
//Namespaces
using namespace std;
//Method definitions
/*
// ---------------------------------------------------------------------------
Description: constructor(), encrypts alphabet string using the inherited encryption method then puts the values into the alphabetArray
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void advancedCaesar::constructor()
{
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::string encryptedAlphabet = caesarCipher::encrypt(alphabet);
	for (int index = 0; index < alphabet.size(); index++)
	{
		this->alphabetArray[index] = encryptedAlphabet[index];
	};
};
/*
// ---------------------------------------------------------------------------
Description: advancedCaesar(), calls private method constructor()
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
advancedCaesar::advancedCaesar()
{
	this->constructor();
};
/*
// ---------------------------------------------------------------------------
Description: advancedCaesar(int shiftValue), calls private method constructor() as well as call the single parameter constructor for caesarCipher
Incoming Data: shiftValue (Integer)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
advancedCaesar::advancedCaesar(int newShiftValue):caesarCipher(newShiftValue)
{
	this->constructor();
};
/*
// ---------------------------------------------------------------------------
Description: print(), first calls the print method for the parent class then prints the alphabetArray elements into the format [_,_,_,...] where '_' is for the shifted alphabet character and the number of '_' is 26
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void advancedCaesar::print()
{
	std::cout << "Shift Value: ";
	caesarCipher::print();
	int alphabetCount = 26;
	int lastCharacterIndex = 25;
	std::string cipherAlphabet = "[";
	for (int index = 0; index < alphabetCount; index++)
	{
		cipherAlphabet += this->alphabetArray[index];
		if (index != lastCharacterIndex)
		{
			cipherAlphabet += ",";
		};
	};
	cipherAlphabet += "]";
	std::cout << "Cipher Alphabet: " << cipherAlphabet << std::endl;
};