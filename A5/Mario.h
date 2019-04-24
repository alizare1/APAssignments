#ifndef MARIO_H
#define MARIO_H

#include "rsdl.hpp"
#include "blockSize.h"

#define X_SPEED 14
#define X_ACCELERATION 5

#define MARIO_NORMAL_STAND_R "assets/sprites/mario/normal/standing-right.png"
#define MARIO_NORMAL_WALK_R_1 "assets/sprites/mario/normal/walking-right-1.png"
#define MARIO_NORMAL_WALK_R_2 "assets/sprites/mario/normal/walking-right-2.png"
#define MARIO_NORMAL_WALK_R_3 "assets/sprites/mario/normal/walking-right-3.png"

class Mario {
public:
    Mario(Point pos);
    void draw(Window* win, int winOffset);
    void handleKeyPress(char key);
    void handleKeyRelease(char key);
    void update();
    Point getPosition();
    int getXSpeed();

private:
    void moveRight();
    void stopRight();

    Point topLeftPos;
    int vx;
    int vy;
    int ay;
    int ax;
};

#endif
