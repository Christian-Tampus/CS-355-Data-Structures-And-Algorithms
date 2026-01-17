// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project#5 - Unanimly
// Date due: 04/06/2025
// Description: Its basically nim...
// ---------------------------------------------------------------------------
#include <iostream>
#include "HumanPlayer.h"
HumanPlayer::HumanPlayer()
{
	/*
	IMPORTANT: THIS CODE CAN EASILY BE REMOVED THEREFORE IT IS NOT CRITICAL COMPONENT TO THIS PROJECT IF THIS PROJECT WILL HAVE CONTINUATION!
	*/
	//UnanimlyPlayer::isComputer = false;
};
/*
// ---------------------------------------------------------------------------
Description: int HumanPlayer::move(int stonePileAmountLeft), Recursively gets the userInput for the number of stones they want to remove (will continue to prompt until a valid value is inputted)
Incoming Data: stonePileAmountLeft (Integer)
Outgoing Data: humanPlayerIntegerInput (Integer)
// ---------------------------------------------------------------------------
*/
int HumanPlayer::move(int stonePileAmountLeft)
{
	std::cout << "Your Choice: ";
	std::string humanPlayerStringInput;
	int humanPlayerIntegerInput;
	std::getline(std::cin,humanPlayerStringInput);
	try
	{
		humanPlayerIntegerInput = std::stoi(humanPlayerStringInput);
	}
	catch (const std::invalid_argument& INVALID_ARGUMENT_ERROR)
	{
		std::cout << "[SYSTEM ERROR] Input Is Not A Valid Integer!" << std::endl;
		humanPlayerIntegerInput = 0;
	}
	catch (const std::out_of_range& OUT_OF_RANGE_ERROR)
	{
		std::cout << "[SYSTEM ERROR] Integer Input Is Out Of Range!" << std::endl;
		humanPlayerIntegerInput = 0;
	};
	if (humanPlayerIntegerInput >= 1 && humanPlayerIntegerInput <= 3 &&  stonePileAmountLeft - humanPlayerIntegerInput < 0)
	{
		std::cout << "[SYSTEM ERROR] There Is Not " << humanPlayerIntegerInput << " Stones Left In The Pile To Take!" << std::endl;
		return this->move(stonePileAmountLeft);
	}
	else
	{
		return humanPlayerIntegerInput;
	};
};
/*
// ---------------------------------------------------------------------------
Description: bool HumanPlayer::getPlayerType(), Returns if the player is a human or a computer by (true for computer, false for human)
Incoming Data: None
Outgoing Data: UnanimlyPlayer::isComputer (Boolean)
// ---------------------------------------------------------------------------
*/
/*
IMPORTANT: THIS CODE CAN EASILY BE REMOVED THEREFORE IT IS NOT CRITICAL COMPONENT TO THIS PROJECT IF THIS PROJECT WILL HAVE CONTINUATION!
*/
/*
bool HumanPlayer::getPlayerType()
{
	return UnanimlyPlayer::isComputer;
};
*/