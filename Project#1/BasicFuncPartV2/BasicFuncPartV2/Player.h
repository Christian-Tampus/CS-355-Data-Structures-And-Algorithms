#include "areaNode.h"

class Player{
  public:
    Player();
	void setCurrent(areaNode*);
	bool playerMoved();
	areaNode* getCurrent();
	//isGameOver should return: 0 for continue, 1 for win, 2 for lose
	int isGameOver();

  private:
		areaNode* currentLocation;
		areaNode* lastLocation;
};
