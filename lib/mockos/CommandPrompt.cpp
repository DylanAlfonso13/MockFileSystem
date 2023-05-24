#include "../../include/mockos/CommandPrompt.h"
#include <iostream>
#include <sstream>
using namespace std;

CommandPrompt::CommandPrompt() {
    filesystem = nullptr;
    filefactory = nullptr;
}

void CommandPrompt:: setFileSystem(AbstractFileSystem* systemvar){
    filesystem = systemvar;
}

void CommandPrompt:: setFileFactory(AbstractFileFactory* factoryvar){
    filefactory = factoryvar;
}

int CommandPrompt::addCommand(string var, AbstractCommand * commands) {
    auto result = commandmap.insert({var, commands});
    if(result.second){ //second stores true if the element was inserted
        return SUCCESS; //success
    }
    return FAILEDINSERTION; //failed insertion
}

void CommandPrompt::listCommands(){
    for (auto& command : commandmap) {
        cout << command.first << endl;
    }
}

string CommandPrompt:: prompt(){
    cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command."<< endl;
    cout << "$ ";
    string input;
    getline(cin, input);
    return input;
}

int CommandPrompt:: run() {

    while(true) {
        string input = prompt();
        if (input == "q") {
            return USERQUITS; //user quits
        }

        else if(input == "help"){
           listCommands();
        }

        else {
            size_t position = input.find(' ');
            string commandName;
            string commandArgument;
            //1 word long
            if (position == string::npos) { //if this fails
                commandName = input;
                auto it = commandmap.find(commandName);
                if (it == commandmap.end()) {
                    cout << "Command not Found: " << commandName << endl;
                }
                else {
                    int checker = it->second->execute("");
                    if (checker != SUCCESS) {
                        cout << "Command Failed" << checker << endl;
                    }
                }
            }

            //2 words long
            else {
                istringstream iss(input);
                iss >> commandName;
                //If 1st word is help
                if (commandName == "help") {
                    iss >> commandArgument;
                    auto it = commandmap.find(commandArgument);
                    if (it == commandmap.end()) {
                        cout << "Command not Found: " << commandArgument << endl;
                    }
                    else {
                        it->second->displayInfo();
                    }
                }
                //Otherwise
                else {
                    //find command name
                    auto it = commandmap.find(commandName);
                    if (it == commandmap.end()) {
                        cout << "Command not Found: " << commandName << endl;
                    }
                    else {
                        //command argument
                        getline(iss, commandArgument);
                        int checker = it->second->execute(commandArgument);
                        if (checker != SUCCESS) {
                            cout << "Command Failed" << endl;
                        }
                    }
                }
            } 
        }

    }
}
