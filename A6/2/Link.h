#ifndef LINK_H
#define LINK_H

#include "Data.h"
#include "Directory.h"
#include <string>
#include "defines.h"

class Link : public Data {
public:
    Link(int _id, std::string _title, Data* _element);
    void view();
    std::string getType();

private:
    Data* element;
};


#endif