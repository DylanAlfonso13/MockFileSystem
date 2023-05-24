#include "../include/mockos/CatDsParsingStrategy.h"
#include <sstream>
using namespace std;

vector<string> CatDsParsingStrategy::parse(std::string input) {
    vector<string> parsedInput;
    string first;
    istringstream iss(input);
    iss >> first;
    //Entire input is used for the case if they want to -a, while first is used for the DS command.
    parsedInput.push_back(input);
    parsedInput.push_back(first);
    return parsedInput;
}
