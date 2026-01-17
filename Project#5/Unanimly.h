// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project#5 - Unanimly
// Date due: 04/06/2025
// Description: Its basically nim...
// ---------------------------------------------------------------------------
#ifndef H_UNANIMLY
#define H_UNANIMLY
#include <iostream>
#include "UnanimlyPlayer.h"
using namespace std;
class Unanimly
{
	private:
		UnanimlyPlayer* player1;
		UnanimlyPlayer* player2;
		int pile;
		int turn;
	public:
		Unanimly();
		/*
		IMPORTANT: THIS CODE CAN EASILY BE REMOVED THEREFORE IT IS NOT CRITICAL COMPONENT TO THIS PROJECT IF THIS PROJECT WILL HAVE CONTINUATION!
		*/
		//Unanimly(int);
		int callMove();
		int play();
};
#endif