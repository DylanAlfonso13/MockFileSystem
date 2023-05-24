#include "../include/mockos/CopyCommand.h"
#include "../include/mockos/SimpleFileSystem.h"
#include <iostream>
#include <sstream>

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* filesys) {
    fs = filesys;
}

int CopyCommand::execute(string input) {
    stringstream iss(input);
    string sourceFileName;
    string targetFileName;
    iss >> sourceFileName;
    iss >> targetFileName;
    AbstractFile* sourceFile = fs->openFile(sourceFileName);
    //checking if the source file exist
    if (sourceFile == nullptr) {
        cout << "Error: file" << sourceFileName << "does not exist." << endl;
        fs->closeFile(sourceFile);
        return FILEDNE;
    }
    //Checking if new file name is valid
    if (targetFileName.find(".") != string::npos) {
        cout << "Error, new file name should not have extension" << endl;
        return EXTENSION;
    }

    //checking for extension and adding it to the new file name
    string extension = sourceFileName.substr(sourceFileName.find_last_of("."));
    targetFileName = targetFileName + extension;
    //creating copy using the prototype pattern
    cout << "cloning file" << endl;
    AbstractFile* newfile = sourceFile->clone(targetFileName);
    if (newfile == nullptr) {
        cout << "Failure when cloning file" << endl;
        fs->closeFile(sourceFile);
        return CLONEFAIL;
    }
    //adding file
    int addcheck = fs->addFile(targetFileName, newfile);
    if (addcheck != SUCCESS) {
        cout << "error when adding to file system" << endl;
        fs->closeFile(sourceFile);
        return addcheck;
    }
    fs->closeFile(sourceFile);
    cout << "succesfully copied!" << endl;
    return addcheck;


}

void CopyCommand::displayInfo() {
    cout << "copy the file and add the copied file to the file system with a different name." << endl;
    cout << "Usage: cp <file_to_copy> <new_name_with_no_extension" << endl;
}