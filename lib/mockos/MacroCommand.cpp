#include "../../include/mockos/MacroCommand.h"
#include <iostream>
using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* filesystem) {
    fs = filesystem;
    parsing = nullptr;
}
MacroCommand::~MacroCommand() {
    for (auto command : commands) {
        delete command;
    }
}
void MacroCommand::addCommand(AbstractCommand* command) {
    commands.push_back(command);
}
void MacroCommand::setParseStrategy(AbstractParsingStrategy* strategy) {
    parsing = strategy;
}

int MacroCommand::execute(string input) {

    if (parsing == nullptr) {
        return PARSENOTSET; 
    }

    //asking parsing strategy to parse an input and return a vector of parsed inputs
    vector<string> parsedinput = parsing->parse(input);

    if (parsedinput.size() != commands.size()) {
        return DIFFERENTSIZES; 
    }
    //looping through commands vector and calling execute.
    //if all the commands execute successfully, it returns a 0;
    int result = 0;
    for (int i = 0; i < commands.size(); i++) {
        result = commands[i]->execute(parsedinput[i]);
        if (result != 0) {
            return result;
        }
    }
    return result;

}

void MacroCommand::displayInfo() {
    cout << "Rename renames a file" << endl;
    cout << "Usage: rn <existing_file> <new_name>" << endl;
    cout << "CatDS is a combination of Cat and DS, after concatenating or writing to the file a formatted file will return to you" << endl;
    cout << "Usage: cds <filename> [-a]" << endl;
}
