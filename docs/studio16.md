# Studio 16

1.) Dylan Alfonso, Stacey Acheampong, Nina Latimore

2.a) In order to declare an interface in C++, you can make a class that contains
	a virtual void function that takes in a reference to an ostream, and then declare separate
	classes that inherit that one to print the interface.

3.a) This would be an example of interface inheritance

3.b) Private, since they are member variables

4.) I ran all of the functions in this test case and it worked as I expected it too, I made 
	comments with how I expected it to print and it did what I expected.

5.) Here's the code: int main() {
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
	It worked as expected! We just changedd line 3, instead of using TextFile in the declaration, we used AbstractFile.