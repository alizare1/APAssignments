#ifndef OBJECTS_H
#define OBJECTS_H

#include <vector>
#include "Pipe.h"
#include "KoopaTroopa.h"
#include "NormalBlock.h"
#include "LittleGoomba.h"
#include "QuestionBlock.h"
#include "Flag.h"


class Objects {
public:
    void addPipe(Pipe* pipe);
    void addFlag(Flag* _flag);
    void addNormalBlock(NormalBlock* normalBlock);
    void draw(Window* win, int winOffset);

private:
    void drawNormalBlocks(Window* win, int winOffset);
    void drawPipes(Window* win, int winOffset);

    std::vector<Pipe*> pipes;
    std::vector<KoopaTroopa*> koopas;
    std::vector<NormalBlock*> normalBlocks;
    std::vector<LittleGoomba*> goombas;
    std::vector<QuestionBlock*> questionBlocks;
    Flag* flag;

};

#endif
