#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include "Game.h"

using namespace std;

vector<vector<char>> readFile(string fileAdress);

int main(int argc, char* argv[]){
    Game game(argv[1]);
    game.run();
    return 0;
}

// Win/lose die flag collision
// fall down the screen (check dead before so dont die twice)
// enemy collision ****** there is an idea in file
// mushroom
// reset offset
// add sound
// breaking blocks, killing enemies by them (collision static up)