#include <iostream>
#include "shape.h"
#include "sphere.h"

using namespace std;

int main() {
    Sphere s(10, 10, 10, 2);
    cout << &s;
    return 0;
}