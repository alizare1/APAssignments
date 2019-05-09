#ifndef MY_GAME_MANAGER_H
#define MY_GAME_MANAGER_H

#include <string>
#include "Field.h"
#include "Player.h"
#include "GoalKeeper.h"
#include "Defender.h"
#include "Striker.h"
#include "defines.h"

class GameManager {
public:
    GameManager();
    void addTeamAGoalKeeper(int dribble, int pass, int defend);
    void addTeamADefender(int dribble, int pass, int defend);
    void addTeamAStriker(int dribble, int pass, int defend);
    void addTeamBGoalKeeper(int dribble, int pass, int defend);
    void addTeamBDefender(int dribble, int pass, int defend);
    void addTeamBStriker(int dribble, int pass, int defend);
    void play();
    std::string getResult();
private:
    void decideAction(Player* ballOwner);
    void performAction(Player* ballOwner, int distanceFromFriend);

    int winStatus;
    Field field;
    int changeTeamCount;
};


#endif