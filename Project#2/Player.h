// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #2 - In-Game Items - Inheritance
// Date due: 02/07/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//Headers
#ifndef H_PLAYER
#define H_PLAYER
//Dependencies
#include "areaNode.h"
#include "ull.h"
//Class declaration
class Player{
	public:
		Player();
		void setCurrent(areaNode*);
		bool playerMoved();
		areaNode* getCurrent();
		//isGameOver should return: 0 for continue, 1 for win, 2 for lose
		int isGameOver();
		uLList<Item*> items;
		void inventory();
		void take();
		void leave();
		void examine();
	private:
		areaNode* currentLocation;
		areaNode* lastLocation;
};
#endif