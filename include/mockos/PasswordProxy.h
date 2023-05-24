#pragma once
#include "AbstractFile.h"
#include "Constants.h"
#include <string>

using namespace std;

class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile*, string);
	virtual ~PasswordProxy();
	virtual vector<char> read() override;
	virtual int write(vector<char>) override;
	virtual int append(vector<char>) override;
	virtual unsigned int getSize() override;
	virtual string getName() override;
	virtual void accept(AbstractFileVisitor*) override;
	virtual AbstractFile* clone(string) override;

private:
	AbstractFile* protectedFile;
	string password_;

protected:
	string passwordPrompt();
	bool checkPassword(string);
};
