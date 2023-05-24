#include "../include/mockos/CommandPrompt.h"
#include "../include/mockos/TouchCommand.h"
#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include <iostream>
using namespace std;

int main(){
    //initializing system, factory, and command
    SimpleFileSystem* filesystem = new SimpleFileSystem();
    SimpleFileFactory* filefactory = new SimpleFileFactory();
    TouchCommand* touch = new TouchCommand(filesystem, filefactory);

    //initializing text file
    AbstractFile* text = filefactory->createFile("text.txt");
    vector<char> textContents = { 'h', 'a', 'b', 'c' };
    text->write(textContents);
    filesystem->addFile("text.txt", text);

    //initializing prompt
    CommandPrompt cprompt;
    cprompt.setFileFactory(filefactory);
    cprompt.setFileSystem(filesystem);
    cprompt.addCommand("touch", touch);

    //Testing command prompt
    cprompt.run();


    //Testing touch
    AbstractFile* file = filesystem->openFile("text.txt");
    if (file != nullptr) {
        std::cout << "File created successfully\n";
        filesystem->closeFile(file);
    }
    else {
        std::cout << "Failed to open file\n";
    }

    delete filesystem;
    delete filefactory;
    delete touch;
    return 0;
};