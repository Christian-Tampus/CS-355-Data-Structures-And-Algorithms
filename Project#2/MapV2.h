// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #2 - In-Game Items - Inheritance
// Date due: 02/07/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_MAPV2
#define H_MAPV2
//Dependencies
#include "Map.h"
#include <iostream>
//Namespaces
using namespace std;
//Class declaration
class MapV2 : public Map
{
	private:
		std::vector<Item*> itemsVector;
	public:
		MapV2();
		void buildMap();
		void makeItem();
		void insertItems();
		void resetItems();
		friend ostream& operator<<(ostream&, MapV2&);
};
#endif