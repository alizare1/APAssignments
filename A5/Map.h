#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include <iostream>
#include "rsdl.hpp"
#include "Game.h"
#include "Objects.h"
#include "Mario.h"

#define MARIO 'M'
#define PIPE '|'
#define FLAG 'f'
#define EMPTY '.'
#define SIMPLE_BRICK 'b'
#define COIN_BLOCK '?'
#define RED_MUSHROOM_BLOCK 'm'
#define HEALTH_BLOCK 'h'
#define GROUND_BLOCK '#'
#define NORMAL_BLOCK '@'

class Game;

class Map {
public:
    Map(Game* _game, Objects* _objects);
    void getMap();
    void initGameSetup();
    int getMapHeight();

private:
    void processMapRow(std::vector<char>& mapRow, int row);
    void processChar(char c, Point pos);
    int findPipeHeight(int headRow, int headCol);
    void clearPipe(int headRow, int headCol);
    int findFlagHeight(int headRow, int headCol);

    std::vector<std::vector<char>> map;
    Objects* objects;
    Game* game;
};

#endif
