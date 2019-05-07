#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <string>
#include "Data.h"
#include "defines.h"
#include "Directory.h"

class File : public Data {
public:
    File(int _id, std::string _title, std::string _content, Directory* _parent);
    void view();
    std::string getType();

private:

    std::string content;
};

#endif