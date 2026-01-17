#include <iostream>
#include "Player.h"

Player::Player(){
    lastLocation = NULL;
    currentLocation = NULL;
}

void Player::setCurrent(areaNode* loc){
    lastLocation = currentLocation;
    currentLocation = loc;
}

bool Player::playerMoved(){
    return !(lastLocation == currentLocation);
}
areaNode* Player::getCurrent(){
    return currentLocation;
}

//isGameOver should return: 0 for continue, 1 for win, 2 for lose
int Player::isGameOver(){
    return 0;
}
