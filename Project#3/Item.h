// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #3 - In-Game Items - Polymorphism and ADTs
// Date due: 02/23/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_ITEM
#define H_ITEM
//Dependencies
#include <string>
#include <iostream>
#include <vector>
#include "structs.h"
//Namespaces
using namespace std;
//Class Declaration
class Item
{
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
		std::string getType();
		friend ostream& operator<<(ostream&, Item&);
		//Update Item Used Boolean
		void updateItemUsedBoolean(bool);
		//Check If Has Used The Item
		bool hasUsedItem();
		virtual void setActiveMessage(std::string);
		virtual std::string getActiveMessage();
		virtual void setActiveArea(int);
		virtual int getActiveArea();
		virtual void addRule(Rule*);
		virtual std::vector<Rule*> getItemUseRules();
		virtual void addEffect(Effect* temp);
		virtual std::vector<Effect*> getItemConsumeEffects();
	protected:
		std::string itemName;
		std::string itemDescription;
		int SR;
		std::string activeMessage;
		int activeArea;
		std::string type;
		//Item Used Boolean To Prevent Use Items From Being Re-Used After Activation
		bool itemUsed = false;
};
#endif