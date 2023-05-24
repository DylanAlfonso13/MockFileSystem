#include "../../include/mockos/PasswordProxy.h"
#include <iostream>
#include <sstream>
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* file, string password) {
	protectedFile = file;
	password_ = password;
}

PasswordProxy::~PasswordProxy() {
	delete protectedFile;
}

string PasswordProxy::passwordPrompt() {
	cout << "Enter Password:" << endl;
	string entered;
	getline(cin, entered);
	return entered;
}

bool PasswordProxy::checkPassword(string enteredPassword) {
	return (password_ == enteredPassword);
}

vector<char> PasswordProxy::read() {
	if (checkPassword(passwordPrompt())) {
		return protectedFile->read();
	}

	else {
		cout << "Incorrect Password" << endl;
		return vector<char>();
	}

}

int PasswordProxy::write(vector<char> contents) {
	if (checkPassword(passwordPrompt())) {
		return protectedFile->write(contents);
	}
	else {
		cout << "Incorrect Password" << endl;
		return INCORRECTPASSWORD;
	}
}

int PasswordProxy::append(vector<char> contents) {
	if (checkPassword(passwordPrompt())) {
		return protectedFile->append(contents);
	}
	else {
		cout << "Incorrect Password" << endl;
		return INCORRECTPASSWORD;
	}
}

unsigned int PasswordProxy::getSize() {
	return protectedFile->getSize();
}

string PasswordProxy::getName() {
	return protectedFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* visitor) {
	if (checkPassword(passwordPrompt())) {
		protectedFile->accept(visitor);
	}
}

AbstractFile* PasswordProxy::clone(string newname) {
	AbstractFile* copy = protectedFile->clone(newname);
	PasswordProxy* passcopy = new PasswordProxy(copy, password_);
	return passcopy;
}