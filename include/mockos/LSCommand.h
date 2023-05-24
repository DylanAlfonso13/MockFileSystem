#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "Constants.h"

class LSCommand : public AbstractCommand {
public:
    LSCommand(AbstractFileSystem*);
    virtual int execute(string) override;
    virtual void displayInfo() override;

private:
    AbstractFileSystem* fs;
    int WIDTH = 20;
};
