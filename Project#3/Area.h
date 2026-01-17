// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #3 - In-Game Items - Polymorphism and ADTs
// Date due: 02/23/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
//
//Headers
#ifndef H_AREA
#define H_AREA
//Dependencies
#include "ull.h"
#include "Item.h"
#include <string>
#include <iostream>
//Namespaces
using namespace std;
//Class Declaration
class Area{
  public:
    void setDescription (string);
    void setGoal(bool);
    void setID(bool);
    string getDescription();
    bool getID();
    bool getGoal();
    void displayArea();
    uLList<Item*> items;
    void search();
  private:
     string description;
     bool instadeath;
     bool goal;
};
#endif