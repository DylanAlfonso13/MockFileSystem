#pragma once

#include <vector>
#include <string>
using namespace std;

class AbstractParsingStrategy{
public:
    virtual ~AbstractParsingStrategy() = default;
    virtual vector<string> parse(string input) = 0;
};