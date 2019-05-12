#include "Striker.h"

Striker::Striker(int _dribble, int _pass, int _defence, char _team)
    : Player(_dribble, _pass, _defence, _team) {}

int Striker::getDefencePower(int position) {
    if (position == DEF_L || position == DEF_R)
        return SDEF_VS_G_MULTI * defence;
    if (position == MID_L) {
        if (team == TEAM_B)
            return defence + S_VS_S_ADD;
        else
            return defence + SDEF_VS_D_ADD;
    }
    if (position == MID_R) {
        if (team == TEAM_A)
            return defence + S_VS_S_ADD;
        else 
            return defence + SDEF_VS_D_ADD;
    }
}
