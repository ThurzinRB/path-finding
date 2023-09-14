#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <vector>
#include "Obstacle.h"

bool isObstacle(int x, int y, std::vector<Obstacle> obsVec) {
    // cout<<"Size"+to_string(obsVec.size())<<endl;
    for (int i = 0; i < obsVec.size(); i++) {
        // cout<<"i: "+ to_string(i) + "xPos: "+ to_string(i)<<endl;
        if (x == obsVec[i].getPos().xPos && y == obsVec[i].getPos().yPos)
            return true;
    }
    return false;
}

#endif
