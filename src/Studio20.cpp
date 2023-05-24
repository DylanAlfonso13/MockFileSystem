#include "../include/mockos/TextFile.h"
#include "../include/mockos/PasswordProxy.h"
#include "../include/mockos/BasicDisplayVisitor.h"
#include <iostream>
using namespace std;

int main() {
	AbstractFile* text = new TextFile("text");
	PasswordProxy* password_protected = new PasswordProxy(text, "password");
	
	//Testing writing
	vector<char> textContents = { 'h', 'a', 'b', 'c' };
	int write_result = password_protected->write(textContents);
	if (write_result == 0) {
		cout << "File write success" << endl;
	}
	else {
		cout << "File write failure" << endl;
	}

	//testing read
	vector<char> read_result = password_protected->read();
	if (read_result.empty()) {
		cout << "Incorrect" << endl;
	}

	//metadata
	BasicDisplayVisitor visitor;
	password_protected->accept(&visitor);

	delete password_protected;
	return 0;
}