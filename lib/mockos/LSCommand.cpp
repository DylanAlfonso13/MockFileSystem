#include "../../include/mockos/LSCommand.h"
#include "../../include/mockos/SimpleFileSystem.h"
#include "../../include/mockos/MetadataDisplayVisitor.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

LSCommand::LSCommand(AbstractFileSystem* filesys) {
    fs = filesys;
}

int LSCommand::execute(string args) {

    set<string> filenames = fs->getFileNames();
    istringstream iss(args);
    string options;

    //displaying metadata
    if (iss >> options && options == "-m") {
        //displaying file data
        for (auto& filename : filenames) {
            AbstractFile* file = fs->openFile(filename);
            AbstractFileVisitor* visitor = new MetadataDisplayVisitor;
            file->accept(visitor);
            fs->closeFile(file);
        }
        cout << endl;
    }

    else {
        //displaying file names only
        int count = 0;
        for (auto& filename : filenames) {
            //setw sets the width of the output
            cout << std::setw(WIDTH) << left << filename;
            count++;
            if (count % 2 == 0) {
                cout << endl;
            }
        }
        if (count % 2 != 0) {
            cout << endl;
        }
    }
    return SUCCESS;
}

void LSCommand::displayInfo() {
    cout << "Lists all files in the file system" << endl;
    cout << "Usage: ls <filename> [-m]" << endl;
    cout << "-m: display file metadata";
}




