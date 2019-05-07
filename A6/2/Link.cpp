#include "Link.h"

Link::Link(int _id, std::string _title, Directory* _parent, Data* _element)
    :Data(_id, _title, _parent) {
    element = _element;
}

void Link::view() {
    std::cout << "Title: " << title << std::endl;
    element->view();
}

std::string Link::getType() {
    return LINK;
}