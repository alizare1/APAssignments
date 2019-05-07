#include "File.h"

File::File(int _id, std::string _title, std::string _content, Directory* _parent)
    :Data(_id, _title, _parent) {
    content = _content;
}

void File::view() {
    std::cout << "Title: " << title << std::endl
        <<  "Content: " << std::endl << content
        << std::endl;
}

std::string File::getType() {
    return FILE;
}