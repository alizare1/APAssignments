#include "GoalKeeper.h"

GoalKeeper::GoalKeeper(int _dribble, int _pass, int _defence, char _team)
    : Player(_dribble, _pass, _defence, _team) {}

int GoalKeeper::getDefencePower(int position) {
    return G_VS_S_MULTI * defence;
}