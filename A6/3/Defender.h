#ifndef DEFENDER_H
#define DEFENDER_H

#include "Player.h"
#include "defines.h"

class Defender : public Player {
public:
    Defender(int _dribble, int _pass, int _defence, char _team);
    int getDefencePower(int position);
};


#endif