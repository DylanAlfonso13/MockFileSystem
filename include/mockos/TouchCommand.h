#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractFile.h"
#include "PasswordProxy.h"
using namespace std;

class TouchCommand : public AbstractCommand {
private:
	AbstractFileSystem* fileSystem;
	AbstractFileFactory* fileFactory;
public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	void displayInfo() override;
	int execute(string) override;



};