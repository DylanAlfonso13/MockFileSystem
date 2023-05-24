#pragma once
#include "AbstractFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"
using namespace std;

class SimpleFileFactory: public AbstractFileFactory{
public:
    virtual AbstractFile* createFile(string) override;
};