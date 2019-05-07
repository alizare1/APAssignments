#include "FileSystem.h"

FileSystem::FileSystem() {
    Directory* dir = new Directory(0, "root", nullptr);
    datas.push_back(dir);
}

void FileSystem::addDirectory(int id, std::string title, int parentID) {
    
}

void FileSystem::addFile(int id, std::string title, std::string content, int parentID) {}

void FileSystem::addLink(int id, std::string title, int elementID, int parentID) {}

void FileSystem::view(int id) {}

bool FileSystem::isIdUsed(int id) {
    for (int i = 0; i < datas.size(); i++) {
        if (id == datas[i]->getID())
            return true;
    }
    return false;
}