#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractParsingStrategy.h"
#include "Constants.h"
using namespace std;

class MacroCommand: public AbstractCommand{
public:
    MacroCommand(AbstractFileSystem*);
    ~MacroCommand();
    virtual int execute(string) override;
    virtual void displayInfo() override;
    void addCommand(AbstractCommand* command);
    void setParseStrategy(AbstractParsingStrategy* strategy);

private:
    AbstractFileSystem* fs;
    vector<AbstractCommand*> commands;
    AbstractParsingStrategy* parsing;
};