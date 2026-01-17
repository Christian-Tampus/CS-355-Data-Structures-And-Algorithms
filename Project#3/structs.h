// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #3 - In-Game Items - Polymorphism and ADTs
// Date due: 02/23/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
#ifndef H_STRUCTS
#define H_STRUCTS
struct Rule
{
	int beginRm;
	char direction;
	int destRm;
};
struct Effect
{
	int effectID;
	int effectAmt;
};
#endif