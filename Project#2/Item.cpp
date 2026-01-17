// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #2 - In-Game Items - Inheritance
// Date due: 02/07/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Dependencies
#include "Item.h"
#include <iostream>
/*
// ---------------------------------------------------------------------------
Description: Item::Item(), default constructor
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
Item::Item(){};
/*
// ---------------------------------------------------------------------------
Description: Item::setName(std::string newItemName), sets itemName
Incoming Data: newItemName (String)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Item::setName(std::string newItemName)
{
	this->itemName = newItemName;
};
/*
// ---------------------------------------------------------------------------
Description: Item::setDesc(std::string newItemDescription), sets itemDescription
Incoming Data: newItemDescription (String)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Item::setDesc(std::string newItemDescription)
{
	this->itemDescription = newItemDescription;
};
/*
// ---------------------------------------------------------------------------
Description: Item::setSR(int newSR), sets SR
Incoming Data: newSR (Integer)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Item::setSR(int newSR)
{
	this->SR = newSR;	
};
/*
// ---------------------------------------------------------------------------
Description: Item::getName(), returns itemName
Incoming Data: None
Outgoing Data: itemName (String)
// ---------------------------------------------------------------------------
*/
std::string Item::getName()
{
	return this->itemName;	
};
/*
// ---------------------------------------------------------------------------
Description: Item::getDesc(), returns itemDescription
Incoming Data: None
Outgoing Data: itemDescription (String)
// ---------------------------------------------------------------------------
*/
std::string Item::getDesc()
{
	return this->itemDescription;	
};
/*
// ---------------------------------------------------------------------------
Description: Item::getSR(), returns SR
Incoming Data: None
Outgoing Data: SR (Integer)
// ---------------------------------------------------------------------------
*/
int Item::getSR()
{
	return this->SR;	
};
/*
// ---------------------------------------------------------------------------
Description: Item::displayName(), prints itemName
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Item::displayName()
{
	std::cout << this->itemName << std::endl;	
};
/*
// ---------------------------------------------------------------------------
Description: Item::displayDesc(), prints itemDescription
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Item::displayDesc()
{
	std::cout << this->itemDescription << std::endl;	
};
/*
// ---------------------------------------------------------------------------
Description: ostream& operator<<(ostream& outStream, Item& item), insertion operator overloaded to print itemName, itemDescription & SR
Incoming Data: outStream (ostream&), item (Item&)
Outgoing Data: outStream (ostream&)
// ---------------------------------------------------------------------------
*/
ostream& operator<<(ostream& outStream, Item& item)
{
	outStream << item.itemName << std::endl;
	outStream << item.itemDescription << std::endl;
	outStream << item.SR << std::endl; 
	return outStream;	
};