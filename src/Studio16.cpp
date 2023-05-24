#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFile.h"
#include <iostream>
using namespace std;

int main() {
	vector<char> contents = { 'h', 'a', 'b', 'c' };
	vector<char> overWriteTest = { 'o' };
	AbstractFile* hi = new TextFile("Hi");
	cout << hi->getName() << endl;
	hi->write(contents);
	hi->append(contents);
	hi->read();
	cout << hi->getSize() << endl;
	//Expecting contents twice on this read, 8 size
	hi->write(overWriteTest);
	hi->read();
	cout << hi->getSize() << endl;
	//expecting just o to print, 1 size
	hi->getName();
	return 0;
}