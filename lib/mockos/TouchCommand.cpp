#include "../../include/mockos/TouchCommand.h"
#include <iostream>
#include <sstream>
using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* system, AbstractFileFactory* factory) {
	fileSystem = system;
	fileFactory = factory;
}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command: touch:<filename>" << endl;
	cout << "-p: creates a password protected file" << endl;
}

int TouchCommand::execute(string input) {
	istringstream iss(input);
	string filename;
	iss >> filename;
	string password;
	AbstractFile* file = fileFactory->createFile(filename);
	if (iss >> password) {
		if (file != nullptr) {
			cout << "Enter Password:" << endl;
			string password;
			getline(cin, password);
			AbstractFile* passwordfile = new PasswordProxy(file, password);
			int checker = fileSystem->addFile(filename, passwordfile);
			if (checker != SUCCESS) {
				delete file;
				cout << "Failure to add new file to system" << endl;
			}
			return checker;
		}
		else {
			cout << "Failure to create new file" << endl;
			return FAILTOCREATEFILE;
		}
	}
	else {
		if (file != nullptr) {
			int checker = fileSystem->addFile(filename, file);
			if (checker != 0) {
				delete file;
				cout << "Failure to add new file to system" << endl;
			}
			return checker;
		}
		else {
			cout << "Failure to create new file" << endl;
			return FAILTOCREATEFILE;
		}
	}
}