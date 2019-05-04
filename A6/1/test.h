#include <iostream>

class test {
public:
    test(int _a) {
        a = _a;
    }

    friend std::ostream &operator<<(std::ostream &output, const test &t);

private:
    int a;
};
