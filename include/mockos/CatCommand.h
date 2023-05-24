#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "Constants.h"

class CatCommand : public AbstractCommand {
public:
	CatCommand(AbstractFileSystem* fileSys) : fs(fileSys) {};
	virtual int execute(string) override;
    virtual void displayInfo() override;

private:
	AbstractFileSystem* fs;
};