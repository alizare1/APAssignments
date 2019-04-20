#ifndef PIPE_H
#define PIPE_H

#include "rsdl.hpp"

class Pipe {
public:
    Pipe(Point headLeftPos, int _height);

private:
    Point headLeftPosition;
    int height;
};

#endif