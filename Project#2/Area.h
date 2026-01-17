// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #2 - In-Game Items - Inheritance
// Date due: 02/07/2025
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
//Class declaration
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