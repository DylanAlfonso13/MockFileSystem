#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "Constants.h"

class CopyCommand : public AbstractCommand{
public:
    CopyCommand(AbstractFileSystem*);
    virtual int execute(string) override;
    virtual void displayInfo() override;

private:
    AbstractFileSystem* fs;
};