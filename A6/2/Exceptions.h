#ifndef EPXEPTIONS_H
#define EPXEPTIONS_H

#include <exception>

#define BAD_ELEMENT_ID "Inavlid element ID requested!\n"
#define ID_ALREADY_EXISTS "Requested ID already exists!\n"
#define BAD_TITLE "Parent directory has the same child!\n"
#define BAD_PARENT_ID "Parent ID is not referring to a directory!\n"
#define BAD_LINK_ELEMENT "Invalid element type requested!\n"

class BadElementId : public std::exception {
public:
    const char * what() const throw ();
};

class IdAlreadyExists : public std::exception {
public:
    const char * what() const throw ();
};

class BadTitle : public std::exception {
public:
    const char * what() const throw ();
};

class BadParentId : public std::exception {
public:
    const char * what() const throw ();
};

class BadLinkedElement : public std::exception {
public:
    const char * what() const throw ();
};

#endif