#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "Data.h"
#include <iostream>
#include <string>
#include <vector>
#include "defines.h"
#include "Exceptions.h"

class Directory : public Data {
public:
    Directory(int _id, std::string _title);
    void view();
    std::string getType();
    void addData(Data* data);

private:
    bool isTitleTaken(std::string Datatitle);

    std::vector<Data*> datas;
};


#endif