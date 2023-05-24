#include "../../include/mockos/TextFile.h"
#include "../../include/mockos/AbstractFileVisitor.h"
#include <string>
#include <iostream>

using namespace std;

TextFile::TextFile(string name) {
	fileName = name;
}

unsigned int TextFile::getSize() {
	return contents.size();
}

string TextFile::getName() {
	return fileName;
}

int TextFile::write(vector<char> passedContents) {
	contents = passedContents;
	return SUCCESS;
}

int TextFile::append(vector<char> addContents) {
	for (int i = 0; i < addContents.size(); i++) {
		contents.push_back(addContents[i]);
	}
	return SUCCESS;
}

vector<char> TextFile::read() {
	return contents;
}

void TextFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_text(this);
}

AbstractFile* TextFile::clone(string newname) {
	string temp = fileName;
	fileName = newname;
	AbstractFile* copy = new TextFile(*this);
	fileName = temp;
	return copy;
}