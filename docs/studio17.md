# Studio 17
1.) Dylan Alfonso, Stacey Acheampong, Nina Latimore

2.) These are the tests we ran
	int main() {
		vector<char> contents = {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3'};
		AbstractFile* hi = new ImageFile("Hi");
		cout << hi->getName() << endl;
		hi->write(contents);
		hi->append(contents);
		hi->read();
	}

	This was the output
	Hi
	X   X
	  X
	X   X

	Looks good!

3.) It's useful because all of the other classes can just inherit from this
	interface

4.) We discussed that we would need to add code in the header file to support multiple different
	file types.
