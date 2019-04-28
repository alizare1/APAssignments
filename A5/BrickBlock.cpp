#include "BrickBlock.h"

BrickBlock::BrickBlock (Point _position): 
    position(_position, BLOCK_SIZE, BLOCK_SIZE) {}

void BrickBlock::draw(Window* win, int winOffset) {
    win->draw_img(
        BRICK_BLOCK_PNG,
        Rectangle(position.x - winOffset, position.y , BLOCK_SIZE, BLOCK_SIZE)
    );
}

Rectangle* BrickBlock::getPositionPointer() {
    return &position;
}