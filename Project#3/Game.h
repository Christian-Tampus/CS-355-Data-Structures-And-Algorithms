// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #3 - In-Game Items - Polymorphism and ADTs
// Date due: 02/23/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
#ifndef H_GAME
#define H_GAME
#include "MapV2.h"
#include "Player.h"
#include "BasicPlayer.h"
#include "HPSPPlayer.h"
class Game{
	private:
		Player* player1;
		MapV2 map;
  	public:
		Game();
  		void play();
  		void resetGame();
};
#endif