// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #3 - CaesarCipher
// Date due: 02/02/2025
// Description: This program can encrypt, or decrypt depending on the constructor input, and can also print the result of the cipher alphabet. 
// ---------------------------------------------------------------------------
//Headers
#ifndef H_AdvancedCaesar
#define H_AdvancedCaesar
//Dependencies
#include "caesarCipher.h"
#include <iostream>
#include <string>
//Namespaces
using namespace std;
//Class declaration, advancedCaesar EXTENDS(Derives) caesarCipher
class advancedCaesar : public caesarCipher
{
	private:
		char alphabetArray[26];
		void constructor(); //<---- This simply reduces the code since it is the same for both constructors
	public:
		advancedCaesar();
		advancedCaesar(int);
		void print();
};
#endif