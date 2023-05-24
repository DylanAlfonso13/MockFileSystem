#pragma once

#include "TextFile.h"
#include "ImageFile.h"
#include "AbstractFile.h"


using namespace std;

class AbstractFileVisitor {
public:
    virtual void visit_text(TextFile*) = 0;
    virtual void visit_image(ImageFile*) = 0;
};