#include "game_manager.h"

void game_manager::add_team_A_goalkeeper(int stamina, int dribble, int pass, int defend) {
    gameManager.addTeamAGoalKeeper(dribble, pass, defend);
}

void game_manager::add_team_A_defender(int stamina, int dribble, int pass, int defend) {
    gameManager.addTeamADefender(dribble, pass, defend);
}

void game_manager::add_team_A_striker(int stamina, int dribble, int pass, int defend) {
    gameManager.addTeamAStriker(dribble, pass, defend);
}

void game_manager::add_team_B_goalkeeper(int stamina, int dribble, int pass, int defend) {
    gameManager.addTeamBGoalKeeper(dribble, pass, defend);
}

void game_manager::add_team_B_defender(int stamina, int dribble, int pass, int defend) {
    gameManager.addTeamBDefender(dribble, pass, defend);
}

void game_manager::add_team_B_striker(int stamina, int dribble, int pass, int defend) {
    gameManager.addTeamBStriker(dribble, pass, defend);
}

void game_manager::play() {
    gameManager.play();
}

std::string game_manager::get_result() {
    return gameManager.getResult();
}