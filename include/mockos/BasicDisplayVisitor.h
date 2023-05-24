#pragma once
#include "AbstractFileVisitor.h"

using namespace std;

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
    virtual void visit_text(TextFile*) override;
    virtual void visit_image(ImageFile*) override;
};