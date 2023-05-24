#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFile.h"
#include "../include/mockos/ImageFile.h"
#include "../include/mockos/BasicDisplayVisitor.h"
#include <iostream>
using namespace std;

int main() {

    vector<char> contents = {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3'};
    vector<char> overWriteTest = { 'o' };
    AbstractFile *hi = new ImageFile("hi");
    //cout << hi->getName() << endl;
    hi->write(contents);
    hi->write(contents);
    hi->append(contents);
    hi->read();


    hi->write(overWriteTest);
    hi->read();
    cout << hi->getSize() << endl;

    //4
    AbstractFile* text = new TextFile("text");
    AbstractFile * image = new ImageFile("Image");
    vector<char> textContents = { 'h', 'a', 'b', 'c' };
    image->write(contents);
    text->write(textContents);
    BasicDisplayVisitor visitor;
    text->accept(&visitor);
    text->accept(&visitor);


}