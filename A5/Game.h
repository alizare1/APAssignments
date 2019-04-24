#ifndef GAME_H
#define GAME_H

#include "rsdl.hpp"
#include <vector>
#include <iostream>
#include <string>
#include "Map.h"
#include "Objects.h"
#include "blockSize.h"


#define GAME_NAME "Super Mario"
#define BACKGROUND "assets/background_image.png" // move screen
#define BACKGROUND_HEIGHT 1000 // move screen
#define BACKGROUND_WIDTH 2000 // move screen

// collision handler with all coords.

class Mario;

class Game {
public:
    Game(std::string mapAdress);
    void run();
    void setMario(Mario* _mario);

private:
    void drawScreen();
    void setBackground(); // move to screen
    void processEvents();
    void updateObjects();
    void updateOffSet();

    Mario* mario;
    Objects objects;
    Window* win; // move to screen
    int winOffset; // move to screen ?
    int backgroundOffset; // move screen
    bool quit;

};

#endif
