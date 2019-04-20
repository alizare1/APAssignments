#ifndef GAME_H
#define GAME_H

#include "rsdl.hpp"
#include <vector>
#include <iostream>
#include "Map.h"
// #include "Objects.h"

#define BLOCK_SIZE 40
#define GAME_NAME "Super Mario"
#define BACKGROUND "assets/background_image.png"
#define BACKGROUND_HEIGHT 1000


class Mario;

class Game{
public:
    Game();
    void run();
    void setMario(Mario* _mario);

private:
    void drawScreen();
    void setBackground();
    void processEvents();
    void updateObjects();

    Mario* mario;
    // Objects objects;
    Window* win;
    int winOffset;
    bool runn;

};

#endif