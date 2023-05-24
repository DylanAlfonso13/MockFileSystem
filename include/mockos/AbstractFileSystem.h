#pragma once

#include <string>
#include <set>
#include <vector>
#include "AbstractFile.h"

using namespace std;

class AbstractFileSystem {
public:
	virtual set<string> getFileNames() = 0;
	virtual int addFile(string, AbstractFile*) = 0;
	virtual int deleteFile(string) = 0;
	virtual AbstractFile* openFile(string) = 0;
	virtual int closeFile(AbstractFile*) = 0;
};