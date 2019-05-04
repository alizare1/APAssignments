#include "test.h"

using namespace std;

ostream &operator<<(ostream &output, const test &t) {
    output << t.a;
    return output;
}