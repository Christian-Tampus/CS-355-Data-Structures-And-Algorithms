// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #3 - In-Game Items - Polymorphism and ADTs
// Date due: 02/23/2025
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
/*
// ---------------------------------------------------------------------------
Description: Player::inventory(), First asks, “Take what item?” and then reads in a single string (could be multiple words).  It then either reports, “No items are in this area to take.” OR it searches the list of items in the current area for one with a name matching the string entered.  If such an item is found it is added to the inventory and removed from the area’s list of items and “You have taken: X” (where X is the item’s name) is printed out OR the text “No item by that name here.” is printed.
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void Player::inventory()
{
	/*
	IMPORTANT: My Solution
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
	*/
	//Updated Solution
	nodeType<Item*>* temp;
	temp = this->items.getFirst();
	if (temp == NULL)
	{
		std::cout << "No items are in your inventory." << std::endl;
	}
	else
	{
		std::cout << "You have the following items:" << std::endl;
		while (temp != NULL)
		{
			std::cout << "\t" << temp->info->getName() << std::endl;
			temp = temp->link;
		};
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
	/*
	IMPORTANT: My Solution
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
	*/
	//Updated Solution
	std::cout << "Take what item?" << std::endl;
	std::string n;
	std::getline(std::cin,n);
	nodeType<Item*>* temp = NULL;
	temp = this->currentLocation->info.items.getFirst();
	if (temp == NULL)
	{
		std::cout << "No items are in this room to take." << std::endl;
	}
	else
	{
		bool found = false;
		while(temp != NULL && !found)
		{
			if (n == temp->info->getName())
			{
				found = true;
				this->items.insertLast(temp->info);
				this->currentLocation->info.items.deleteNode(temp->info);
			}
			else
			{
				temp = temp->link;
			};
		};
		if (found)
		{
			std::cout << "You have taken: " << n << std::endl;
		}
		else
		{
			std::cout << "No item by that name here." << std::endl;
		};
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
	/*
	IMPORTANT: My Solution
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
	*/
	//Updated Solution
	std::cout << "Leave what item?" << std::endl;
	std::string n;
	std::getline(std::cin,n);
	nodeType<Item*>* temp = NULL;
	temp = this->items.getFirst();
	if (temp == NULL)
	{
		std::cout << "You have no items in your inventory." << std::endl;
	}
	else
	{
		bool found = false;
		while (temp != NULL && !found)
		{
			if (n == temp->info->getName())
			{
				found = true;
				this->currentLocation->info.items.insertLast(temp->info);
				this->items.deleteNode(temp->info);
			}
			else
			{
				temp = temp->link;	
			};
		};
		if (found)
		{
			std::cout << "You have dropped: " << n << std::endl;
		}
		else
		{
			std::cout << "No item by that name in your inventory." << std::endl;	
		};
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
	/*
	IMPORTANT: My Solution
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
	*/
	//Updated Solution
	std::cout << "Examine what item?" << std::endl;
	std::string n;
	std::getline(std::cin,n);
	nodeType<Item*>* temp = NULL;
	temp = this->items.getFirst();
	if (temp == NULL)
	{
		std::cout << "You have no items in your inventory to examine." << std::endl;	
	}
	else
	{
		bool found = false;
		while (temp != NULL && !found)
		{
			if (n == temp->info->getName())
			{
				found = true;
				std::cout << temp->info->getDesc() << std::endl;
			}
			else
			{
				temp = temp->link;
			};
		};
		if (!found)
		{
			std::cout << "No item by that name in your inventory." << std::endl;
		};
	};
};
/*
// ---------------------------------------------------------------------------
Description: Player::getGameEndReason(), returns gameEndReason
Incoming Data: None
Outgoing Data: gameEndReason (String)
// ---------------------------------------------------------------------------
*/
std::string Player::getGameEndReason()
{
	return this->gameEndReason;
};