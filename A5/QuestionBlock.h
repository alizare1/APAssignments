#ifndef QBLOCK_H
#define QBLOCK_H

#include "rsdl.hpp"

#define Q_BLOCK_1 "assets/sprites/objects/bricks_blocks/question-1.png"
#define Q_BLOCK_2 "assets/sprites/objects/bricks_blocks/question-2.png"
#define Q_BLOCK_3 "assets/sprites/objects/bricks_blocks/question-3.png"
#define Q_BLOCK_EMPTY "assets/sprites/objects/bricks_blocks/question-empty.png"

#define COIN_BLOCK '?'
#define RED_MUSHROOM_BLOCK 'm'
#define HEALTH_BLOCK 'h'

class QuestionBlock {
public:
    QuestionBlock(Point pos, char _type);
    void draw(Window* win, int winOffset);

private:
    Point position;
    char type;
};

#endif
