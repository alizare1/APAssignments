#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(int _dribble, int _pass, int _defence, char _team);
    int getPassPower();
    int getDribblePower();
    virtual int getDefencePower(int position) = 0;
    char whichTeam();
    void tire();

protected:
    int defence;
    int pass;
    int dribble;
    char team;

};

#endif