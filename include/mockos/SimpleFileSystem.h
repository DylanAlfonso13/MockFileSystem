#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>
#include "AbstractFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

class SimpleFileSystem : public AbstractFileSystem {
public:
    virtual int addFile(string, AbstractFile*) override;
    virtual int deleteFile(string) override;
    virtual AbstractFile* openFile(string) override;
    virtual int closeFile(AbstractFile*) override;
    virtual set<string> getFileNames()  override;
private:
	map<string, AbstractFile*> files;
	set<AbstractFile*> openFiles;
};