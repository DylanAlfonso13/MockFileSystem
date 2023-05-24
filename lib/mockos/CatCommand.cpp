#include "../include/mockos/CatCommand.h"
#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/PasswordProxy.h"
#include <iostream>
#include <sstream>
using namespace std;

int CatCommand::execute(string input) {
	istringstream iss(input);
	cout << input << endl;
	string filename;
	iss >> filename;
	AbstractFile* file = fs->openFile(filename);
	//first wanna check for if the file opened, then check if there's a command
	if (file != nullptr) {
		string command;
		if (iss >> command) {
			if (command == "-a") {
				for (char content : file->read()) {
					cout << content;
				}
				cout << endl;
				cout << "Enter text to append to the file. Enter :wq to save and quit or :q to quit without saving:" << endl;
				vector<char> newData;
				while (true) {
					string inputLine;
					getline(cin, inputLine);
					if (inputLine == ":q") {
						fs->closeFile(file);
						return SUCCESS;
					}
					else if (inputLine == ":wq") {
						int check = file->append(newData);
						if (check != SUCCESS) {
							cout << "Could not append, if it's an image, append not supported" << endl;
						}
						fs->closeFile(file);
						return check;
					}
					else {
						if (!newData.empty()) {
							newData.push_back('\n');
						}
						for (char c : inputLine) {
							newData.push_back(c);
						}
					}
				}
			}
		}
		else {
			cout << "Enter text to write to the file. Enter :wq to save and quit or :q to quit without saving:" << endl;
			vector <char> newData;
			while (true) {
				string inputLine;
				getline(cin, inputLine);
				if (inputLine == ":q") {
					fs->closeFile(file);
					return SUCCESS;
				}
				else if (inputLine == ":wq") {
					int check = file->write(newData);
					if (check != SUCCESS) {
						cout << "Could not write data" << endl;
					}
					fs->closeFile(file);
					return check;
				}
				else {
					if (!newData.empty()) {
						newData.push_back('\n');
					}
					for (char c : inputLine) {
						newData.push_back(c);
					}
				}
			}
		}

	}
	fs->closeFile(file);
	displayInfo();
	return NULLFILE;
}
void CatCommand::displayInfo() {
	cout << "cat can be used to concatenate to files as well as overriding and writing to files, cat can be invoked from the command prompt as follows: cat <filename> [-a]" << endl;
	cout << "-a: stands for append, include if you want to append to the file, otherwise write to file" << endl;
}
