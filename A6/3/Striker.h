#ifndef STRIKER_H
#define STRIKER_H

#include "Player.h"
#include "defines.h"

class Striker : public Player {
public:
    Striker(int _dribble, int _pass, int _defence, char _team);
    int getDefencePower(int position);
};

#endif