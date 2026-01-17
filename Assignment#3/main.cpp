// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Assignment #3 - CaesarCipher
// Date due: 02/02/2025
// Description: This program can encrypt, or decrypt depending on the constructor input, and can also print the result of the cipher alphabet. 
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include "advancedCaesar.h";
//Namespaces
using namespace std;
//Driver
int main()
{
	/*
	IMPORTANT WARNING: INPUT VALUES >= 6 WILL OVERFLOW AND GIVE UNEXPECTED CIPHER RESULTS WITH THE GIVEN caesarCipher.h CODE!
	*/
	//Variables
	string asdf = "xyz";
	std::cout << "ASDF BEFORE: " << asdf << std::endl;
	for (int index = 0; index < asdf.length(); index++)
	{
		std::cout << asdf[index] << " ASCII: " << (int)asdf[index] << std::endl;
		asdf[index] += 8;
		std::cout << asdf[index] << " ASCII: " << (int)asdf[index] << std::endl;
	};
	std::cout << "ASDF AFTER: " << asdf << std::endl;
	std::string inputString = "cakeinthebreakroom"; //<----- CHANGE ME!
	advancedCaesar advancedCaesar1(5);
	advancedCaesar advancedCaesar2;
	//Print outs
	std::cout << "AdvancedCaesar1 With Input Parameter Of 5:" << std::endl;
	advancedCaesar1.print();
	std::cout << "Encrypted '" << inputString << "' Result: " << advancedCaesar1.encrypt(inputString) << std::endl;
	std::cout << "Decrypted '" << advancedCaesar1.encrypt(inputString) << "' Result: " << advancedCaesar1.decrypt(advancedCaesar1.encrypt(inputString)) << std::endl;
	std::cout << "AdvancedCaesar2 With No Input Parameters:" << std::endl << std::endl;
	advancedCaesar2.print();
	std::cout << "Encrypted '" << inputString << "' Result: " << advancedCaesar2.encrypt(inputString) << std::endl;
	std::cout << "Decrypted '" << advancedCaesar2.encrypt(inputString) << "' Result: " << advancedCaesar2.decrypt(advancedCaesar2.encrypt(inputString)) << std::endl;
	std::cout << "[SYSTEM MESSAGE] Program Terminated..." << std::endl;
	return 0;
};