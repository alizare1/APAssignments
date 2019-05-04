#ifndef CONE_H
#define CONE_H

#include "shape.h"
#include "pi.h"
#include "string"

class Cone : public Shape {
public:
    Cone(int _x, int _y, int _z, int r, int h);
    virtual void scale(int factor);
	virtual int volume() const;
private:
    virtual std::string getType() const;

    int radius;
    int height;
};

#endif