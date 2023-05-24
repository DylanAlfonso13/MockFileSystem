#pragma once
#include "AbstractFileSystem.h"
using namespace std;

class AbstractFileFactory{
public:
    virtual AbstractFile* createFile(string) = 0;
};