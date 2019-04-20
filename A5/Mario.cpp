#include "Mario.h"


Mario::Mario(Point pos): topLeftPos(pos) {
    
}

void Mario::draw(Window* win, int winOffset) {
    win->fill_circle(topLeftPos, 20);
    // win->draw_img(MARIO_STANDING_RIGHT,
    //  Rectangle(topLeftPos.x - winOffset, topLeftPos.y, 
    //   topLeftPos.x - winOffset + BLOCK_SIZE, topLeftPos.y + BLOCK_SIZE));
}