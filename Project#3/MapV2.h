// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #3 - In-Game Items - Polymorphism and ADTs
// Date due: 02/23/2025
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
//Class Declaration
class MapV2 : public Map
{
	private:
		std::vector<Item*> itemsVector;
	public:
		MapV2();
		void buildMap();
		void makeItem();
		void makeItemType(Item*&, std::string);
		void makePlayer();
		void insertItems();
		void resetItems();
		friend ostream& operator<<(ostream&, MapV2&);
		//Stores String For PlayerType, Defaults To basic PlayerType
		std::string playerType = "basic";
};
#endif