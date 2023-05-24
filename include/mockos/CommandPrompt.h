#pragma once
#include <string>
#include <map>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "Constants.h"
using namespace std;
class CommandPrompt{
private:
    map<string, AbstractCommand*> commandmap;
    AbstractFileSystem* filesystem;
    AbstractFileFactory* filefactory;
public:
    CommandPrompt();
    void setFileSystem(AbstractFileSystem*);
    void setFileFactory(AbstractFileFactory*);
    int addCommand(string, AbstractCommand*);
    int run();
protected:
    void listCommands();
    string prompt();

};