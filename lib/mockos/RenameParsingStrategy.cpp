#include "../include/mockos/RenameParsingStrategy.h"
#include <iostream>
#include <sstream>

using namespace std;

vector<string> RenameParsingStrategy::parse(std::string input) {
    //defining parse
    vector<string> vec;
    istringstream iss(input);
    string existingfile;
    iss >> existingfile;
    vec.push_back(input);
    vec.push_back(existingfile);
    return vec;
}

