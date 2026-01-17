// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #2 - In-Game Items - Inheritance
// Date due: 02/07/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_ITEM
#define H_ITEM
//Dependencies
#include <iostream>
//Namespaces
using namespace std;
//Class declaration
class Item
{
	private:
		std::string itemName;
		std::string itemDescription;
		int SR;
	public:
		Item();
		void setName(std::string);
		void setDesc(std::string);
		void setSR(int);
		std::string getName();
		std::string getDesc();
		int getSR();
		void displayName();
		void displayDesc();
		friend ostream& operator<<(ostream&, Item&);
};
#endif