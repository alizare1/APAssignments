#include "File.h"

File::File(int _id, std::string _title, std::string _content)
    :Data(_id, _title) {
    content = _content;
}

void File::view() {
    std::cout << TITLE << title << std::endl
        <<  CONTENT << std::endl << content
        << std::endl;
}

std::string File::getType() {
    return FILE;
}