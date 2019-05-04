#ifndef CUBOID_H
#define CUBOID_H

#include "shape.h"
#include "string"

class Cuboid : public Shape {
public:
    Cuboid(int _x, int _y, int _z, int w, int h, int _depth);
    virtual void scale(int factor);
	virtual int volume() const;
private:
    virtual std::string getType() const;

    int width;
    int height;
    int depth;

};

#endif