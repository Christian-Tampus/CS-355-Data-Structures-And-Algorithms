// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #3 - In-Game Items - Polymorphism and ADTs
// Date due: 02/23/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_CONSUMEITEM
#define H_CONSUMEITEM
//Dependencies
#include "Item.h"
//Namespaces
using namespace std;
//Class Declaration
class ConsumeItem : public Item
{
	public:
		void setActiveMessage(std::string) override;
		std::string getActiveMessage();
		void setActiveArea(int);
		int getActiveArea();
		void addRule(Rule*);
		std::vector<Rule*> getItemUseRules();
		void addEffect(Effect* temp);
		std::vector<Effect*> getItemConsumeEffects();
	private:
		std::vector<Rule*> rulesVector;
		std::vector<Effect*> effectsVector;
};
#endif