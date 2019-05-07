#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "Data.h"
#include <iostream>
#include <string>
#include <vector>
#include "defines.h"

class Directory : public Data {
public:
    Directory(int _id, std::string _title, Directory* _parent);
    void view();
    std::string getType();

private:

    std::vector<Data*> datas;
};


#endif