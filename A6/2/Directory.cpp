#include "Directory.h"

Directory::Directory(int _id, std::string _title)
    :Data(_id, _title) {
}

void Directory::view() {
    std::cout << TITLE << title << std::endl;
    for (int i = 0; i < datas.size(); i++) {
        std::cout << TITLE << datas[i]->getTitle()
            << ", " << TYPE << datas[i]->getType()
            << std::endl;
    }
}

std::string Directory::getType() {
    return DIRECTORY;
}

void Directory::addData(Data* data) {
    if (isTitleTaken(data->getTitle()))
        throw BadTitle();
    datas.push_back(data);
}

bool Directory::isTitleTaken(std::string Datatitle) {
    for (int i = 0; i < datas.size(); i++) {
        if (Datatitle == datas[i]->getTitle())
            return true;
    }
    return false;
}