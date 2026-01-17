// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #3 - In-Game Items - Polymorphism and ADTs
// Date due: 02/23/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Dependencies
#include "ConsumeItem.h"
/*
// ---------------------------------------------------------------------------
Description: ConsumeItem::setActiveMessage(std::string newActiveMessage), sets activeMessage to newActiveMessage
Incoming Data: None
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void ConsumeItem::setActiveMessage(std::string newActiveMessage)
{
	this->activeMessage = newActiveMessage;
};
/*
// ---------------------------------------------------------------------------
Description: ConsumeItem::getActiveMessage(), returns activeMessage
Incoming Data: newActiveMessage (String)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
std::string ConsumeItem::getActiveMessage()
{
	return this->activeMessage;
};
/*
// ---------------------------------------------------------------------------
Description: ConsumeItem::setActiveArea(int newActiveArea), sets activeArea to newActiveArea
Incoming Data: newActiveArea (Integer)
Outgoing Data: activeMessage (String)
// ---------------------------------------------------------------------------
*/
void ConsumeItem::setActiveArea(int newActiveArea)
{
	this->activeArea = newActiveArea;
};
/*
// ---------------------------------------------------------------------------
Description: ConsumeItem::getActiveArea(), returns activeArea
Incoming Data: None
Outgoing Data: activeArea (Integer)
// ---------------------------------------------------------------------------
*/
int ConsumeItem::getActiveArea()
{
	return this->activeArea;
};
/*
// ---------------------------------------------------------------------------
Description: ConsumeItem::addRule(Rule* temp), adds a new rule to the rulesVector
Incoming Data: temp (Rule*)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void ConsumeItem::addRule(Rule* temp)
{
	this->rulesVector.push_back(temp);
};
/*
// ---------------------------------------------------------------------------
Description: ConsumeItem::getItemUseRules(), returns rulesVector
Incoming Data: None
Outgoing Data: rulesVector (Rule* Vector)
// ---------------------------------------------------------------------------
*/
std::vector<Rule*> ConsumeItem::getItemUseRules()
{
	return this->rulesVector;
};
/*
// ---------------------------------------------------------------------------
Description: ConsumeItem::addEffect(Effect* temp), adds a new effect to effectsVector
Incoming Data: temp (Effect*)
Outgoing Data: None
// ---------------------------------------------------------------------------
*/
void ConsumeItem::addEffect(Effect* temp)
{
	this->effectsVector.push_back(temp);
};
/*
// ---------------------------------------------------------------------------
Description: ConsumeItem::getItemConsumeEffects(), returns effectsVector
Incoming Data: None
Outgoing Data: effectsVector (Effect* Vector>
// ---------------------------------------------------------------------------
*/
std::vector<Effect*> ConsumeItem::getItemConsumeEffects()
{
	return this->effectsVector;
};