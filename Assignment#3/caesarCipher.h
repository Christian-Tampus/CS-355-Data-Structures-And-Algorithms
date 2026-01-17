// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #3 - CaesarCipher
// Date due: 02/02/2025
// Description: This program can encrypt, or decrypt depending on the constructor input, and can also print the result of the cipher alphabet. 
// ---------------------------------------------------------------------------
//Headers
#ifndef H_CaesarCipher
#define H_CaesarCipher
//Dependencies
#include <iostream>
#include <string>
//Namespaces
using namespace std;
//Class declaration
/*
IMPORTANT: Rewrote the code to conform to the code standards [DID NOT CHANGE the logic of the original code, just rewrote it to conform to the code standards & personal preferences for variable names]
*/
class caesarCipher
{
	private:
		int shiftValue;
	public:
		caesarCipher();
		caesarCipher(int);
		std::string encrypt(std::string);
		std::string decrypt(std::string);
		void print();
};
#endif