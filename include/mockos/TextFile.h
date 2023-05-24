#pragma once

#include "AbstractFile.h"

class TextFile : public AbstractFile {
private:
	vector<char> contents;
	string fileName;
public:
	TextFile(string);
	virtual unsigned int getSize() override;
	virtual string getName() override;
	virtual int write(vector<char>) override;
	virtual int append(vector<char>) override;
	virtual vector<char> read() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(string) override;
};