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
	private:
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
		void makeArea();
		void makeLinks();
		void linkLinks();
		areaNode* getStart();
		void print();
		int reverseLookUp(areaNode*);
};
