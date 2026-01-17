// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project#5 - Unanimly
// Date due: 04/06/2025
// Description: Its basically nim...
// ---------------------------------------------------------------------------
//Dependencies
#include <iostream>
#include <string>
#include "Unanimly.h"
//Namespaces
using namespace std;
//Function Declaration
/*
IMPORTANT: THIS CODE CAN EASILY BE REMOVED THEREFORE IT IS NOT CRITICAL COMPONENT TO THIS PROJECT IF THIS PROJECT WILL HAVE CONTINUATION!
*/
//int gameModeWithInputValidation();
//Driver
int main()
{
	std::cout << "[SYSTEM MESSAGE] Welcome To The Unanimly Game!" << std::endl;
	std::cout << "[NOTE FOR DR. RAY] You Can Uncomment ALL The Lines Of Code In ALL The Files That Are Below The Comments Of => 'IMPORTANT: THIS CODE CAN EASILY...' To Test The Ability To Choose The Game Mode For 1 Player Or 2 Players!" << std::endl;
	std::cout << "[NOTE FOR DR. RAY] The Code Files Are Logically The Same As The Original, I've Only Did A Bit Of Refactoring!" << std::endl;
	int x;
	std::string cont = "y";
	Unanimly game;
	/*
	IMPORTANT: THIS CODE CAN EASILY BE REMOVED THEREFORE IT IS NOT CRITICAL COMPONENT TO THIS PROJECT IF THIS PROJECT WILL HAVE CONTINUATION!
	*/
	//Unanimly game(gameModeWithInputValidation());
	while (cont == "y")
	{
		x = game.play();
		std::cout << "Player " << x << " Wins!" << std::endl;
		std::cout << "Game Over! Play Again ('y' Or 'n')?" << std::endl;
		std::getline(std::cin,cont);
	};
	std::cout << "[SYSTEM MESSAGE] Program Terminated..." << std::endl;
	return 0;
};
//Function Definitions
/*
// ---------------------------------------------------------------------------
Description: int gameModeWithInputValidation, Recursively prompts the user for the game mode type (1 player or 2 players)
Incoming Data: None
Outgoing Data: Game Node Integer (1 OR 2)
// ---------------------------------------------------------------------------
*/
/*
IMPORTANT: THIS CODE CAN EASILY BE REMOVED THEREFORE IT IS NOT CRITICAL COMPONENT TO THIS PROJECT IF THIS PROJECT WILL HAVE CONTINUATION!
*/
/*
int gameModeWithInputValidation()
{
	std::cout << "Select [1] For 1 Player (COMPUTER VS HUMAN 1) Or [2] For 2 Players (HUMAN 1 VS HUMAN 2)!" << std::endl;
	std::cout << "Game Mode: ";
	std::string userStringInput;
	int userIntegerInput = 0;
	std::getline(std::cin,userStringInput);
	try
	{
		userIntegerInput = std::stoi(userStringInput);
	}
	catch (const std::invalid_argument& INVALID_ARGUMENT_ERROR)
	{
		userIntegerInput = -1;
		std::cout << "[SYSTEM ERROR] Input Is Not A Valid Integer!" << std::endl;
	}
	catch (const std::out_of_range& OUT_OF_RANGE_ERROR)
	{
		userIntegerInput = -1;
		std::cout << "[SYSTEM ERROR] Integer Input Is Out Of Range!" << std::endl;
	};
	if (userIntegerInput == 1 || userIntegerInput == 2)
	{
		return userIntegerInput;
	}
	else
	{
		if (userIntegerInput == 0)
		{
			std::cout << "[SYSTEM ERROR] The Only Valid Inputs For The Game Modes Are [1] & [2]!" << std::endl;
		};
		return gameModeWithInputValidation();
	};
};
*/