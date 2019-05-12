#include "Defender.h"

Defender::Defender(int _dribble, int _pass, int _defence, char _team)
    : Player(_dribble, _pass, _defence, _team) {}

int Defender::getDefencePower(int position) {
    if (position == MID_L || position == MID_R)
        return defence + D_VS_D_ADD;
    else
        return defence;
}