#include "../../include/mockos/ImageFile.h"
#include "../../include/mockos/AbstractFileVisitor.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;


ImageFile::ImageFile(string name) {
    fileName = name;
    size = 0;
}

unsigned int ImageFile::getSize() {
    return contents.size();
}

string ImageFile::getName() {
    return fileName;
}

int ImageFile::write(vector<char> newPic) {

    int inputSize = newPic.back() - '0';
    if (inputSize * inputSize + 1 != newPic.size()) {
        contents.clear();
        size = 0;
        return SIZENOTEQUAL;
    }

    newPic.pop_back();

    for (int i = 0; i < inputSize * inputSize; i++) {
        char pix = newPic[i];
        if (pix != 'X' && pix != ' ') {
            contents.clear();
            size = 0;
            return INCORRECTPIXEL;
        }
    }
    contents = newPic;
    size = inputSize;
    return SUCCESS;
}

int ImageFile::append(vector<char>) {
    return APPENDNOTSUPPORTED; //Doesn't support append
}



vector<char> ImageFile::read() {
    return contents;
}


void ImageFile::accept(AbstractFileVisitor* visitor) {
    visitor->visit_image(this);
}

AbstractFile* ImageFile::clone(string newname) {
    string temp = fileName;
    fileName = newname;
    AbstractFile* copy = new ImageFile(*this);
    fileName = temp;
    return copy;
}

