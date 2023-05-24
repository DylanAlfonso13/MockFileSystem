#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "Constants.h"

class DisplayCommand: public AbstractCommand{
public:
    DisplayCommand(AbstractFileSystem* fileSys) : fs(fileSys) {};
    virtual int execute(string) override;
    virtual void displayInfo() override;
private:
    AbstractFileSystem* fs;
};