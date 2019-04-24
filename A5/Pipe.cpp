#include "Pipe.h"
#include <iostream>

Pipe::Pipe(Point headLeftPos, int _height)
    :headLeftPosition(headLeftPos), height(_height) {
}

void Pipe::draw(Window* win, int winOffset) {
    drawHead(win, winOffset);
    if (height > 1)
        drawBody(win, winOffset);
}

void Pipe::drawHead(Window* win, int winOffset) {
    win->draw_img(PIPE_HEAD_L,
        Rectangle(headLeftPosition.x - winOffset, headLeftPosition.y,
        BLOCK_SIZE, BLOCK_SIZE));
    win->draw_img(PIPE_HEAD_R,
        Rectangle(headLeftPosition.x - winOffset + BLOCK_SIZE, headLeftPosition.y,
        BLOCK_SIZE, BLOCK_SIZE));
}

void Pipe::drawBody(Window* win,int winOffset) {
    for (int i = 1; i < height; i++) {
        win->draw_img(PIPE_BODY_L,
            Rectangle(headLeftPosition.x - winOffset, headLeftPosition.y + i * BLOCK_SIZE,
            BLOCK_SIZE, BLOCK_SIZE));
        win->draw_img(PIPE_BODY_R,
            Rectangle(headLeftPosition.x - winOffset + BLOCK_SIZE, headLeftPosition.y + i * BLOCK_SIZE,
            BLOCK_SIZE, BLOCK_SIZE));
    }
}
