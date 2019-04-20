#include "Map.h"

using namespace std;

Map::Map(Game* _game) {//, Objects* _objects) {
    game = _game;
    // objects = _objects;
}

void Map::initGameSetup() {
    for(int row = 0; row < map.size(); row++){
        processMapRow(map[row], row);
    }
}

void Map::processMapRow(vector<char> mapRow, int row) {
    for (int charIndex = 0 ; charIndex < mapRow.size(); charIndex++){
       processChar(mapRow[charIndex], Point(charIndex, row));
    }
}

void Map::processChar(char c, Point pos) {
    Point pixelPos(pos.x * BLOCK_SIZE
        , pos.y * BLOCK_SIZE );
    switch(c){
        case MARIO: {
            Mario* mario = new Mario(pixelPos);
            game->setMario(mario);
        }
        break;
        // case PIPE: {
        //     Pipe* pipe = new Pipe(pixelPos, 
        //         findPipeHeight(pos.y, pos.x));
        //     objects->addPipe(pipe);
        // }
        // break;
        // case FLAG: {
        //     Flag* flag = new Flag(pixelPos, 
        //         findFlagHeight(pos.y, pos.x));
        //     objects->addFlag(flag);
        // }
        // break;
        // case GROUND_BLOCK: {
        //     NormalBlock* normalBlock = new NormalBlock(pixelPos, 
        //         GROUND_BLOCK);
        //     objects->addNormalBlock(normalBlock);
        // }
        // break;
    }
}

void Map::getMap() {
    string line;
    int k = 0;
    while(getline(cin, line)) {
        map.push_back(vector<char>());
        for(int i = 0; i < line.length(); i++){
            map[map.size() - 1].push_back(line[i]);
        }
    }
}

int Map::findPipeHeight(int headRow, int headCol){
    int i = headRow;
    int height = 0;
    while (map[i][headCol] == PIPE){
        height++;
        map[i][headCol] = EMPTY;
        map[i][headCol + 1] = EMPTY;
        i++;
    }
    return height;
}

int Map::findFlagHeight(int headRow, int headCol){
    int i = headRow;
    int height = 0;
    while (map[i][headCol] == FLAG){
        height++;
        map[i][headCol] = EMPTY;
        i++;
    }
    return height;
}

int Map::getMapHeight(){
    return map.size();
}

