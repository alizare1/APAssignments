#include "Flag.h"

Flag::Flag(Point headPos, int _height)
    :headPosition(headPos), height(_height) {}

void Flag::draw(Window* win, int winOffset) {
    drawHead(win, winOffset);
    if (height > 1)
        drawBody(win, winOffset);
}

void Flag::drawHead(Window* win, int winOffset) {
    win->draw_img(FLAG_HEAD_PNG,
        Rectangle(headPosition.x - winOffset, headPosition.y,
        BLOCK_SIZE, BLOCK_SIZE));
}

void Flag::drawBody(Window* win, int winOffset) {
    for (int i = 1; i < height; i++)
        win->draw_img(FLAG_BODY_PNG,
            Rectangle(headPosition.x - winOffset, headPosition.y + i * BLOCK_SIZE,
            BLOCK_SIZE, BLOCK_SIZE));
}
