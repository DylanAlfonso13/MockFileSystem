#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/CommandPrompt.h"
#include "../include/mockos/TouchCommand.h"
#include "../include/mockos/LSCommand.h"
#include "../include/mockos/RemoveCommand.h"
#include "../include/mockos/CatCommand.h"
#include "../include/mockos/DisplayCommand.h"
#include "../include/mockos/CopyCommand.h"
#include "../include/mockos/MacroCommand.h"
#include "../include/mockos/AbstractParsingStrategy.h"
#include "../include/mockos/RenameParsingStrategy.h"
#include "../include/mockos/CatDsParsingStrategy.h"
#include <iostream>
#include <string>

int main() {
    AbstractFileSystem* file_system = new SimpleFileSystem();
    AbstractFileFactory* file_factory = new SimpleFileFactory();
    CommandPrompt command_prompt;
    command_prompt.setFileSystem(file_system);
    command_prompt.setFileFactory(file_factory);
    //Add commands as we go in this section
    AbstractCommand* touch_command = new TouchCommand(file_system, file_factory);
    AbstractCommand* ls_command = new LSCommand(file_system);
    AbstractCommand* remove_command = new RemoveCommand(file_system);
    AbstractCommand* cat_command = new CatCommand(file_system);
    AbstractCommand* display_command = new DisplayCommand(file_system);
    AbstractCommand* copy_command = new CopyCommand(file_system);

    //rename macrocommand
    MacroCommand* mc1 = new MacroCommand(file_system);
    AbstractParsingStrategy* rps = new RenameParsingStrategy;
    mc1->setParseStrategy(rps);
    mc1->addCommand(copy_command);
    mc1->addCommand(remove_command);

    //CATDS command
    MacroCommand* mc2 = new MacroCommand(file_system);
    AbstractParsingStrategy* cds = new CatDsParsingStrategy;
    mc2->setParseStrategy(cds);
    mc2->addCommand(cat_command);
    mc2->addCommand(display_command);

    command_prompt.addCommand("touch", touch_command);
    command_prompt.addCommand("ls", ls_command);
    command_prompt.addCommand("remove", remove_command);
    command_prompt.addCommand("cat", cat_command);
    command_prompt.addCommand("ds", display_command);
    command_prompt.addCommand("cp", copy_command);
    command_prompt.addCommand("rn", mc1);
    command_prompt.addCommand("cds", mc2);


    command_prompt.run();
    delete file_system;
    delete file_factory;
    delete touch_command;
    delete ls_command;
    delete remove_command;
    delete cat_command;
    delete display_command;
    delete copy_command;
    delete mc1;
    delete mc2;
    return 0;
}