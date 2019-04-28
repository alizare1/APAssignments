#ifndef BRICK_BLOCK_H
#define BRICK_BLOCK_H

#include "rsdl.hpp"
#include "blockSize.h"

#define BRICK_BLOCK_PNG "assets/sprites/objects/bricks_blocks/brick.png"

class BrickBlock {
public:
    BrickBlock(Point _position);
    void draw(Window* win, int winOffset);
    Rectangle* getPositionPointer();
private:
    Rectangle position;
};

#endif