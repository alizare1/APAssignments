#include "Mario.h"
#include <iostream>
using namespace std;


Mario::Mario(Point pos): topLeftPos(pos) {
    ay = X_ACCELERATION;
}

void Mario::draw(Window* win, int winOffset) {
    win->draw_img(MARIO_NORMAL_STAND_R,
     Rectangle(topLeftPos.x - winOffset, topLeftPos.y,
      BLOCK_SIZE, BLOCK_SIZE));
}

void Mario::handleKeyPress(char key) {
    switch (key) {
        case 'd':
            moveRight();
            break;
        case 'a':
            vx = -X_SPEED;
            break;
    }
}

void Mario::handleKeyRelease(char key) {
    switch (key) {
        case 'd':
            vx = 0;
            break;
        case 'a':
            vx = 0;
            break;
    }
}

void Mario::moveRight() {
    vx = X_SPEED;
}

void Mario::stopRight() {
    vx = 0;
}

void Mario::update(){
    topLeftPos.x += vx;
}

Point Mario::getPosition() {
    return topLeftPos;
}

int Mario::getXSpeed() {
    return X_SPEED;
}
