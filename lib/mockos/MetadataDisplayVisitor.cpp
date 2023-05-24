#include "../../include/mockos/MetadataDisplayVisitor.h"
#include "../../include/mockos/AbstractFile.h"
#include "../../include/mockos/TextFile.h"
#include "../../include/mockos/ImageFile.h"
#include <iostream>
#include <iomanip>
using namespace std;

void MetadataDisplayVisitor::visit_text(TextFile* file) {
    cout << std::setw(WIDTH) << left << file->getName() << setw(WIDTH) << "text" << setw(WIDTH) << file->getSize() << endl;
}

void MetadataDisplayVisitor::visit_image(ImageFile* file) {
    cout << std::setw(WIDTH) << left << file->getName() << setw(WIDTH) << "image" << setw(WIDTH) << file->getSize() << endl;
}