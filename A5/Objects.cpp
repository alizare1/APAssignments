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

void Objects::addQuestionBlock (QuestionBlock* qBlock) {
    questionBlocks.push_back(qBlock);
}

void Objects::draw(Window* win, int winOffset) {
    drawNormalBlocks(win, winOffset);
    drawPipes(win, winOffset);
    drawFlag(win, winOffset);
}

void Objects::drawNormalBlocks(Window* win, int winOffset){
    for (int i = 0; i < normalBlocks.size(); i++) {
        normalBlocks[i]->draw(win, winOffset);
    }
}

void Objects::drawPipes(Window* win, int winOffset) {
    for (int i = 0; i < pipes.size(); i++) {
        pipes[i]->draw(win, winOffset);
    }
}

void Objects::drawFlag(Window* win, int winOffset) {
    flag->draw(win, winOffset);
}
