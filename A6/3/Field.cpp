#include "Field.h"

#include <iostream>

Field::Field() {
}

void Field::addPlayer(Player* player, int position) {
    field[position] = player;
}

void Field::setBallOwner(Player* player) {
    ballOwner = field[getPlayerPosition(player)];
}

Player* Field::getBallOwner() {
    return ballOwner;
}

int Field::getPlayerPosition(Player* player) {
    for (int i = 0; i < field.size(); i++) {
        if (field[i] == player)
            return i;
    }
}

int Field::getDistanceFromFriend(Player* player) {
    int position = getPlayerPosition(player);

    if (player->whichTeam() == TEAM_A) {
        for (int i = position; i > 0; i--)
            if (field[i]->whichTeam() == TEAM_A)
                return position - i;
    }

    else {
        for (int i = position; i < field.size() ; i++)
            if (field[i]->whichTeam() == TEAM_B)
                return i - position;
    }

    return NO_FRIEND;
}

Player* Field::getNextPlayer(Player* player) {
    if (player->whichTeam() == TEAM_A)
        return field[getPlayerPosition(player) - 1];
    else
        return field[getPlayerPosition(player) + 1];
}

void Field::loseBallToOpponent() {
    ballOwner = getNextPlayer(ballOwner);
}

void Field::passBallToFriend() {
    if (ballOwner->whichTeam() == TEAM_A)
        ballOwner = field[getPlayerPosition(ballOwner) - 2];
    else
        ballOwner = field[getPlayerPosition(ballOwner) + 2];
}

void Field::swapDribble() {
    int opponentPosition = getPlayerPosition(getNextPlayer(ballOwner));
    field[getPlayerPosition(ballOwner)] = getNextPlayer(ballOwner);
    field[opponentPosition] = getBallOwner();
}

int Field::getWinStatus() {
    if (field[GOAL_L]->whichTeam() == TEAM_A)
        return A_WIN;
    if (field[GOAL_R]->whichTeam() == TEAM_B)
        return B_WIN;
    return DRAW;
}
