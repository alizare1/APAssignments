#include "Player.h"

Player::Player(int _dribble, int _pass, int _defence, char _team) {
    dribble = _dribble;
    pass = _pass;
    defence = _defence;
    team = _team;
}

int Player::getPassPower() {
    return pass;
}

int Player::getDribblePower() {
    return dribble;
}

char Player::whichTeam() {
    return team;
}

void Player::tire() {
    dribble >= 10 ? dribble -= 10 : dribble = 0;
    pass >= 10 ? pass -= 10 : pass = 0;
    defence >= 10 ? defence -= 10 : defence = 0;
}