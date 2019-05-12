#include "Exceptions.h"

const char * BadElementId::what() const throw () {
    return BAD_ELEMENT_ID;
}

const char * IdAlreadyExists::what() const throw () {
    return ID_ALREADY_EXISTS;
}

const char * BadTitle::what() const throw () {
    return BAD_TITLE;
}

const char * BadParentId::what() const throw () {
    return BAD_PARENT_ID;
}

const char * BadLinkedElement::what() const throw () {
    return BAD_LINK_ELEMENT;
}
