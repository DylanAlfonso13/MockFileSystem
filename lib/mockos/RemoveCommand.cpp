#include "../../include/mockos/RemoveCommand.h"
#include <iostream>
#include <sstream>
using namespace std;

int RemoveCommand::execute(string args) {
    istringstream iss(args);
    string filename;
    if (!(iss >> filename)) {
        return FILENOTREMOVED;
        cout << "Remove failure" << endl;
    }
    int filestatus = fs->deleteFile(filename);
    cout << "Remove success" << endl;
    return filestatus;
}

void RemoveCommand::displayInfo() {
    cout << "Remove a file from the file system." << endl;
    cout << "Usage: remove <filename>" << endl;
}