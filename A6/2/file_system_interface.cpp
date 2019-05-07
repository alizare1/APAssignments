#include "file_system_interface.h"

FileSystemInterface::FileSystemInterface()
    :fileSystem(FileSystem()) {}

void FileSystemInterface::add_directory(int id, std::string title, int parent_id) {
    fileSystem.addDirectory(id, title, parent_id);
}

void FileSystemInterface::add_file(int id, std::string title, std::string content, int parent_id) {
    fileSystem.addFile(id, title, content, parent_id);
}

void FileSystemInterface::add_link(int id, std::string title, int element_id, int parent_id) {
    fileSystem.addLink(id, title, element_id, parent_id);
}