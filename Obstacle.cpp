#include <iostream>
#include "Obstacle.h"
// #include "Position.h"




Obstacle::Obstacle(int x, int y)
{
    xPos = x;
    yPos = y;
}
Position Obstacle::getPos(){
    Position temp;
    temp.xPos = xPos;
    temp.yPos = yPos;
    return temp;
}
int Obstacle::test(){
    return 2;
}
