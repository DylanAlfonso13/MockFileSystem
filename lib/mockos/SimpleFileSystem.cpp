#include "../../include/mockos/SimpleFileSystem.h"
#include <iostream>
using namespace std;

int SimpleFileSystem::addFile(string fileName, AbstractFile* abstract){
    if(files.count(fileName) > 0){
        return FILEEXISTS;
    }

    else if(abstract == nullptr){
        return ABSTRACTFILENULL;
    }

    else{
        files.insert(make_pair(fileName, abstract));
        return SUCCESS;
    }

}


AbstractFile* SimpleFileSystem::openFile(string fileName) {
    if (files.count(fileName) == 0) {
        return nullptr;
    }

    AbstractFile* file = files[fileName];
    if (openFiles.count(file) > 0) {
        return nullptr;
    }
    openFiles.insert(file);
    return file;
}

int SimpleFileSystem::closeFile(AbstractFile* abstract) {
    if (openFiles.count(abstract) == 0) {
        return ABSTRACTFILENOTOPEN;
    }
    openFiles.erase(abstract);
    return SUCCESS;
}

int SimpleFileSystem::deleteFile(string fileName) {
    if (files.count(fileName) == 0) {
        return FILEDOESNOTEXIST;
    }
    AbstractFile* file = files[fileName];
    if (openFiles.count(file) > 0) {
        return OPEN;
    }
    files.erase(fileName);
    delete file;
    return SUCCESS;
}

set<string> SimpleFileSystem::getFileNames() {
    set<string> fileNames;
    for (auto& fileit : files) {
        fileNames.insert(fileit.first);

    }
    return fileNames;
}