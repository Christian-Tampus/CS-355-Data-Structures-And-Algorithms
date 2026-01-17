// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project#5 - Unanimly
// Date due: 04/06/2025
// Description: Its basically nim...
// ---------------------------------------------------------------------------
#ifndef H_HUMANPLAYER
#define H_HUMANPLAYER
#include "UnanimlyPlayer.h"
class HumanPlayer : public UnanimlyPlayer
{
	public:
		HumanPlayer();
		int move(int);
		/*
		IMPORTANT: THIS CODE CAN EASILY BE REMOVED THEREFORE IT IS NOT CRITICAL COMPONENT TO THIS PROJECT IF THIS PROJECT WILL HAVE CONTINUATION!
		*/
		//bool getPlayerType();
};
#endif