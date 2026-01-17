// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #3 - In-Game Items - Polymorphism and ADTs
// Date due: 02/23/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "MapV2.h"
#include "Item.h"
#include "ConsumeItem.h"
#include "UseItem.h"
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
Description: MapV2::buildMap(), overwrites Map::buildMap() to handle maps with different item types & player types
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
			//NEW TOKEN <ptype>
			else if (Map::nextToken == "<ptype>")
			{
				Map::parser.eatToken();
				Map::nextToken = Map::parser.getNext();
				this->makePlayer();
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
Description: MapV2::makeItem(), Creates a unique item type (basic, consume, use) and calls makeItemType method passing tempItemPointer & the ending tag associated with the item type
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void MapV2::makeItem()
{
	Item* tempItemPointer = nullptr;
	while (Map::nextToken != "</item>")
	{
		if (Map::nextToken == "<basic>")
		{
			tempItemPointer = new Item();
			this->makeItemType(tempItemPointer,"</basic>");
		}
		else if (Map::nextToken == "<consume>")
		{
			tempItemPointer = new ConsumeItem();
			this->makeItemType(tempItemPointer,"</consume>");
		}
		else if (Map::nextToken == "<use>")
		{
			tempItemPointer = new UseItem();
			this->makeItemType(tempItemPointer,"</use>");
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
Description: MapV2::makeItemType(Item*& inputItemPointer, std::string itemTypeClosingTag), creates the unique item types and parses their attributes then sets them to the tempItemPointer
Incoming Data: inputItemPointer (Item*&), itemTypeClosingTag (String)
Outgoing Data: inputItemPointer (Item*&)
// ---------------------------------------------------------------------------
*/
void MapV2::makeItemType(Item*& inputItemPointer, std::string itemTypeClosingTag)
{
	const char delimiter = ',';
	const int numberOfEndingTags = 7;
	const std::string endingTags[numberOfEndingTags] = {"</name>","</desc>","</star>","</actmess>","</actar>","</effect>","</rule>"};
	Map::parser.eatToken();
	Map::nextToken = Map::parser.getNext();
	while (Map::nextToken != itemTypeClosingTag)
	{
		if (Map::nextToken == "<name>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			inputItemPointer->setName(Map::nextToken);
		}
		else if (Map::nextToken == "<desc>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			inputItemPointer->setDesc(Map::nextToken);
		}
		else if (Map::nextToken == "<star>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			inputItemPointer->setSR(std::stoi(Map::nextToken));
		}
		else if (Map::nextToken == "<actmess>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			inputItemPointer->setActiveMessage(Map::nextToken);
		}
		else if (Map::nextToken == "<actar>")
		{
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			inputItemPointer->setActiveArea(std::stoi(Map::nextToken));
		}
		else if (Map::nextToken == "<rule>")
		{
			Rule* newRule = new Rule;
			std::string tempStringToken;
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			std::istringstream ss(Map::nextToken);
			std::getline(ss,tempStringToken,delimiter);
			newRule->beginRm = std::stoi(tempStringToken);
			std::getline(ss,tempStringToken,delimiter);
			newRule->direction = tempStringToken[0];
			std::getline(ss,tempStringToken,delimiter);
			newRule->destRm = std::stoi(tempStringToken);
			inputItemPointer->addRule(newRule);
		}
		else if (Map::nextToken == "<effect>")
		{
			/*
			IMPORTANT: Consume Items Should Have 3 attributes so that you can quantify the ammount per consumable <effect>1,10,x</effect>
			Where 'x' is the consumable quantity
			*/
			Effect* newEffect = new Effect;
			std::string tempStringToken;
			Map::parser.eatToken();
			Map::nextToken = Map::parser.getNext();
			std::istringstream ss(Map::nextToken);
			std::getline(ss,tempStringToken,delimiter);
			newEffect->effectID = std::stoi(tempStringToken);
			std::getline(ss,tempStringToken,delimiter);
			newEffect->effectAmt = std::stoi(tempStringToken);
			inputItemPointer->addEffect(newEffect);
		}
		else
		{
			bool doNothing = false;
			for (int index = 0; index < numberOfEndingTags; index++)
			{
				if (Map::nextToken == endingTags[index])
				{
					doNothing = true;
					break;
				};
			};
			if (!doNothing)
			{
				std::cout << "Parse Error Location 3" << std::endl;
				Map::ifderr = true;
				break;	
			};
		};
		Map::parser.eatToken();
		Map::nextToken = Map::parser.getNext();
	};
};
/*
// ---------------------------------------------------------------------------
Description: MapV2::makePlayer(), Creates new player type by first validating the player type, if not valid will default to basic player type
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void MapV2::makePlayer()
{
	const int numberOfPlayerTypes = 2;
	const std::string validPlayerTypesArray[numberOfPlayerTypes] = {"basic","hpsp"};
	std::string playerType = Map::nextToken;
	bool isValidPlayerType = false;
	for (int index = 0; index < numberOfPlayerTypes; index++)
	{
		if (validPlayerTypesArray[index] == playerType)
		{
			isValidPlayerType = true;
			break;
		};
	};
	if (!isValidPlayerType)
	{
		std::cout << "Player Type: " << playerType << " Is An Invalid Player Type!" << std::endl;
		std::cout << "Defaulting To Basic Player Type!" << std::endl;
		playerType = "basic";
	};
	this->playerType = playerType;
	Map::parser.eatToken();
	Map::nextToken = Map::parser.getNext();
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
		this->itemsVector[index]->updateItemUsedBoolean(false);
		Map::areasVec[this->itemsVector[index]->getSR() - 1]->info.items.insertLast(this->itemsVector[index]);
	};
};
/*
// ---------------------------------------------------------------------------
Description: MapV2::resetItems(), method that moves all the pointers to the various Item objects back to their starting areas (this function is called from the resetGame() function in the Game class) and also resets the map area connection pointers.
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
	//This resets the area connection pointers
	Map::linkLinks();
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