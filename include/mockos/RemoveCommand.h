#pragma once

#include <string>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "Constants.h"

class RemoveCommand: public AbstractCommand{
public:
    RemoveCommand(AbstractFileSystem* fileSys): fs(fileSys) {};
    virtual int execute(string args) override;
    virtual void displayInfo() override;

private:
    AbstractFileSystem* fs;
};