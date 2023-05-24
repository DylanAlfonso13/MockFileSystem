#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/AbstractFileFactory.h"
#include <iostream>
using namespace std;



int main() {
	AbstractFileSystem* fileSystem = new SimpleFileSystem();
	AbstractFileFactory* fileFactory = new SimpleFileFactory();
	AbstractFile* image = fileFactory->createFile("image.img");
	AbstractFile* text = fileFactory->createFile("text.txt");
	vector<char> contents = { 'h', 'a', 'b', 'c' };
	text->write(contents);
	vector<char> imageContents = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' };
	image->write(imageContents);
	fileSystem->addFile("image.img", image);
	fileSystem->addFile("text.txt", text);
	cout << fileSystem->openFile("image.img") << endl;
	cout << fileSystem->openFile("text.txt") << endl;
	text->read();
	image->read();


}