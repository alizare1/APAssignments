#ifndef SPHERE_H
#define SPHERE_H

#include "shape.h"
#include "pi.h"
#include "math.h"
#include "string"

class Sphere : public Shape {
public:
    Sphere(int _x, int _y, int _z, int r);
    virtual void scale(int factor);
	virtual int volume() const;
private:
    virtual std::string getType() const;

    int radius;

};

#endif