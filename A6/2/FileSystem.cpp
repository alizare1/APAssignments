#include "FileSystem.h"

FileSystem::FileSystem() {
    Directory* dir = new Directory(0, ROOT);
    datas.push_back(dir);
}

void FileSystem::addData(Data* newData, int parentID) {
    try {
        validateId(newData->getID());
        getParent(parentID)->addData(newData);
        datas.push_back(newData);
    }
    catch (std::exception& e) {
        std::cerr << e.what();
        delete newData;
    }
}

void FileSystem::addDirectory(int id, std::string title, int parentID) {
    Directory* newDir = new Directory(id, title);
    addData(newDir, parentID);
}

void FileSystem::addFile(int id, std::string title, std::string content, int parentID) {
    File* newFile = new File(id, title, content);
    addData(newFile, parentID);
}

void FileSystem::addLink(int id, std::string title, int elementID, int parentID) {
    Link* newLink;
    try {
        newLink = new Link(id, title, getLinkedData(elementID));
    }
    catch(std::exception& e) {
        std::cerr << e.what();
        return;
    }
    addData(newLink, parentID);
}

void FileSystem::view(int id) {
    try {
        getData(id)->view();
    }
    catch (std::exception& e) {
        std::cerr << e.what();
    }
}

bool FileSystem::isIdTaken(int id) {
    for (int i = 0; i < datas.size(); i++) {
        if (id == datas[i]->getID())
            return true;
    }
    return false;
}

Data* FileSystem::getData(int id) {
    for (int i = 0; i < datas.size(); i++) {
        if (id == datas[i]->getID())
            return datas[i];
    }
    throw BadElementId();
}

Directory* FileSystem::getParent(int id) {
    Data* parent = getData(id);
    if (isDirectory(parent))
        return dynamic_cast<Directory*>(parent);
    else
        throw BadParentId();
}

bool FileSystem::isDirectory(Data* data) {
    if (data->getType() == DIRECTORY)
        return true;
    return false;
}

void FileSystem::validateId(int id) {
    if (isIdTaken(id))
        throw IdAlreadyExists();
}

Data* FileSystem::getLinkedData(int elementID) {
    Data* element = getData(elementID);
    if (getData(elementID)->getType() == LINK) 
        throw BAD_LINK_ELEMENT;
    return element;
}