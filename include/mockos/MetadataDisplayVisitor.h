#pragma once

#include "AbstractFileVisitor.h"

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_text(TextFile*) override;
	virtual void visit_image(ImageFile*) override;
private:
	int WIDTH = 20;
};