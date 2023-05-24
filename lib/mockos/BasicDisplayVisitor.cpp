#include "../../include/mockos/BasicDisplayVisitor.h"
#include <iostream>

using namespace std;

void BasicDisplayVisitor::visit_text(TextFile* file) {
    vector<char> contents = file->read();
    for (int i = 0; i < contents.size(); i++) {
        cout << contents[i];
    }
    cout << endl;
}

void BasicDisplayVisitor::visit_image(ImageFile* file) {
    vector<char> contents = file->read();
    int size = sqrt(contents.size());
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int formula2 = (i * size) + j;
            cout << contents[formula2];
        }
        cout << '\n';
    }
}