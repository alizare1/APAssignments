#ifndef DELETE_H
#define DELELE_H

#include "request.h"

class Delete : public Request {
public:
    void parseInput(StructedInput& structedInput);

private:
    std::map<std::string, std::function<void(StructedInput)>> functionMap;
};

#endif