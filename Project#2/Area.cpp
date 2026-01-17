// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #2 - In-Game Items - Inheritance
// Date due: 02/07/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
#include <iostream>
#include "Area.h"
void Area::setDescription (string desc){
    description = desc;
}
void Area::setGoal(bool g){
    goal = g;
}
void Area::setID(bool id){
    instadeath = id;
}
string Area::getDescription(){
    return description;
}
bool Area::getID(){
    return instadeath;
}
bool Area::getGoal(){
    return goal;
}
void Area::displayArea(){
    cout<<description<<endl;
}
/*
// ---------------------------------------------------------------------------
Description: Area::search(), Searches the area's linked list for items, if the length of the linked list is 0, then it should print out that there are no items in the area, if not it prints out the names of the items that are found in the area.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Area::search()
{
	if (this->items.length() > 0)
	{
		std::cout << "The following items are in this area:" << std::endl;
		nodeType<Item*>* currentItem = this->items.getFirst();
		while (currentItem != nullptr)
		{
			std::cout << "\t" << currentItem->info->getName() << std::endl;
			currentItem = currentItem->link;
		};
	}else
	{
		std::cout << "No items are in this area." << std::endl;
	};
};