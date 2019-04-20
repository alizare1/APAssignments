#include "Game.h"

using namespace std;

Game::Game() {
    //objects = Objects();
    Map map(this);//, &objects);
    map.getMap();
    map.initGameSetup();
    win = new Window((map.getMapHeight() + 10) * BLOCK_SIZE,
       map.getMapHeight() * BLOCK_SIZE, GAME_NAME);
    winOffset = 0;
    
}

void Game::run(){
    runn = true;
    while(runn) {
        processEvents();
        updateObjects();
        drawScreen();
        delay(100);
    }
}

void Game::updateObjects() {

}

void Game::processEvents() {
    while(win->has_pending_event()){
        Event e = win->poll_for_event();
        switch (e.get_type()) {
        case Event::KEY_RELEASE:
            cout << e.get_pressed_key();
            break;
        case Event::KEY_PRESS:
            
        case Event::QUIT:
            runn = false;
            break;
        }
    }
}

void Game::drawScreen(){
    win->clear();
    setBackground();
    mario->draw(win, winOffset);
    // cout << win->get_height() << '/' << win->get_width();
    win->update_screen();
}

void Game::setBackground(){
    // win->draw_img(BACKGROUND, NULL_RECT, 
    //     Rectangle(Point(winOffset, BACKGROUND_HEIGHT - win->get_height()),
    //     Point(win->get_width() + winOffset, 0))
    //     );
    win->draw_img(BACKGROUND);
}

void Game::setMario(Mario* _mario) {
    mario = _mario;
}

