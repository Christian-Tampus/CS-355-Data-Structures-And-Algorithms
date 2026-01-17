// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #2 - In-Game Items - Inheritance
// Date due: 02/07/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include <string>
#include "ull.h"
#include "Player.h"
Player::Player(){
    lastLocation = NULL;
    currentLocation = NULL;
}
void Player::setCurrent(areaNode* loc){
    lastLocation = currentLocation;
    currentLocation = loc;
}
bool Player::playerMoved(){
    return !(lastLocation == currentLocation);
}
areaNode* Player::getCurrent(){
    return currentLocation;
}
//isGameOver should return: 0 for continue, 1 for win, 2 for lose
int Player::isGameOver(){
	//--------------------------------------------------
	//Assignment #1 - Make the Game Winnable/Loseable
	//Declare variables
	bool isInstaDeathRoom = true;
	bool isGoalRoom = true;
	int loseReturnValue = 2;
	int winReturnValue = 1;
	int continueReturnValue = 0;
	bool currentLocationID = (*this->currentLocation).info.getID();
	bool currentLocationGoal = (*this->currentLocation).info.getGoal();
	/*
	1. First check if player's currentLocationID is equal to an isInstaDeathRoom, if true return loseReturnValue
	2. Second check if player's currentLocationGoal is equal to isGoalRoom, if true return winReturnValue
	3. Else If both first & second checks are false, return continueReturnValue
	*/
    return (currentLocationID == isInstaDeathRoom ? loseReturnValue : currentLocationGoal == isGoalRoom ? winReturnValue : continueReturnValue);
    //--------------------------------------------------
};
/*
// ---------------------------------------------------------------------------
Description: Player::inventory(), First asks, “Take what item?” and then reads in a single string (could be multiple words).  It then either reports, “No items are in this area to take.” OR it searches the list of items in the current area for one with a name matching the string entered.  If such an item is found it is added to the inventory and removed from the area’s list of items and “You have taken: X” (where X is the item’s name) is printed out OR the text “No item by that name here.” is printed.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Player::inventory()
{
	if (this->items.length() > 0)
	{
		std::cout << "You have the following items:" << std::endl;
		nodeType<Item*>* currentItem = this->items.getFirst();
		while (currentItem != nullptr)
		{
			std::cout << "\t" << currentItem->info->getName() << std::endl;
			currentItem = currentItem->link;	
		};
	}
	else
	{
		std::cout << "No items are in your inventory" << std::endl;
	};
};
/*
// ---------------------------------------------------------------------------
Description: Player::take(), First asks, “Take what item?” and then reads in a single string (could be multiple words).  It then either reports, “No items are in this area to take.” OR it searches the list of items in the current area for one with a name matching the string entered.  If such an item is found it is added to the inventory and removed from the area’s list of items and “You have taken: X” (where X is the item’s name) is printed out OR the text “No item by that name here.” is printed.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Player::take()
{
	std::cout << "Take what item?" << std::endl;
	std::string itemToTake;
	std::getline(std::cin,itemToTake);
	if (this->currentLocation->info.items.length() > 0)
	{
		nodeType<Item*>* currentItem = this->currentLocation->info.items.getFirst();
		while (currentItem != nullptr && currentItem->info->getName() != itemToTake)
		{
			currentItem = currentItem->link;		
		};
		if (currentItem != nullptr && currentItem->info->getName() == itemToTake)
		{
			std::cout << "You have taken: " << currentItem->info->getName() << std::endl;
			this->items.insertLast(currentItem->info);
			this->currentLocation->info.items.deleteNode(currentItem->info);
		}
		else
		{
			std::cout << "No item by that name here." << std::endl;	
		};
	}
	else
	{
		std::cout << "No items are in this area to take." << std::endl;	
	};
};
/*
// ---------------------------------------------------------------------------
Description: Player::leave(), First asks, “Leave what item?” and then reads in a single string (could be multiple words).  It then either reports, “You have no items in your inventory.” OR it searches the inventory of items for one with a name matching the string entered.  If such an item is found it is removed from the inventory, added to the area’s list of items and “You have dropped: X” (where X is the item’s name) is printed out OR the text “No item by that name in your inventory.” is printed.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Player::leave()
{
	std::cout << "Leave what item?" << std::endl;
	std::string itemToLeave;
	std::getline(std::cin,itemToLeave);
	if (this->items.length() > 0)
	{
		nodeType<Item*>* currentItem = this->items.getFirst();
		while (currentItem != nullptr && currentItem->info->getName() != itemToLeave)
		{
			currentItem = currentItem->link;	
		};
		if (currentItem != nullptr && currentItem->info->getName() == itemToLeave)
		{
			std::cout << "You have dropped: " << currentItem->info->getName() << std::endl;
			this->currentLocation->info.items.insertLast(currentItem->info);
			this->items.deleteNode(currentItem->info);
		}
		else
		{
			std::cout << "No item by that name in your inventory." << std::endl;	
		};
	}
	else
	{
		std::cout << "You have no items in your inventory." << std::endl;	
	};
};
/*
// ---------------------------------------------------------------------------
Description: Player::examine(), First asks, “Examine what item?” and then reads in a single string (could be multiple words).  It then either reports, “You have no items in your inventory to examine.” OR it searches the inventory for an item of that name.  The function will then either report “No item by that name in your inventory.” OR it will print the item’s description (using getDesc()).
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Player::examine()
{
	std::cout << "Examine what item?" << std::endl;
	std::string itemToExamine;
	std::getline(std::cin,itemToExamine);
	if (this->items.length() > 0)
	{
		nodeType<Item*>* currentItem = this->items.getFirst();
		while (currentItem != nullptr && currentItem->info->getName() != itemToExamine)
		{
			currentItem = currentItem->link;
		};
		if (currentItem != nullptr && currentItem->info->getName() == itemToExamine)
		{
			std::cout << currentItem->info->getDesc() << std::endl;
		}
		else
		{
			std::cout << "No item by that name in your inventory." << std::endl;	
		};
	}
	else
	{
		std::cout << "You have no items in your inventory to examine." << std::endl;	
	};
};