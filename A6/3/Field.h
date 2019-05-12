#ifndef FIELD_H
#define FIELD_H

#include "Player.h"
#include "defines.h"
#include <array>

class Field {
public:
    Field();
    void addPlayer(Player* player, int position);
    void setBallOwner(Player*);
    Player* getBallOwner();
    Player* getNextPlayer(Player* player);
    int getDistanceFromFriend(Player* player);
    int getPlayerPosition(Player*);
    void loseBallToOpponent();
    void passBallToFriend();
    void swapDribble();
    int getWinStatus();
private:

    std::array<Player*, FIELD_SIZE> field;
    Player* ballOwner;
};

#endif