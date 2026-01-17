// ---------------------------------------------------------------------------
// Name: Christian Tampus
// Course-Section: CS-355-01
// Assignment: Project #2 - In-Game Items - Inheritance
// Date due: 02/07/2025
// Description: This program is the IF (Interactive Fiction) game engine that can parse/handle any .IFD formated game files.
// ---------------------------------------------------------------------------
#ifndef H_MAP
#define H_MAP
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "areaNode.h"
#include "IFDParser.h"
#include "LinkData.h"
#include "Area.h"
using namespace std;
class Map{
	protected:
		vector<areaNode*> areasVec;
		int areacnt;
		//Here is the instance of IFDParser
	  	IFDParser parser;
		//Some additional class attributes here
        vector<LinkData*> linkVec;
		string nextToken;
		bool ifderr;
	public:
	    Map();
	    void buildMap();
		void makeArea();
		void makeLinks();
		void linkLinks();
		areaNode* getStart();
		//void print();
		int reverseLookUp(areaNode*);
		friend ostream& operator<<(ostream&, Map&);
};
#endif