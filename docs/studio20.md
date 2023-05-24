# Studio 20
1)Team: Stacey Acheampong, Dylan Alfonso and Nina Latimore

2.) It's necessary to delete the pointer to the actual file in the passwordproxy destructor in order to prevent memory leaks.

4.) int main() {
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
	Here's the implementation, First we test writing, which has return messages for certain scenarios
	Also, the read has an incorrect message as well.  For metadata / reading, if the password is correct, 
	it returns the data in the file, otherwise nothing is returned.

5.) no failed tests!