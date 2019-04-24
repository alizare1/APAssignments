#include <stdio.h>
#include <string>
#include <vector>
#include "Game.h"




int main(int argc, char* argv[]){
    Game game(argv[1]);
    game.run();
    return 0;
}
