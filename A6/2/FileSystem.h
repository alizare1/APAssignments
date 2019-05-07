#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <vector>
#include "Data.h"
#include "Directory.h"
#include "File.h"
#include "Link.h"
#include "defines.h"

class FileSystem {
public:
    FileSystem();
    void addDirectory(int id, std::string title, int parentID);
    void addFile(int id, std::string title, std::string content, int parentID);
    void addLink(int id, std::string title, int elementID, int parentID);
    
    void view(int id);

private:
    bool isIdUsed(int id);

    std::vector<Data*> datas;

};

#endif