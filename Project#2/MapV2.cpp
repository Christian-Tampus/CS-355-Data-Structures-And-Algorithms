// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #2 - In-Game Items - Inheritance
// Date due: 02/07/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include "MapV2.h"
#include "Item.h"
/*
// ---------------------------------------------------------------------------
Description: MapV2::MapV2(), default constructor.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
MapV2::MapV2(){};
/*
// ---------------------------------------------------------------------------
Description: MapV2::buildMap(), overwrites Map::buildMap() to handle maps with items
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void MapV2::buildMap()
{
	Map::ifderr = false;
	Map::parser.tokenIt();
	Map::nextToken = Map::parser.getNext();
	if (Map::nextToken == "<game>")
	{
		Map::parser.eatToken();
		Map::nextToken = Map::parser.getNext();
		while(Map::nextToken != "</game>")
		{
			if (Map::nextToken == "<area>")
			{
				Map::parser.eatToken();
				Map::nextToken = Map::parser.getNext();
				Map::makeArea();
			}
			else if (Map::nextToken == "<links>")
			{
                Map::parser.eatToken();
				Map::nextToken = Map::parser.getNext();
				Map::makeLinks();
			}
			else if (Map::nextToken == "<item>")
			{
				Map::parser.eatToken();
				Map::nextToken = Map::parser.getNext();
				this->makeItem();
			}
			else 
			{
				std::cout << "Parse Error Location 1" << std::endl;
				Map::ifderr = true;
				break;
			};
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
		};
		if (Map::ifderr)
		{
			std::cout << " :: ERROR :: IF Document Formatting Error" << std::endl;
			std::cout << "Game Loading Failed" << std::endl;
			std::cout << "General Area of Parsing Failure:" << std::endl;
			std::cout << "-------------------------------------" << std::endl;
			std::cout << Map::nextToken << std::endl;
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			std::cout << Map::nextToken << std::endl;
			Map::parser.eatToken();
            Map::nextToken = Map::parser.getNext();
			std::cout << Map::nextToken << std::endl;
            Map::parser.eatToken();
            Map::nextToken = Map::parser.getNext();
            std::cout << Map::nextToken << std::endl;
            std::cout <<"-------------------------------------" << std::endl;
			return;
		};
	}
	else
	{
		std::cout << " :: ERROR :: No \"<game>\" tag found." << std::endl;
		std::cout << "Game Loading Failed" << std::endl;
	};
	Map::linkLinks();
	this->insertItems();
};
/*
// ---------------------------------------------------------------------------
Description: MapV2::makeItem(), Creates item and gets the name, desc & start room then appends it to the back of the itemsVector.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void MapV2::makeItem()
{
	Item* tempItemPointer = new Item;
	while (Map::nextToken != "</item>")
	{
		if (Map::nextToken == "<name>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			tempItemPointer->setName(Map::nextToken);
		}
		else if (Map::nextToken == "<desc>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			tempItemPointer->setDesc(Map::nextToken);
		}
		else if (Map::nextToken == "<star>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			tempItemPointer->setSR(std::stoi(Map::nextToken));
		}
		else if (Map::nextToken == "</name>" || Map::nextToken == "</desc>" || Map::nextToken == "</star>")
		{
			//Do Nothing
		}
		else
		{
			std::cout << "Parse Error Location 2" << std::endl;
			Map::ifderr = true;
			break;
		};
		Map::parser.eatToken();
		Map::nextToken = Map::parser.getNext();
	};
	itemsVector.push_back(tempItemPointer);
};
/*
// ---------------------------------------------------------------------------
Description: MapV2::insertItems(), loops itemsVector and gets the start room value offset by 1 and uses that to index the correct area in areasVec to insert the item.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void MapV2::insertItems()
{
	for (int index = 0; index < this->itemsVector.size(); index++)
	{
		Map::areasVec[this->itemsVector[index]->getSR() - 1]->info.items.insertLast(this->itemsVector[index]);
	};
};
/*
// ---------------------------------------------------------------------------
Description: MapV2::resetItems(), method that moves all the pointers to the various Item objects back to their starting areas (this function is called from the resetGame() function in the Game class).
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void MapV2::resetItems()
{
	for (int index = 0; index < Map::areasVec.size(); index++)
	{
		Map::areasVec[index]->info.items.destroyList();
	};
	this->insertItems();
};
/*
// ---------------------------------------------------------------------------
Description: ostream& operator<<(ostream& osObject, MapV2& mapV2), Prints the information of the areas and then the items in each area.
Incoming Data: osObject (ostream&), mapV2 (MapV2&)
Outgoing Data: osObject (ostream&)
// ---------------------------------------------------------------------------
*/
ostream& operator<<(ostream& osObject, MapV2& mapV2)
{
	osObject << "******************************************************************" << std::endl;
	osObject << "CHEATING!!!! Printing the set of areas and connections on the map." << std::endl;
	osObject << "******************************************************************" << std::endl;
	for (int index = 0; index < mapV2.areasVec.size(); index++)
	{
		osObject << "This is area: " << index + 1 << std::endl;
		osObject << mapV2.areasVec[index]->info.getDescription() << std::endl;
		if (mapV2.areasVec[index]->info.getID() == 1)
		{
			osObject << "Area is INSTADEATH." << std::endl;
		};
		if (mapV2.areasVec[index]->info.getGoal() == 1)
		{
			osObject << "Area is GOAL." << std::endl;	
		};
		osObject << "Connections:" << std::endl;
		osObject << "\t u: Area #" << mapV2.reverseLookUp(mapV2.areasVec[index]->u) << std::endl;
		osObject << "\t d: Area #" << mapV2.reverseLookUp(mapV2.areasVec[index]->d) << std::endl;
		osObject << "\t l: Area #" << mapV2.reverseLookUp(mapV2.areasVec[index]->l) << std::endl;
		osObject << "\t r: Area #" << mapV2.reverseLookUp(mapV2.areasVec[index]->r) << std::endl;
	};
	osObject << "******************************************************************" << std::endl;
	osObject << "CHEATING!!!! ITEM LOCATIONS FOR ALL NON-INVENTORY ITEMS." << std::endl;
	osObject << "******************************************************************" << std::endl;
	for (int index = 0; index < mapV2.areasVec.size(); index++)
	{
		osObject << "Items for area " << index + 1 << ": " << mapV2.areasVec[index]->info.getDescription() << std::endl;
		mapV2.areasVec[index]->info.search();
	};
	return osObject;
};