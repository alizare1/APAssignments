#ifndef OBJECTS_H
#define OBJECTS_H

#include <vector>
#include "Pipe.h"
// #include "KoopaTroopa.h"
// #include "LittleGoomba.h"
#include "NormalBlock.h"
// #include "QuestionBlock.h"
#include "Flag.h"


class Objects {
public:
    void addPipe(Pipe* pipe);
    void addFlag(Flag* _flag);
    void addNormalBlock(NormalBlock* normalBlock);

private:


    std::vector<Pipe*> pipes;
    // std::vector<KoopaTroopa*> koopas;
    // std::vector<LittleGoomba*> goombas;
    std::vector<NormalBlock*> normalBlocks;
    // std::vector<QuestionBlock*> questionBlocks;
    Flag* flag;

};

#endif