#ifndef COLLISION_DETECTOR_H
#define COLLISION_DETECTOR_H

#include "Objects.h"
#include "rsdl.hpp"
#include <vector>
#include "Mario.h"
#include "QuestionBlock.h"
#include "BrickBlock.h"
#include "LittleGoomba.h"


#define ESTIMATION_Y 20
#define ESTIMATION_X 3

class Mario;

// ----------------- WRITE MOVING COLLISON BY ENEMIES NOT MARIO -----------------

// if have y in common before and after its right or left and vica versa
// check x and y seperatedly before and after adding V. then compare and decide

class CollisionHandler {
public:
    enum CollisionType {
        RIGHT,
        LEFT,
        UP,
        DOWN,
        DIE,
        NONE
    };
    void setMario(Mario* _mario);
    void addStaticObjects(Rectangle* position);
    void addNormalBlock(Rectangle* position);
    void addQuestionBlock(QuestionBlock* _QBlock);
    void addBrickBlock(BrickBlock* _brickBlock);
    void addGoomba(LittleGoomba* _goomba);
    void addKoopa(KoopaTroopa* _koopa);
    void handleCollisions();

private:
    struct ColMario {
        Mario* mario;
        Rectangle* position;
        bool* collidesDown;
    };
    struct ColQBlock {
        QuestionBlock* QBlock;
        Rectangle* position;
    };
    struct ColBrickBlock {
        BrickBlock* brickBlock;
        Rectangle* position;
    };
    struct ColGoomba {
        LittleGoomba* goomba;
        Rectangle* position;
        bool* collidesDown;
    };
    struct ColKoopa {
        KoopaTroopa* koopa;
        Rectangle* position;
        bool* collidesDown;
    };

    void handleMarioStaticObjectsCollision();
    void handleMarioQBlocksCollision();
    void handleMarioBricksCollision();
    void handleMario(CollisionType collision);
    void checkGoombas();
    void handleGoomba(ColGoomba* goomba, CollisionType collision);
    void handleGoombasStaticObjsCollision(ColGoomba* goomba);
    void handleGoombasQBlocksCollision(ColGoomba* goomba);
    void handleGoombasBricksCollision(ColGoomba* goomba);
    void checkKoopas();
    void handleKoopa(ColKoopa* koopa, CollisionType collision);
    void handleKoopasStaticObjsCollision(ColKoopa* koopa);
    void handleKoopasQBlocksCollision(ColKoopa* koopa);
    void handleKoopasBricksCollision(ColKoopa* koopa);
    CollisionType collides(Rectangle* mainObj, int vx, int vy, Rectangle* obj);
    int getRx(Rectangle* rect);
    int getBy(Rectangle* rect);

    ColMario mario;
    std::vector<Rectangle*> staticObjects;
    std::vector<ColQBlock*> questionBlocks;
    std::vector<ColBrickBlock*> brickBlocks;
    std::vector<ColGoomba*> goombas;
    std::vector<ColKoopa*> koopas;    
};


#endif