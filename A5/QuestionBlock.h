#ifndef QBLOCK_H
#define QBLOCK_H

#include "rsdl.hpp"

#define COIN_BLOCK '?'
#define RED_MUSHROOM_BLOCK 'm'
#define HEALTH_BLOCK 'h'

class QuestionBlock {

private:
    Point position;
    char type;
};

#endif