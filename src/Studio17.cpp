#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFile.h"
#include "../include/mockos/ImageFile.h"
#include <iostream>
using namespace std;

int main() {
	vector<char> contents = {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3'};
	AbstractFile* hi = new ImageFile("Hi");
	cout << hi->getName() << endl;
	hi->write(contents);
	hi->append(contents);
	hi->read();
}