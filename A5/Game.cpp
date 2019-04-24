#include "Game.h"

using namespace std;

Game::Game(string mapAdress) {
    objects = Objects();
    Map map(this, &objects);
    map.getMap(mapAdress);
    map.initGameSetup();
    win = new Window((map.getMapHeight() + 10) * BLOCK_SIZE,
       map.getMapHeight() * BLOCK_SIZE, GAME_NAME);
    winOffset = backgroundOffset = 0;
    quit = false;
}

void Game::run() {
    while(!quit) {
        processEvents();
        updateObjects();
        drawScreen();
        delay(10);
    }
}

void Game::updateObjects() {
    mario->update();
    updateOffSet();
}

void Game::processEvents() {
    while(win->has_pending_event()){
        Event e = win->poll_for_event();
        switch (e.get_type()) {
        case Event::KEY_PRESS:
            mario->handleKeyPress(e.get_pressed_key());
            break;
        case Event::KEY_RELEASE:
            mario->handleKeyRelease(e.get_pressed_key());
            break;
        case Event::QUIT:
            quit = true;
            break;
        }
    }
}

void Game::drawScreen(){
    win->clear();
    setBackground();
    objects.draw(win, winOffset);
    mario->draw(win, winOffset);
    win->update_screen();
}

void Game::setBackground() {
    if (backgroundOffset >= BACKGROUND_WIDTH)
        backgroundOffset = 0;
    if (win->get_width() + backgroundOffset >= BACKGROUND_WIDTH) {
        int prevBGWidth = BACKGROUND_WIDTH - backgroundOffset;
        int newBGWidth = win->get_width() - prevBGWidth;
        win->draw_img(BACKGROUND,
            Rectangle(0, 0, prevBGWidth, win->get_height()),
            Rectangle(backgroundOffset, BACKGROUND_HEIGHT - win->get_height(),
            prevBGWidth , win->get_height())
        );
        win->draw_img(BACKGROUND,
            Rectangle(prevBGWidth, 0, newBGWidth, win->get_height()),
            Rectangle(0, BACKGROUND_HEIGHT - win->get_height(),
            newBGWidth, win->get_height())
        );
    }
    else {
        win->draw_img(BACKGROUND, NULL_RECT,
            Rectangle(Point(backgroundOffset, BACKGROUND_HEIGHT - win->get_height()),
            win->get_width(), win->get_height())
        );
    }
}

void Game::updateOffSet() {
    if (mario->getPosition().x - winOffset > win->get_width() / 2) {
        winOffset += mario->getXSpeed();
        backgroundOffset += mario->getXSpeed();
    }
}

void Game::setMario(Mario* _mario) {
    mario = _mario;
}
