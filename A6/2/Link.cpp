#include "Link.h"

Link::Link(int _id, std::string _title, Data* _element)
    :Data(_id, _title) {
    element = _element;
}

void Link::view() {
    std::cout << TITLE << title << std::endl;
    element->view();
}

std::string Link::getType() {
    return LINK;
}