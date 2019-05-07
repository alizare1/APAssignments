#include "Directory.h"

Directory::Directory(int _id, std::string _title, Directory* _parent)
    :Data(_id, _title, _parent) {
    if (_id == 0)
        parent = this;  
}

void Directory::view() {
    std::cout << "Title: " << title << std::endl;
    for (int i = 0; i < datas.size(); i++) 
        datas[i]->view();
}

std::string Directory::getType() {
    return DIRECTORY;
}