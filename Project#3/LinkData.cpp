// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #3 - In-Game Items - Polymorphism and ADTs
// Date due: 02/23/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
#include <iostream>
#include "LinkData.h"
void LinkData::setDigits(int u, int d, int l, int r)
{
    //u,l,d,r
    digits[0] = u;
    digits[1] = d;
    digits[2] = l;
    digits[3] = r;
}
int LinkData::getDigit(int pos)
{
    return digits[pos];
}