#include "../include/mockos/DisplayCommand.h"
#include "../include/mockos/BasicDisplayVisitor.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int DisplayCommand::execute(string input) {
    bool isdata = false; //checks if the data option is being used
    //readiing in string
    istringstream iss(input);
    string filename;
    string option;
    iss >> filename;
    iss >> option;

    //checking if -d is passed
    if (option == "-d") {
        isdata = true;
    }

    AbstractFile* file = fs->openFile(filename);
    if (file != nullptr) {
        //formatted
        if (!isdata) {
            //formatted 
            vector<char> vec = file->read();
            AbstractFileVisitor* visitor = new BasicDisplayVisitor;
            file->accept(visitor);
        }
        // for text / unformatted images
        else {
            for (char content : file->read()) {
                cout << content;
            }
        }
        cout << endl;
        fs->closeFile(file);
        return SUCCESS;
    }
    cout << "File not found" << endl;
    return FILENOTFOUND;
}

void DisplayCommand::displayInfo() {
    cout << "Display opens a file and displays its contents. ds can be invoked from the command prompt as follows: ds <filename> [-d]" << endl;
    cout << "-d is for data only, not formatted." << endl;
}