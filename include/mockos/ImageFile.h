#pragma once
#include "AbstractFile.h"
#include "Constants.h"

class ImageFile : public AbstractFile {
private:
	string fileName;
	vector<char> contents;
	char size;
public:
	ImageFile(string);
	virtual unsigned int getSize() override;
	virtual string getName() override;
	virtual int write(vector<char>) override;
	virtual int append(vector<char>) override;
	virtual vector<char> read() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(string) override;
};

