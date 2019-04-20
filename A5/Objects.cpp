#include "Objects.h"

using namespace std;

void Objects::addPipe(Pipe* pipe) {
    pipes.push_back(pipe);
}

void Objects::addFlag(Flag* _flag) {
    flag = _flag;
}

void Objects::addNormalBlock(NormalBlock* normalBlock) {
    normalBlocks.push_back(normalBlock);
}