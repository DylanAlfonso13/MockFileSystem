#pragma once
#include "AbstractParsingStrategy.h"
#include <string>
#include <vector>

class CatDsParsingStrategy : public AbstractParsingStrategy{
public:
    virtual vector<string> parse(string input) override;
};