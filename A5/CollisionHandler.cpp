#include "CollisionHandler.h"

void CollisionHandler::setMario(Mario* _mario) {
    mario.mario = _mario;
    mario.position = mario.mario->getPositionPointer();
    mario.collidesDown = mario.mario->getDownCollisionPointer();
}

#include <iostream>

CollisionHandler::CollisionType CollisionHandler::collides(Rectangle* mainObj, int vx, int vy, Rectangle* obj) {
    if ((mainObj->y >= obj->y && mainObj->y < getBy(obj))
    || (getBy(mainObj) <= getBy(obj) && getBy(mainObj) > obj->y)
    ||  (getBy(mainObj) + vy > obj->y && vy > 0) ) {
        if (getRx(mainObj) <= obj->x && getRx(mainObj) + vx >= obj->x) {
            mainObj->x = obj->x - mainObj->w;
            return RIGHT;
        }
        if (mainObj->x >= getRx(obj) && mainObj->x + vx < getRx(obj)) {
            mainObj->x = obj->x + obj->w;
            return LEFT;
        }
    }
    if ((mainObj->x >= obj->x && mainObj->x < getRx(obj))
    || (getRx(mainObj) <= getRx(obj) && getRx(mainObj) > obj->x)) {
        if (getBy(mainObj) <= obj->y && getBy(mainObj) + vy >= obj->y) {
            mainObj->y = obj->y - mainObj->h;
            return DOWN;
        }
        if (mainObj->y >= getBy(obj) && mainObj->y + vy <= getBy(obj)) {
            mainObj->y = obj->y + obj->h;
            return UP;
        }
    }
    return NONE;
}

int CollisionHandler::getRx(Rectangle* rect) {
    return rect->x + rect->w;
}

int CollisionHandler::getBy(Rectangle* rect) {
    return (rect->y + rect->h);
}

void  CollisionHandler::handleMario(CollisionType collision) {
    switch (collision) {
            case RIGHT:
            case LEFT:
                mario.mario->setVx(0);
                break;
            case UP:
                mario.mario->setVy(0);
                break;
            case DOWN:
                mario.mario->setVy(0);
                *mario.collidesDown = true;
                break; 
        }
}

void CollisionHandler::handleCollisions() {
    if (!mario.mario->isAlive())
        return;
    *mario.collidesDown = false;
    handleMarioQBlocksCollision();
    handleMarioStaticObjectsCollision();
    handleMarioBricksCollision();
    checkGoombas();
    checkKoopas();
}

void CollisionHandler::handleMarioStaticObjectsCollision() {
    for (int i = 0; i < staticObjects.size(); i++) {
        CollisionType collision = collides(mario.position, mario.mario->getVx(), mario.mario->getVy(), staticObjects[i]);
        handleMario(collision);
    }
}

void CollisionHandler::handleMarioQBlocksCollision() {
    for (int i = 0; i < questionBlocks.size(); i++) {
        CollisionType collision = collides(mario.position, mario.mario->getVx(), mario.mario->getVy(), questionBlocks[i]->position);
        handleMario(collision);
        if (collision == UP) {
            char blockType = questionBlocks[i]->QBlock->hit();
            switch (blockType) {
                case COIN_BLOCK:
                    mario.mario->addCoin();
            }
        }
    }
}

void CollisionHandler::handleMarioBricksCollision() {
    for (int i = 0; i < brickBlocks.size(); i++) {
        CollisionType collision = collides(mario.position, mario.mario->getVx(), mario.mario->getVy(), brickBlocks[i]->position);
        handleMario(collision);
    }
}

void CollisionHandler::handleGoomba(ColGoomba* goomba, CollisionType collision) {
    switch (collision) {
        case LEFT:
        case RIGHT:
            goomba->goomba->setVx(-goomba->goomba->getVx());
            break;
        case DOWN:
            *goomba->collidesDown = true;
            goomba->goomba->setVy(0);
            break;
    }
}

void CollisionHandler::checkGoombas() {
    for (int i = 0; i < goombas.size(); i++) {
        handleGoombasStaticObjsCollision(goombas[i]);
        handleGoombasQBlocksCollision(goombas[i]);
        handleGoombasBricksCollision(goombas[i]);
    }
}


void CollisionHandler::handleGoombasStaticObjsCollision(ColGoomba* goomba) {
    *goomba->collidesDown = false;
    for (int i = 0; i < staticObjects.size(); i++) {
        CollisionType collision = collides(goomba->position, goomba->goomba->getVx(), goomba->goomba->getVy(), staticObjects[i]);
        handleGoomba(goomba , collision);
    }
}

void CollisionHandler::handleGoombasQBlocksCollision(ColGoomba* goomba) {
    for (int i = 0; i < questionBlocks.size(); i++) {
        CollisionType collision = collides(goomba->position, goomba->goomba->getVx(), goomba->goomba->getVy(), questionBlocks[i]->position);
        handleGoomba(goomba , collision);
    }
}

void CollisionHandler::handleGoombasBricksCollision(ColGoomba* goomba) {
    for (int i = 0; i < brickBlocks.size(); i++) {
        CollisionType collision = collides(goomba->position, goomba->goomba->getVx(), goomba->goomba->getVy(), brickBlocks[i]->position);
        handleGoomba(goomba , collision);
    }
}

void CollisionHandler::checkKoopas() {
    for (int i = 0; i < koopas.size(); i++) {
        handleKoopasStaticObjsCollision(koopas[i]);
        handleKoopasQBlocksCollision(koopas[i]);
        handleKoopasBricksCollision(koopas[i]);
    }
}

void CollisionHandler::handleKoopa(ColKoopa* koopa, CollisionType collision) {
    switch (collision) {
        case LEFT:
        case RIGHT:
            koopa->koopa->setVx(-koopa->koopa->getVx());
            break;
        case DOWN:
            *koopa->collidesDown = true;
            koopa->koopa->setVy(0);
            break;
    }
}
void CollisionHandler::handleKoopasStaticObjsCollision(ColKoopa* koopa) {
    *koopa->collidesDown = false;
    for (int i = 0; i < staticObjects.size(); i++) {
        CollisionType collision = collides(koopa->position, koopa->koopa->getVx(), koopa->koopa->getVy(), staticObjects[i]);
        handleKoopa(koopa , collision);
    }
}

void CollisionHandler::handleKoopasQBlocksCollision(ColKoopa* koopa) {
    for (int i = 0; i < questionBlocks.size(); i++) {
        CollisionType collision = collides(koopa->position, koopa->koopa->getVx(), koopa->koopa->getVy(), questionBlocks[i]->position);
        handleKoopa(koopa , collision);
    }
}

void CollisionHandler::handleKoopasBricksCollision(ColKoopa* koopa) {

}

void CollisionHandler::addStaticObjects(Rectangle* position) {
    staticObjects.push_back(position);
}

void CollisionHandler::addQuestionBlock(QuestionBlock* _QBlock) {
    ColQBlock* QBlock = new ColQBlock;
    QBlock->QBlock = _QBlock;
    QBlock->position = _QBlock->getPositionPointer();
    questionBlocks.push_back(QBlock);
}

void CollisionHandler::addBrickBlock(BrickBlock* _brickBlock) {
    ColBrickBlock* brickBlock = new ColBrickBlock;
    brickBlock->brickBlock = _brickBlock;
    brickBlock->position = brickBlock->brickBlock->getPositionPointer();
    brickBlocks.push_back(brickBlock);
}

void CollisionHandler::addGoomba(LittleGoomba* _goomba) {
    ColGoomba* goomba = new ColGoomba;
    goomba->goomba = _goomba;
    goomba->position = goomba->goomba->getPositionPointer();
    goomba->collidesDown = goomba->goomba->getDownCollisionPointer();
    goombas.push_back(goomba);
}

void CollisionHandler::addKoopa(KoopaTroopa* _koopa) {
    ColKoopa* koopa = new ColKoopa;
    koopa->koopa = _koopa;
    koopa->collidesDown = _koopa->getDownCollisionPointer();
    koopa->position = _koopa->getPositionPointer();
    koopas.push_back(koopa);
}