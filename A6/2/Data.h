#ifndef DATA_H
#define DATA_H

#include <string>

class Data {
public:
    Data(int _id, std::string _title, Data* _parent);
    virtual void view() = 0;
    virtual std::string getType() = 0;
    int getID();
    std::string getTitle();
    

protected:
    std::string title;
    int id;
    Data* parent;
};

#endif