#include <exception>

#define BAD_ELEMENT_ID "Inavlid element ID requested!"
#define ID_ALREADY_EXISTS "Requested ID already exists!"
#define BAD_TITLE "Parent directory has the same child!"
#define BAD_PARENT_ID "Parent ID is not referring to a directory!"
#define BAD_LINK_ELEMENT "Invalid element type requested!"

class BadElementId : public std::exception {
    const char * what () const throw ();
};

class IdAlreadyExists : public std::exception {
    const char * what () const throw ();
};

class BadTitle : public std::exception {
    const char * what () const throw ();
};
