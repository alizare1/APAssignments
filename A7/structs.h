#ifndef STRUCTS_H
#define STRUCTS_H

#include <map>
#include <string>
#include "defines.h"

struct StructedInput {
    std::string method;
    std::string command;
    Args args;
};

struct SignupArgs {
    std::string email;
    std::string username;
    std::string password;
    int age;
    std::string publisher; 
};

struct LoginArgs {
    std::string username;
    std::string password;
};

struct NewFilmArgs {
    std::string name;
    std::string summary;
    std::string director;
    int year;
    int length;
    int price;
};

#endif