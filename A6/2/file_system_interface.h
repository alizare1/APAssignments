
#ifndef FILE_SYSTEM_INTERFACE_H_
#define FILE_SYSTEM_INTERFACE_H_

#include <string>
#include "FileSystem.h"


class FileSystemInterface
{
public:
    FileSystemInterface();
    void add_directory(int id, std::string title, int parent_id);
    void add_file(int id, std::string title, std::string content, int parent_id);
    void add_link(int id, std::string title, int element_id, int parent_id);

    void view(int id);
private:
    FileSystem fileSystem;
};

#endif

// a base class with id,title,parent_id. then children: file, link, directory
// storing them, polymorphism ?