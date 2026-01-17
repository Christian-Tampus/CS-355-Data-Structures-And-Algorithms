// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #3 - In-Game Items - Polymorphism and ADTs
// Date due: 02/23/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
#ifndef H_AREANODE
#define H_AREANODE
#include "Area.h"
struct areaNode
{
	Area info;
	areaNode *u;
	areaNode *d;
	areaNode *l;
	areaNode *r;
};
#endif