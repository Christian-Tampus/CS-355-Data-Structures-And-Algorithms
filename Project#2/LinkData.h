// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #2 - In-Game Items - Inheritance
// Date due: 02/07/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
#ifndef H_LINKDATA
#define H_LINKDATA
#include <iostream>
using namespace std;
class LinkData{
	public:
		static const int SIZE = 4;
		void setDigits(int, int, int, int);
		int getDigit(int);
	private:
		int digits[4];
};
#endif