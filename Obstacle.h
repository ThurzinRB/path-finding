#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct Position
{
    int xPos, yPos;
};


class Obstacle
{
private:
    int xPos, yPos;

public:
    Obstacle(int x, int y);
    Position getPos();
    int test();
};

#endif