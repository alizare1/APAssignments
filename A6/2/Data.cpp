#include "Data.h"

Data::Data(int _id, std::string _title, Data* _parent) {
    id = _id;
    title = _title;
    parent = _parent;
}

int Data::getID() {
    return id;
}

std::string Data::getTitle() {
    return title;
}