// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project#5 - Unanimly
// Date due: 04/06/2025
// Description: Its basically nim...
// ---------------------------------------------------------------------------
#ifndef H_COMPUTERPLAYER
#define H_COMPUTERPLAYER
#include "UnanimlyPlayer.h"
class ComputerPlayer : public UnanimlyPlayer
{
	public:
		ComputerPlayer();
		int move(int);
		/*
		IMPORTANT: THIS CODE CAN EASILY BE REMOVED THEREFORE IT IS NOT CRITICAL COMPONENT TO THIS PROJECT IF THIS PROJECT WILL HAVE CONTINUATION!
		*/
		//bool getPlayerType();
};
#endif