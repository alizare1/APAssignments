#ifndef NORMAL_BLOCK_H
#define NORMAL_BLOCK_H

#include "rsdl.hpp"

#define GROUND_BLOCK '#'
#define NORMAL_BLOCK '@'

class NormalBlock {
public:
    NormalBlock(Point pos, char _type);

private:
    Point position;
    char type;
};

#endif