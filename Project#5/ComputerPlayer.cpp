// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project#5 - Unanimly
// Date due: 04/06/2025
// Description: Its basically nim...
// ---------------------------------------------------------------------------
#include <iostream>
#include "ComputerPlayer.h"
ComputerPlayer::ComputerPlayer()
{
	/*
	IMPORTANT: THIS CODE CAN EASILY BE REMOVED THEREFORE IT IS NOT CRITICAL COMPONENT TO THIS PROJECT IF THIS PROJECT WILL HAVE CONTINUATION!
	*/
	//UnanimlyPlayer::isComputer = true;
};
/*
// ---------------------------------------------------------------------------
Description: int ComputerPlayer::move(int stonePileAmountLeft), recursively calls the same function to determine what number of stones to remove at any given number of stones in the current stone pile
Incoming Data: stonePileAmountLeft (Integer)
Outgoing Data: stonePileAmountLeft (Integer)
// ---------------------------------------------------------------------------
*/
int ComputerPlayer::move(int stonePileAmountLeft)
{
	if (stonePileAmountLeft <= 3)
	{
		//Take all the remaining stones and the computer wins!
		return stonePileAmountLeft;
	}
	else if (stonePileAmountLeft == 4)
	{
		//OHHHH NOOOOOO! Computer Loses The Game (If human player is not dumb) (Should never enter this if-statement if the number of stones is always not divisible by 4 and the computer always start first)
		return 1;
	};
	//do this because we can't use x MOD 4 :-(
	return this->move(stonePileAmountLeft - 4);
};
/*
// ---------------------------------------------------------------------------
Description: bool ComputerPlayer::getPlayerType(), Returns if the player is a human or a computer by (true for computer, false for human)
Incoming Data: None
Outgoing Data: UnanimlyPlayer::isComputer (Boolean)
// ---------------------------------------------------------------------------
*/
/*
IMPORTANT: THIS CODE CAN EASILY BE REMOVED THEREFORE IT IS NOT CRITICAL COMPONENT TO THIS PROJECT IF THIS PROJECT WILL HAVE CONTINUATION!
*/
/*
bool ComputerPlayer::getPlayerType()
{
	return UnanimlyPlayer::isComputer;
};
*/