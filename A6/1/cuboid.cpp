#include "cuboid.h"

Cuboid::Cuboid(int _x, int _y, int _z, int w, int h, int _depth)
    : Shape(_x, _y, _z) {
    width = w;
    height = h;
    depth = _depth;
}

void Cuboid::scale(int factor) {
    width *= factor;
    height *= factor;
    depth *= factor;
}

int Cuboid::volume() const {
    return width * height * depth;
}

std::string Cuboid::getType() const {
    return "Cuboid";
}
