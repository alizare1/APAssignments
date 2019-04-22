#ifndef NORMAL_BLOCK_H
#define NORMAL_BLOCK_H

#include "rsdl.hpp"
#include "blockSize.h"

#define GROUND_BLOCK '#'
#define NORMAL_BLOCK '@'

#define GROUND_BLOCK_PNG "assets/sprites/objects/bricks_blocks/clay.png"

class NormalBlock {
public:
    NormalBlock(Point pos, char _type);
    void draw(Window* win, int winOffset);
private:
    Point position;
    char type;
};

#endif
