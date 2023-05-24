#pragma once

#include <string>
#include <vector>

class AbstractFileVisitor;

using namespace std;

class AbstractFile {
public:
	virtual vector<char> read() = 0;
	virtual int write(vector<char>) = 0;
	virtual int append(vector<char>) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
	virtual void accept(AbstractFileVisitor*) = 0;
	virtual AbstractFile* clone(string newname) = 0;
	virtual ~AbstractFile() = default;

};