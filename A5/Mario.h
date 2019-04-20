#ifndef MARIO_H
#define MARIO_H

#include "rsdl.hpp"
#include "Game.h"

#define MARIO_STANDING_RIGHT "assets/sprites/mario/normal/standing-right.png"

class Mario {
public:
    Mario(Point pos);
    void draw(Window* win, int winOffset);
    void keypress(char key);

private:

    Point topLeftPos;
    int vx;
    int vy;
    int ay;
    int ax;
};

#endif