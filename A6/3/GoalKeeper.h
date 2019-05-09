#ifndef GOALKEEPER_H
#define GOALKEEPER_H

#include "Player.h"
#include "defines.h"

class GoalKeeper : public Player {
public:
    GoalKeeper(int _dribble, int _pass, int _defence, char _team);
    int getDefencePower(int position);
};

#endif