#include "NormalBlock.h"

NormalBlock::NormalBlock(Point pos, char _type)
    :position(pos), type(_type) {}

void NormalBlock::draw(Window* win, int winOffset) {
    if (type == GROUND_BLOCK)
        win->draw_img(GROUND_BLOCK_PNG,
            Rectangle(position.x - winOffset, position.y , BLOCK_SIZE, BLOCK_SIZE));
}
