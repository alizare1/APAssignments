#include "Data.h"

Data::Data(int _id, std::string _title) {
    id = _id;
    title = _title;
}

int Data::getID() {
    return id;
}

std::string Data::getTitle() {
    return title;
}