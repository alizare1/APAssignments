#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <vector>
#include "Data.h"
#include "Directory.h"
#include "File.h"
#include "Link.h"
#include "defines.h"
#include "Exceptions.h"
#include "exception"

class FileSystem {
public:
    FileSystem();
    void addDirectory(int id, std::string title, int parentID);
    void addFile(int id, std::string title, std::string content, int parentID);
    void addLink(int id, std::string title, int elementID, int parentID);
    
    void view(int id);

private:
    bool isIdTaken(int id);
    void validateId(int id);
    Data* getData(int id);
    Directory* getParent(int id);
    bool isDirectory(Data* data);
    void addToParent(Directory* parent, Data* data);
    void addData(Data* newData, int parentID);
    Data* getLinkedData(int elementID);

    std::vector<Data*> datas;

};

#endif