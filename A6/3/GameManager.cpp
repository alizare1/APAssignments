#include "GameManager.h"

GameManager::GameManager() {
    changeTeamCount = winStatus = 0;
}

std::string GameManager::getResult() {
    if (winStatus == A_WIN)
        return A_WIN_MESSAGE;
    if (winStatus == B_WIN)
        return B_WIN_MESSAGE;
    return DRAW_MESSAGE;
}

void GameManager::play() {
    Player* ballOwner;

    while (changeTeamCount < MAX_CHANGE_TEAM && winStatus == DRAW ) {
        ballOwner = field.getBallOwner();
        decideAction(ballOwner);
        winStatus = field.getWinStatus();
    }
}

void GameManager::decideAction(Player* ballOwner) {
    int distanceFromFriend = distanceFromFriend 
        = field.getDistanceFromFriend(ballOwner);
    
    if(distanceFromFriend == 1)
        field.setBallOwner(field.getNextPlayer(ballOwner));
    else
        performAction(ballOwner, distanceFromFriend);  
}

void GameManager::performAction(Player* ballOwner, int distanceFromFriend) {
    Player* opponent = field.getNextPlayer(ballOwner);
    int opponentDefPow = opponent->getDefencePower(field.getPlayerPosition(opponent));
    
    if (distanceFromFriend == 2) {
        if (ballOwner->getPassPower() > opponentDefPow ) {
            ballOwner->tire();
            field.passBallToFriend();
            return;
        }
    }

    else {
        if (ballOwner->getDribblePower() > opponentDefPow) {
            ballOwner->tire();
            field.swapDribble();
            return;
        }
    }

    field.loseBallToOpponent();
    changeTeamCount++;
}

void GameManager::addTeamAGoalKeeper(int dribble, int pass, int defend) {
    GoalKeeper* gk = new GoalKeeper(dribble, pass, defend, TEAM_A);
    field.addPlayer(gk, GOAL_R);
    field.setBallOwner(gk);
}

void GameManager::addTeamADefender(int dribble, int pass, int defend) {
    field.addPlayer(new Defender(dribble, pass, defend, TEAM_A), DEF_R );
}

void GameManager::addTeamAStriker(int dribble, int pass, int defend) {
    field.addPlayer(new Striker(dribble, pass, defend, TEAM_A), MID_R );
}

void GameManager::addTeamBGoalKeeper(int dribble, int pass, int defend) {
    field.addPlayer(new GoalKeeper(dribble, pass, defend, TEAM_B), GOAL_L );
}

void GameManager::addTeamBDefender(int dribble, int pass, int defend) {
    field.addPlayer(new Defender(dribble, pass, defend, TEAM_B), DEF_L );
}

void GameManager::addTeamBStriker(int dribble, int pass, int defend) {
    field.addPlayer(new Striker(dribble, pass, defend, TEAM_B), MID_L );
}