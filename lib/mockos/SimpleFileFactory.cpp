#include "../../include/mockos/SimpleFileFactory.h"
#include <iostream>
using namespace std;

AbstractFile* SimpleFileFactory :: createFile(string fileName){
    string extension = fileName.substr(fileName.find_last_of(".") + 1);
    if (extension == "txt") {
        return new TextFile(fileName);
    }
    else if (extension == "img") {
        return new ImageFile(fileName);
    }
    else {
        return nullptr;
    }

}