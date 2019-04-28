#include "Game.h"

using namespace std;

Game::Game(string mapAdress) {
    collisionHandler = new CollisionHandler();
    objects = new Objects(collisionHandler);
    Map map(this, objects);
    map.readMap(mapAdress);
    map.initGameSetup();
    camera = new Camera( WINDOW_WIDTH * BLOCK_SIZE,
       map.getMapHeight() * BLOCK_SIZE, GAME_NAME);
    gameStep = 0;
}


void Game::run() {
    objects->setScreenWith(camera->getWidth());
    while(gameRunning) {
        processEvents();
        collisionHandler->handleCollisions();
        updateObjects();
        drawScreen(gameStep);
        gameStep++;
        delay(30);
    }
}

void Game::updateObjects() {
    mario->update();
    objects->update();
    camera->updateOffsets(mario->getPosition().x, mario->getVx());
}

void Game::processEvents() {
    while(camera->getWindow()->has_pending_event()) {
        Event e = camera->getWindow()->poll_for_event();
        switch (e.get_type()) {
        case Event::KEY_PRESS:
            mario->handleKeyPress(e.get_pressed_key());
            break;
        case Event::KEY_RELEASE:
            mario->handleKeyRelease(e.get_pressed_key());
            break;
        case Event::QUIT:
            exit(0);
            break;
        }
    }
}

void Game::drawScreen(int step){
    camera->clearScreen();
    camera->setBackground();
    objects->draw(camera->getWindow(), camera->getWinOffset(), step);
    mario->draw(camera->getWindow(), camera->getWinOffset(), step);
    camera->updateScreen();
}

void Game::setMario(Mario* _mario) {
    mario = _mario;
    collisionHandler->setMario(_mario);
}

int Game::getWinHeight() {
    return camera->getHeight();
}

void Game::resetOffset() {
    camera->resetOffset();
}

void Game::lose() {
    gameRunning = false;
    drawScreen(gameStep);
    camera->lose();
}

void Game::win() {
    gameRunning = false;
    drawScreen(gameStep);
    camera->won();
}

int Game::getWinOffset() {
    return camera->getWinOffset();
}