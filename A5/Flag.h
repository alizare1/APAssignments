#ifndef FLAG_H
#define FLAG_H

#include "rsdl.hpp"

class Flag {
public:
    Flag(Point headPos, int _height);

private:
    Point headPosition;
    int height;
};

#endif