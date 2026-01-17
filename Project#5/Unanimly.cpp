// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project#5 - Unanimly
// Date due: 04/06/2025
// Description: Its basically nim...
// ---------------------------------------------------------------------------
/*
IMPORTANT: I'VE ONLY REFACTORED THE CODE IN THIS FILE, ALL THE LOGIC IS EXACTLY THE SAME BESIDES A FEW MINOR COUT TWEAKS!
*/
#include "Unanimly.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
Unanimly::Unanimly()
{
	//Comment out the next line and uncomment the next line for PART 2
    this->player1 = new ComputerPlayer();
    //this->player2 = new HumanPlayer();
    player2 = new HumanPlayer();
};
/*
IMPORTANT: THIS CODE CAN EASILY BE REMOVED THEREFORE IT IS NOT CRITICAL COMPONENT TO THIS PROJECT IF THIS PROJECT WILL HAVE CONTINUATION!
*/
/*
Unanimly::Unanimly(int gameMode)
{
	if (gameMode == 1)
	{
		this->player1 = new ComputerPlayer();
	}
	else
	{
		this->player1 = new HumanPlayer();
	};
	this->player2 = new HumanPlayer();
};
*/
int Unanimly::callMove()
{
	int amt;
	std::cout << "Player " << this->turn << ": There Are " << this->pile << " Stones Left. Select 1, 2, Or 3 Stones." << std::endl;
	/*
	IMPORTANT: THIS CODE CAN EASILY BE REMOVED THEREFORE IT IS NOT CRITICAL COMPONENT TO THIS PROJECT IF THIS PROJECT WILL HAVE CONTINUATION!
	*/
	//std::cout << "Player " << this->turn << (this->turn == 1 ? this->player1->getPlayerType() == true ? " [COMPUTER]" : " [HUMAN 1]" : this->player1->getPlayerType() == true ? " [HUMAN 1]" : " [HUMAN 2]") << ": There Are " << this->pile << " Stones Left. Select 1, 2, Or 3 Stones." << std::endl;
	do
	{
		if (this->turn == 1)
		{
			amt = this->player1->move(this->pile);	
		}
		else
		{
			amt = this->player2->move(this->pile);
		};
		if (amt > 3 || amt < 1)
		{
			std::cout << "Error: Must Select 1, 2, Or 3 Stones. Try Again." << std::endl;
		};
	}while (amt > 3 || amt < 1);
	return amt;
};
int Unanimly::play()
{
	this->turn = 1; //player 1 always starts
	this->pile = 25; //pile starts with 25 stones
	int amt;
	bool gameOver = false;
	while (!gameOver)
	{
		amt = this->callMove();
		this->pile -= amt;
		std::cout << "Player 1 Elects To Take " << amt << " Stones. " << this->pile << " Stones Remain." << std::endl;
		/*
		IMPORTANT: THIS CODE CAN EASILY BE REMOVED THEREFORE IT IS NOT CRITICAL COMPONENT TO THIS PROJECT IF THIS PROJECT WILL HAVE CONTINUATION!
		*/
		//std::cout << "Player " << this->turn << (this->turn == 1 ? this->player1->getPlayerType() == true ? " [COMPUTER]" : " [HUMAN 1]" : this->player1->getPlayerType() == true ? " [HUMAN 1]" : " [HUMAN 2]") << " Elects To Take " << amt << " Stones. " << this->pile << " Stones Remain." << std::endl;
		if (this->pile == 0)
		{
			gameOver = true;
		}
		else
		{
			this->turn = (this->turn == 1 ? 2 : 1);
		};
	};
	return this->turn;
};